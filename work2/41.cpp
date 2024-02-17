#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <typename T, typename Graph>
pair<vector<T>, vector<int>> dijkstra(const Graph &G, int s) {
    int N = G.size();
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(0, s);
    vector<T> dis(N, inf<T>);
    dis[s] = 0;
    vector<int> route(N, -1);
    while (!q.empty()) {
        auto [dv, v] = q.top();
        q.pop();
        if (dv > dis[v]) continue;
        for (auto [cost, nv] : G[v]) {
            T c = dv + cost;
            if (dis[nv] > c) {
                dis[nv] = c;
                q.emplace(dis[nv], nv);
                route[nv] = v;
            }
        }
    }
    return {dis, route};
}
struct UnionFind {
  private:
    int N;
    vector<int> dat;
    void build() {
        dat.assign(N, -1);
    }

  public:
    UnionFind(int n = 0) : N(n) {
        build();
    }
    void reset() {
        build();
    }
    int operator[](int x) {
        while (dat[x] >= 0) {
            int pp = dat[dat[x]];
            if (pp < 0) return dat[x];
            x = dat[x] = pp;
        }
        return x;
    }
    long long size(int x) {
        x = (*this)[x];
        return -dat[x];
    }
    bool unite(int x, int y) {
        x = (*this)[x], y = (*this)[y];
        if (x == y) return false;
        if (-dat[x] < -dat[y]) swap(x, y);
        dat[x] += dat[y], dat[y] = x;
        return true;
    }
    vector<vector<int>> groups() {
        vector<vector<int>> ret(N);
        for (int i = 0; i < N; i++) {
            ret[(*this)[i]].emplace_back(i);
        }
        ret.erase(remove_if(begin(ret), end(ret),
                            [&](const vector<int> &v) { return v.empty(); }),
                  end(ret));
        return ret;
    }
};
// TODO binary_search
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
template <typename T> struct Mmin {
    using value_type = T;
    static constexpr T e = inf<T>;
    static constexpr T op(const T &x, const T &y) noexcept {
        return min(x, y);
    }
};
// TODO lazy update
// TODO binary_search
template <typename Monoid> struct FwkTree {
    using M = Monoid;
    using T = typename M::value_type;

  private:
    int N;
    vector<T> node;
    T tot;
    void init() {
        node.assign(N + 1, M::e);
        tot = M::e;
    }
    void bind(T &x, const T &y) {
        x = M::op(x, y);
    }

  public:
    FwkTree(int n) : N(n) {
        init();
    }
    FwkTree(const vector<T> &a) : N(a.size()) {
        init();
        for (int i = 1; i <= N; i++) {
            bind(tot, a[i - 1]);
            bind(node[i], a[i - 1]);
            int f = i + (i & -i);
            if (f <= N) bind(node[f], node[i]);
        }
    }
    void act(int i, const T &x) {
        bind(tot, x);
        for (++i; i <= N; i += i & -i) bind(node[i], x);
    }
    T get(int r) {
        T ans = M::e;
        for (++r; r; r -= r & -r) bind(ans, node[r]);
        return ans;
    }
    T top() {
        return tot;
    }
};
// TODO binary_search
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
    vector<T> getall() {
        for (int i = 1; i < size; i++) propagate(i);
        return {node.begin() + size, node.begin() + size + N};
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
template <typename T> struct Madd {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T op(const T &x, const T &y) noexcept {
        return x + y;
    }
};
template <typename T> struct MAminadd {
    using M_m = Mmin<T>;
    using M_a = Madd<T>;
    using M = typename M_m::value_type;
    using A = typename M_a::value_type;
    static constexpr M act(const M &m, const A &a, const long long &size) {
        (void)size; // unused
        return m == inf<T> ? m : m + a;
    }
};
template <class T> struct StarrySkyTree {
  private:
    int N, log, sz;
    vector<T> node;
    void init() {
        log = 1;
        while ((1 << log) < N) ++log;
        sz = 1 << log;
        node.assign(sz << 1, -inf<T>);
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
    T sum(int i) {
        T ans = node[i];
        while (i >>= 1) ans += node[i];
        return ans;
    }

  public:
    StarrySkyTree(int n) : N(n) {
        init();
    }
    StarrySkyTree(const vector<T> &a) : N(a.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + sz] = a[i];
        for (int i = sz - 1; i >= 1; --i) node[i] = _star(i);
    }
    T operator[](int i) {
        return sum(i + sz);
    }
    T get(int l, int r) {
        T ans = -inf<T>;
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = max(ans, sum(l++));
            if (r & 1) ans = max(ans, sum(--r));
        }
        return ans;
    }
    T top() {
        return node[1];
    }
    void apply(int l, int r, const T &x) {
        for (int ll = (l += sz), rr = (r += sz); ll < rr; ll >>= 1, rr >>= 1) {
            if (ll & 1) node[ll++] += x;
            if (rr & 1) node[--rr] += x;
        }
        l >>= __builtin_ctz(l);
        r >>= __builtin_ctz(r);
        while (l >>= 1) star(l);
        while (r >>= 1) star(r);
    }
};
namespace FFT {
using real = double;
struct C {
    real x, y;
    C() : x(0), y(0){};
    C(real x, real y) : x(x), y(y){};
    inline C operator+(const C &c) const {
        return C(x + c.x, y + c.y);
    }
    inline C operator-(const C &c) const {
        return C(x - c.x, y - c.y);
    }
    inline C operator*(const C &c) const {
        return C(x * c.x - y * c.y, x * c.y + y * c.x);
    }
    inline C conj() const {
        return C(x, -y);
    }
};
const real PI = acosl(-1);
int base = 1;
vector<C> rts = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};
void ensure_base(int nbase) {
    if (nbase <= base) return;
    rev.resize(1 << nbase);
    rts.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    while (base < nbase) {
        real angle = PI * 2.0 / (1 << (base + 1));
        for (int i = 1 << (base - 1); i < (1 << base); i++) {
            rts[i << 1] = rts[i];
            real angle_i = angle * (2 * i + 1 - (1 << base));
            rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
        }
        ++base;
    }
}
void fft(vector<C> &a, int n) {
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
        if (i < (rev[i] >> shift)) swap(a[i], a[rev[i] >> shift]);
    }
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                C z = a[i + j + k] * rts[j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] = a[i + j] + z;
            }
        }
    }
}
} // namespace FFT
template <typename R>
vector<long long> convolution_fft(const vector<R> &a, const vector<R> &b) {
    using C = FFT::C;
    int need = (int)a.size() + (int)b.size() - 1, nbase = 1;
    while ((1 << nbase) < need) ++nbase;
    FFT::ensure_base(nbase);
    int sz = 1 << nbase;
    vector<C> fa(sz);
    for (int i = 0; i < sz; i++) {
        double x = i < (int)a.size() ? a[i] : 0;
        double y = i < (int)b.size() ? b[i] : 0;
        fa[i] = C(x, y);
    }
    FFT::fft(fa, sz);
    C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
    for (int i = 0; i <= (sz >> 1); i++) {
        int j = (sz - i) & (sz - 1);
        C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
        fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
        fa[i] = z;
    }
    for (int i = 0; i < (sz >> 1); i++) {
        C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
        C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * FFT::rts[(sz >> 1) + i];
        fa[i] = A0 + A1 * s;
    }
    FFT::fft(fa, sz >> 1);
    vector<long long> ret(need);
    for (int i = 0; i < need; i++) {
        ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
    }
    return ret;
}
const long long MOD = 998244353;
template <typename T> T modpow(T a, T n) {
    T ans = 1;
    while (n > 0) {
        if (n & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        n >>= 1ll;
    }
    return ans;
}
long long modinv(long long a) {
    return modpow(a, MOD - 2);
}
vector<long long> mf;
long long modfact(int x) {
    if ((int)mf.size() > x) return mf[x];
    if (mf.empty()) mf.push_back(1);
    for (int i = mf.size(); i <= x; i++) mf.push_back(mf.back() * i % MOD);
    return mf[x];
}
long long mod_combination(int n, int k) {
    return modfact(n) * modinv(modfact(k)) % MOD * modinv(modfact(n - k)) % MOD;
}
template <typename T> T nCk(int n, int k) {
    if (k < 0 || n < k) return 0;
    T ret = 1;
    for (T i = 1; i <= k; ++i) {
        ret *= n--;
        ret /= i;
    }
    return ret;
}
const int MAX = 3e5;
long long fac[MAX], finv[MAX], inv[MAX];
void extEuclidInv() {
    fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long nCk(int n, int k) {
    if (n < k or n < 0 or k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
template <typename T> T digitsum(T a, int N = 10) {
    T ans = 0;
    while (a != 0) {
        ans += a % N;
        a /= N;
    }
    return ans;
}
template <typename T> vector<T> divisors(T a) {
    vector<T> ans;
    for (T i = 1; i * i <= a; i++) {
        if (a % i != 0) continue;
        ans.push_back(i);
        if (a / i != i) ans.push_back(a / i);
    }
    return ans;
}
template <typename T> map<T, int> p_fact(T N) {
    map<T, int> P;
    for (T i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            P[i]++;
            N /= i;
        }
    }
    if (N > 1) P[N]++;
    return P;
}
template <typename T> bool is_p(T N) {
    if (N == 2) return true;
    if (N == 1 or N % 2 == 0) return false;
    for (T i = 3; i * i <= N; i += 2) {
        if (N % i == 0) return false;
    }
    return true;
}
template <typename T> vector<bool> eratosthenes(T N) {
    vector<bool> is_P(N + 1, true);
    is_P[0] = is_P[1] = false;
    for (T i = 2; i * i <= N; i++) {
        if (!is_P[i]) continue;
        for (T j = i * i; j <= N; j += i) is_P[j] = false;
    }
    return is_P;
}
int main() {
    int N, W;
    cin >> N >> W;
    UnionFind uf(N);
    LazySegTree<MAminadd<int>> lseg(N);
    SegTree<Mmin<long long>> seg(N);
    FwkTree<Mmin<int>> fwk(N);
    StarrySkyTree<int> sst(N);
    vector<int> w(N), c(N);
    auto cal = [&](const int &a) -> void {
        cout << 1 << endl;
        if (i) cout << " ";
        cout << A[i];
        cout << endl;
    };
    map<long long, long long> mp;
    auto func = [&](auto f, long long a) -> long long {
        if (a == 1) return 0;
        if (mp.count(a)) return mp[a];
        mp[a] = f(f, a / 2) + a + f(f, (a + 1) / 2);
        return mp[a];
    };
    do {
        //
    } while (next_permutation(A.begin(), A.end()));
    for (long long bit = 0; bit < (1ll << N); bit++) {
        long long tmp = 0;
        for (int k = 0; k < N; k++) {
            if (bit & (1ll << k)) {
                tmp |= A[k];
            }
        }
    }
    for (int bit = 0; bit < (1 << H); bit++) {
        for (int bit2 = 0; bit2 < (1 << W); bit2++) {
            vector<int> h, w;
            for (int k = 0; k < H; k++) {
                if (bit & (1 << k)) h.push_back(k);
            }
            for (int k = 0; k < W; k++) {
                if (bit2 & (1 << k)) w.push_back(k);
            }
        }
    }
    for (;;) {
    }
    for (long long i = 0; i * i <= N; i++) {
    }
    for (auto &v : A) {
    }
    fir(long long i = N; i > 0; i = (i - 1) & N) {
        cout << N - i << endl;
    }
    cout << N << endl;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
        }
    }
    set<int> st;
    auto itr = st.lower_bound(A);
    if (itr == st.begin()) continue;
    int a = *--itr;
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> c[i];
    }
    auto a = convolution_fft(w, c);
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + w[i];
    }
    auto zip = []<class T>(vector<T> a) -> pair<vector<T>, vector<T>> {
        vector<T> c = a;
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        for (auto &v : a) v = lower_bound(c.begin(), c.end(), v) - c.begin();
        return {a, c};
    };
    auto [comp, cvt] = zip(w);
    int ans = 0;
    FwkTree<Madd<int>> fwk2(cvt.size());
    for (int i = 0; i < N; i++) {
        ans += fwk2.top() - fwk2.get(comp[i]);
        fwk2.act(comp[i], 1);
    }
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i + 1][j] = dp[i][j];
            if (w[i] <= j) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w[i]] + c[i]);
            }
            if (dp[i][j]) {
                dp[i + 1][j] = true;
                dp[i + 1][min(j + w[i], W)] = true;
            }
        }
    }
    cout << dp[N][W] << endl;
    queue<pair<int, int>> q;
    q.push({sy, sx});
    vector<vector<int>> dis(H, vector<int>(W, -1));
    dis[sy][sx] = 0;
    while (!q.empty()) {
        int py = q.front().first;
        int px = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int y = py + dy[i];
            int x = px + dx[i];
            if (y < 0 or x < 0 or H <= y or W <= x) continue;
            if (dis[y][x] == -1 and cango(G[y][x])) {
                dis[y][x] = dis[py][px] + 1;
                q.push({y, x});
            }
        }
    }
    queue<int> q;
    q.push(0);
    vector<int> dis(N, -1);
    dis[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int nv : G[v]) {
            if (dis[nv] == -1) {
                dis[nv] = dis[v] + 1;
                q.push(nv);
            }
        }
    }
}
