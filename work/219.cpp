#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <typename T> struct Mmin {
    using value_type = T;
    static constexpr T e = inf<T>;
    static constexpr T op(const T &x, const T &y) noexcept {
        return min(x, y);
    }
};
template <typename T> struct Mgcd {
    using value_type = T;
    static constexpr T e = 1;
    static constexpr T op(const T &x, const T &y) noexcept {
        return gcd(x, y);
    }
};
template <typename T> struct Madd {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T op(const T &x, const T &y) noexcept {
        return x + y;
    }
};
template <typename T> struct Mprod {
    using value_type = T;
    static constexpr T e = 1;
    static constexpr T op(const T &x, const T &y) noexcept {
        return x * y;
    }
};
template <typename T> struct MAadd {
    using M_m = Madd<T>;
    using M_a = Madd<T>;
    using M = typename M_m::value_type;
    using A = typename M_a::value_type;
    static constexpr M act(const M &m, const A &a, const long long &size) {
        return m + a * T(size);
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
        for (int i = size - 1; i > 0; --i) update(i);
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
        for (int i = size - 1; i > 0; --i) update(i);
    }
    T operator[](int p) {
        p += size;
        for (int i = log; i > 0; --i) propagate(p >> i);
        return node[p];
    }
    void set(int p, const T &x) {
        p += size;
        for (int i = log; i > 0; --i) propagate(p >> i);
        node[p] = x;
        for (int i = 1; i <= log; ++i) update(p >> i);
    }
    void act(int p, const T &x) {
        p += size;
        for (int i = log; i > 0; --i) propagate(p >> i);
        node[p] = M::op(node[p], x);
        for (int i = 1; i <= log; ++i) update(p >> i);
    }
    T get(int l, int r) {
        if (l == r) return M::e;
        l += size, r += size;
        for (int i = log; i > 0; --i) {
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
        for (int i = log; i > 0; --i) {
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
            if (((l >> i) << i) != l) propagate(l >> i);
            if (((r >> i) << i) != r) propagate((r - 1) >> i);
        }
    }
};
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
            bind(node[i], a[i - 1]);
            int f = i + (i & -i);
            if (f <= N) bind(node[f], node[i]);
        }
    }
    void act(int i, const T &x) {
        tot += x;
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
int main() {
    const double PI = acos(-1);
    const vector<int> dx = {0, 1, 0, -1};
    const vector<int> dy = {1, 0, -1, 0};
    const int INF = 1001001001;
    const long long MOD = 998244353;
    auto islow = [](char c) -> bool { return islower(c) != 0; };
    auto isupp = [](char c) -> bool { return isupper(c) != 0; };
    auto divCeil = []<class T>(T a, T b) -> T {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    auto divFloor = []<class T>(T a, T b) -> T {
        return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
    };
    auto split = [](string s, char c) -> vector<string> {
        vector<string> S;
        string t;
        for (char v : s) {
            if (v == c) {
                if (!t.empty()) S.push_back(t);
                t.clear();
            } else {
                t += v;
            }
        }
        if (!t.empty()) S.push_back(t);
        return S;
    };
    auto mod_pow = [&]<class T>(T a, T n) -> T {
        T ans = 1;
        while (n > 0) {
            if (n & 1) ans = ans * a % MOD;
            a = a * a % MOD;
            n >>= 1ll;
        }
        return ans;
    };
    auto is_p = []<class T>(T num) -> bool {
        if (num == 2) return true;
        if (num < 2 || num % 2 == 0) return false;
        double sqrtNum = sqrt(num);
        for (T i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    };
    auto factorial = []<class T>(T N) -> T {
        T ans = 1;
        while (N > 0) ans *= N--;
        return ans;
    };
    auto p_fact = []<class T>(T N) -> map<T, int> {
        map<T, int> P;
        for (T i = 2; i * i <= N; i++) {
            while (N % i == 0) {
                P[i]++;
                N /= i;
            }
        }
        if (N > 1) P[N]++;
        return P;
    };
    auto digitsum = []<class T>(T a, int N = 10) -> T {
        T ans = 0;
        while (a != 0) {
            ans += a % N;
            a /= N;
        }
        return ans;
    };
    auto divisors = []<class T>(T a) -> vector<T> {
        vector<T> ans;
        for (int i = 1; i * i <= a; i++) {
            if (a % i != 0) continue;
            ans.push_back(i);
            if (a / i != i) ans.push_back(a / i);
        }
        return ans;
    };
    vector<long long> mf;
    auto modfact = [&](int x) -> long long {
        if ((int)mf.size() > x) return mf[x];
        if (mf.empty()) mf.push_back(1);
        for (int i = mf.size(); i <= x; i++) mf.push_back(mf.back() * i % MOD);
        return mf[x];
    };
    auto eratosthenes = []<class T>(T N) -> vector<bool> {
        vector<bool> is_P(N + 1, true);
        is_P[0] = is_P[1] = false;
        for (T i = 2; i * i <= N; i++) {
            if (!is_P[i]) continue;
            for (T j = i * i; j <= N; j += i) is_P[j] = false;
        }
        return is_P;
    };
    auto modinv_fermat = [&](long long a) -> long long {
        return mod_pow(a, MOD - 2);
    };
    auto mod_combination = [&](int n, int k) -> long long {
        return modfact(n) * modinv_fermat(modfact(k)) % MOD *
               modinv_fermat(modfact(n - k)) % MOD;
    };
    const int MAX = 3e5;
    long long fac[MAX], finv[MAX], inv[MAX];
    auto Extended_Euclid_inverse_calc = [&]() -> void {
        fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
        for (int i = 2; i < MAX; i++) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    };
    Extended_Euclid_inverse_calc();
    auto nCk = [&](int n, int k) -> long long {
        if (n < k or n < 0 or k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    };
    auto compress = []<class T>(vector<T> &a) -> int {
        vector<T> c = a;
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        for (auto &v : a) v = lower_bound(c.begin(), c.end(), v) - c.begin();
        return c.size();
    };
    auto cango = [](const char &a) -> bool {
        string white = ".SG";
        return white.find(a) != string::npos;
    };
    FwkTree<Madd<int>> fwk(compress(mf));
    SegTree<Mmin<int>> seg(compress(mf));
    LazySegTree<MAminadd<int>> lseg(10);
}
