#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
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
template <typename T> T factorial(T N) {
    T ans = 1;
    while (N > 0) ans *= N--;
    return ans;
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
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <typename T> struct Madd {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T op(const T &x, const T &y) noexcept {
        return x + y;
    }
};
template <typename T> struct Mgcd {
    using value_type = T;
    static constexpr T e = 1;
    static constexpr T op(const T &x, const T &y) noexcept {
        return gcd(x, y);
    }
};
template <typename T> struct Mmax {
    using value_type = T;
    static constexpr T e = -inf<T>;
    static constexpr T op(const T &x, const T &y) noexcept {
        return max(x, y);
    }
};
template <typename T> struct Mmin {
    using value_type = T;
    static constexpr T e = inf<T>;
    static constexpr T op(const T &x, const T &y) noexcept {
        return min(x, y);
    }
};
template <typename T> struct Mmul {
    using value_type = T;
    static constexpr T e = 1;
    static constexpr T op(const T &x, const T &y) noexcept {
        return x * y;
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
template <typename T> struct MAsumadd {
    using M_m = Madd<T>;
    using M_a = Madd<T>;
    using M = typename M_m::value_type;
    using A = typename M_a::value_type;
    static constexpr M act(const M &m, const A &a, const long long &size) {
        return m + a * T(size);
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
auto zip = []<class T>(vector<T> a) -> pair<vector<T>, vector<T>> {
    vector<T> c = a;
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for (auto &v : a) v = lower_bound(c.begin(), c.end(), v) - c.begin();
    return {a, c};
};
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
struct DateTime {
    int year, month, day;
    DateTime() : year(0), month(0), day(0){};
    DateTime(int m) : year(0), month(m), day(0){};
    DateTime(int y, int m, int d) : year(y), month(m), day(d){};
    static constexpr int month_days[13] = {0,  31, 28, 31, 30, 31, 30,
                                           31, 31, 30, 31, 30, 31};
    // 月の日数
    int dpm(int m) {
        if (is_leap_year(year) and m == 2) return 29;
        return month_days[m];
    }
    // 1年1月1日が 0 となるように変換
    int to_int() {
        int y = (month <= 2 ? year - 1 : year);
        int m = (month <= 2 ? month + 12 : month);
        int d = day;
        return 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d -
               429;
    }
    // to_int() の逆関数
    static DateTime from_int(int x) {
        int y = x * 400 / 146097 + 1;
        int d = x - DateTime(y, 1, 1).to_int();
        int m = 1;
        while (d >= 28) {
            int k = month_days[m] + (m == 2 && is_leap_year(y) ? 1 : 0);
            if (d < k) break;
            ++m;
            d -= k;
        }
        if (m == 13) {
            ++y;
            m = 1;
        }
        ++d;
        return DateTime(y, m, d);
    }
    // 日曜日が 0 として、曜日を [0, 7) で返す
    int weekday() {
        return (to_int() + 1) % 7;
    }
    DateTime &operator++() {
        ++day;
        int lim = month_days[month];
        if (is_leap_year(year) && month == 2) lim = 29;
        if (day <= lim) return (*this);
        day = 1;
        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
        return (*this);
    }
    DateTime operator++(int) {
        DateTime tmp = *this;
        ++*this;
        return tmp;
    }
    bool operator==(DateTime const &rhs) const {
        return to_tuple() == rhs.to_tuple();
    }
    bool operator!=(DateTime const &rhs) const {
        return to_tuple() != rhs.to_tuple();
    }
    bool operator<(DateTime const &rhs) const {
        return to_tuple() < rhs.to_tuple();
    }
    bool operator<=(DateTime const &rhs) const {
        return to_tuple() <= rhs.to_tuple();
    }
    bool operator>(DateTime const &rhs) const {
        return to_tuple() > rhs.to_tuple();
    }
    bool operator>=(DateTime const &rhs) const {
        return to_tuple() >= rhs.to_tuple();
    }
    // yyyy[sep]mm[sep]dd
    string to_string(string sep = "-") {
        string y = std::to_string(year);
        string m = std::to_string(month);
        string d = std::to_string(day);
        while ((int)y.size() < 4) y = "0" + y;
        while ((int)m.size() < 2) m = "0" + m;
        while ((int)d.size() < 2) d = "0" + d;
        return y + sep + m + sep + d;
    }
    tuple<int, int, int> to_tuple() const {
        return {year, month, day};
    }
    static bool is_leap_year(int y) {
        if (y % 400 == 0) return true;
        return (y % 4 == 0 && y % 100 != 0);
    }
    static bool is_valid_date(int y, int m, int d) {
        if (!(1 <= m && m <= 12)) return 0;
        int mx = month_days[m];
        if (m == 2 && is_leap_year(y)) ++mx;
        return (1 <= d && d <= mx);
    }
};
int main() {
    const double PI = acos(-1);
    const vector<int> dx = {0, 1, 0, -1};
    const vector<int> dy = {1, 0, -1, 0};
}
