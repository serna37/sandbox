#include <bits/stdc++.h>
using namespace std;
template <typename T> struct Madd {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T op(const T &x, const T &y) noexcept {
        return x + y;
    }
};
template <class Monoid> struct SegTree {
    using M = Monoid;
    using T = typename M::value_type;

  private:
    int N, log, size;
    vector<T> node;
    void init() {
        log = 1;
        while ((1 << log) < N) ++log;
        size = 1 << log;
        node.assign(size << 1, M::e);
    }
    void update(const int &i) {
        node[i] = M::op(node[i << 1 | 0], node[i << 1 | 1]);
    }

  public:
    SegTree(int n) : N(n) {
        init();
    }
    SegTree(const vector<T> &a) : N(a.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + size] = a[i];
        for (int i = size - 1; i >= 1; --i) update(i);
    }
    T operator[](int i) {
        return node[i + size];
    }
    void set(int i, const T &x) {
        node[i += size] = x;
        while (i >>= 1) update(i);
    }
    void act(int i, const T &x) {
        i += size;
        node[i] = M::op(node[i], x);
        while (i >>= 1) update(i);
    }
    T get(int l, int r) {
        T L = M::e, R = M::e;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = M::op(L, node[l++]);
            if (r & 1) R = M::op(node[--r], R);
        }
        return M::op(L, R);
    }
    T top() {
        return node[1];
    }
};
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <class T> struct StarrySkyTree {
  private:
    int N, log, size;
    vector<T> node;
    void init() {
        log = 1;
        while ((1 << log) < N + 1) ++log;
        size = 1 << log;
        node.assign(size << 1, -inf<T>);
    }
    T _star(int i) {
        T mx = max(node[i << 1 | 0], node[i << 1 | 1]);
        node[i << 1 | 0] -= mx;
        node[i << 1 | 1] -= mx;
        return mx;
    }
    void star(int i) {
        node[i] += _star(i);
    }

  public:
    StarrySkyTree(int n) : N(n) {
        init();
    }
    StarrySkyTree(const vector<T> &a) : N(a.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + size] = a[i];
        for (int i = size - 1; i >= 1; --i) node[i] = _star(i);
    }
    T operator[](int i) {
        T ans = node[i += size];
        while (i >>= 1) ans += node[i];
        return ans;
    }
    T get(int l, int r) {
        if (l == 0 and r == N) return node[1];
        stack<int> L, R;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L.push(l++);
            if (r & 1) R.push(--r);
        }
        vector<T> leaf;
        T commonL = node[1];
        for (int i = l - 1; i > 1; i >>= 1) commonL += node[i];
        for (int i = l - 1; !L.empty();) {
            i = (i << 1 | 1);
            if (i == L.top()) {
                leaf.push_back(commonL + node[i--]);
                L.pop();
            }
            commonL += node[i];
        }
        T commonR = node[1];
        for (int i = r; i > 1; i >>= 1) commonR += node[i];
        for (int i = r; !R.empty();) {
            i = (i << 1 | 0);
            if (i == R.top()) {
                leaf.push_back(commonR + node[i++]);
                R.pop();
            }
            commonR += node[i];
        }
        return *max_element(leaf.begin(), leaf.end());
    }
    T top() {
        return node[1];
    }
    void apply(int l, int r, const T &x) {
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) node[l++] += x;
            if (r & 1) node[--r] += x;
            if ((l - 1) > 1) star((l - 1) >> 1);
            if (r < (size << 1)) star(r >> 1);
        }
        for (int i = l - 1; i > 1; i >>= 1) star(i);
        for (int i = r; i >= 1; i >>= 1) star(i);
    }
};
template <typename MonoidAct> struct LazySegTree {
    using M = typename MonoidAct::M_m;
    using A = typename MonoidAct::M_a;
    using T = typename M::value_type;
    using U = typename A::value_type;

  private:
    int N, log, size;
    vector<T> node;
    vector<U> lazy;
    void init() {
        log = 1;
        while ((1 << log) < N) ++log;
        size = 1 << log;
        node.assign(size << 1, M::e);
        lazy.assign(size, A::e);
    }
    void update(int i) {
        node[i] = M::op(node[i << 1 | 0], node[i << 1 | 1]);
    }
    void apply_at(int k, U a) {
        int topbit = k == 0 ? -1 : 31 - __builtin_clz(k);
        long long sz = 1 << (log - topbit);
        node[k] = MonoidAct::act(node[k], a, sz);
        if (k < size) lazy[k] = A::op(lazy[k], a);
    }
    void propagate(int k) {
        if (lazy[k] == A::e) return;
        apply_at((k << 1 | 0), lazy[k]);
        apply_at((k << 1 | 1), lazy[k]);
        lazy[k] = A::e;
    }

  public:
    LazySegTree(int n) : N(n) {
        init();
    }
    LazySegTree(const vector<T> &a) : N(a.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + size] = a[i];
        for (int i = size - 1; i >= 1; --i) update(i);
    }
    T operator[](int p) {
        p += size;
        for (int i = log; i >= 1; --i) propagate(p >> i);
        return node[p];
    }
    void set(int p, const T &x) {
        p += size;
        for (int i = log; i >= 1; --i) propagate(p >> i);
        node[p] = x;
        for (int i = 1; i <= log; ++i) update(p >> i);
    }
    void act(int p, const T &x) {
        p += size;
        for (int i = log; i >= 1; --i) propagate(p >> i);
        node[p] = M::op(node[p], x);
        for (int i = 1; i <= log; ++i) update(p >> i);
    }
    T get(int l, int r) {
        if (l == r) return M::e;
        l += size, r += size;
        for (int i = log; i >= 1; --i) {
            if (((l >> i) << i) != l) propagate(l >> i);
            if (((r >> i) << i) != r) propagate((r - 1) >> i);
        }
        T L = M::e, R = M::e;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = M::op(L, node[l++]);
            if (r & 1) R = M::op(node[--r], R);
        }
        return M::op(L, R);
    }
    T top() {
        return node[1];
    }
    void apply(int l, int r, U a) {
        if (l == r) return;
        l += size, r += size;
        for (int i = log; i >= 1; --i) {
            if (((l >> i) << i) != l) propagate(l >> i);
            if (((r >> i) << i) != r) propagate((r - 1) >> i);
        }
        int l2 = l, r2 = r;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) apply_at(l++, a);
            if (r & 1) apply_at(--r, a);
        }
        l = l2, r = r2;
        for (int i = 1; i <= log; ++i) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }
};
struct UnionFind {
  private:
    int N;
    vector<int> par;

  public:
    UnionFind(int N) : N(N), par(N) {
        iota(par.begin(), par.end(), 0);
    }
    int getRoot(const int &i) {
        return par[i] == i ? i : par[i] = getRoot(par[i]);
    }
    void unite(int x, int y) {
        int rx = getRoot(x), ry = getRoot(y);
        if (rx == ry) return;
        par[rx] = ry;
    }
    bool isSameRoot(int x, int y) {
        return getRoot(x) == getRoot(y);
    }
    bool isRoot(int i) {
        return getRoot(i) == i;
    }
    int getRootCnt() {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (isRoot(i)) cnt++;
        }
        return cnt;
    }
};
int main() {
    const int INF = 1001001001;
    const double PI = acos(-1);
    const long long MOD = 998244353;
    auto mod_pow = [&]<class T>(T a, T n) -> T {
        T ans = 1;
        while (n > 0) {
            if (n & 1) ans = ans * a % MOD;
            a = a * a % MOD;
            n >>= 1ll;
        }
        return ans;
    };
    int ans = 0;
    cout << ans << endl;
}
