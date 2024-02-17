#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int INF = 1001001001;
const long long MOD = 998244353;
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};
template <typename T> struct SegTree {
  private:
    int e = 0;
    int N;
    vector<T> v;
    T c(const T &a, const T &b) {
        return a + b;
    }

  public:
    SegTree(int n) : N(n), v(n << 1, e){};
    T operator[](const int &i) {
        return v[i + N];
    }
    void build(const vector<T> &a) {
        for (int i = 0; i < N; i++) v[i + N] = a[i];
        for (int i = N - 1; i >= 0; i--) v[i] = c(v[i << 1 | 0], v[i << 1 | 1]);
    }
    void set(int i, const T &x) {
        v[i += N] = x;
        while (i >>= 1) v[i] = c(v[i << 1 | 0], v[i << 1 | 1]);
    }
    T get(int l, int r) {
        T vl = e, vr = e;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = c(vl, v[l++]);
            if (r & 1) vr = c(v[--r], vr);
        }
        return c(vl, vr);
    }
    T top() {
        return v[1];
    }
};
template <typename T> struct SegRCQ {
  private:
    int N;
    vector<unordered_map<int, int>> node;
    void bind(const int &i) {
        for (auto v : node[i << 1 | 0]) node[i][v.first] += v.second;
        for (auto v : node[i << 1 | 1]) node[i][v.first] += v.second;
    }

  public:
    SegRCQ(int n) : N(n), node(n << 1){};
    unordered_map<int, int> operator[](int i) {
        return node[i + N];
    }
    void build(const vector<T> &a) {
        for (int i = 0; i < N; i++) node[i + N][a[i]] = 1;
        for (int i = N - 1; i >= 0; i--) bind(i);
    }
    void set(int i, T x) {
        node[i += N] = x;
        while (i >>= 1) bind(i);
    }
    T get(int l, int r, int x) {
        T vl = 0, vr = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                if (node[l].count(x)) vl += node[l][x];
                l++;
            }
            if (r & 1) {
                --r;
                if (node[r].count(x)) vl += node[r][x];
            }
        }
        return vl + vr;
    }
    T top() {
        return node[1];
    }
};
template <typename T> struct FwkTree {
  private:
    int e = 0;
    int N;
    vector<T> node;
    void bind(T &a, const T &b) {
        a += b;
    }

  public:
    FwkTree(int n) : N(n), node(n + 1, e){};
    void build(const vector<T> &a) {
        for (int i = 1; i <= N; i++) {
            bind(node[i], a[i - 1]);
            int f = i + (i & -i);
            if (f <= N) bind(node[f], node[i]);
        }
    }
    void act(const int &i, const T &x) {
        for (int f = i + 1; f <= N; f += f & -f) bind(node[f], x);
    }
    T get(const int &r) {
        T ans = e;
        for (int f = r + 1; f; f -= f & -f) bind(ans, node[f]);
        return ans;
    }
};
int main() {
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
                if (!t.empty()) {
                    S.push_back(t);
                }
                t.clear();
            } else {
                t += v;
            }
        }
        if (!t.empty()) {
            S.push_back(t);
        }
        return S;
    };
    auto mod_pow = [&]<class T>(T a, T n) -> T {
        T ans = 1;
        while (n > 0) {
            if (n & 1) {
                ans = ans * a % MOD;
            }
            a = a * a % MOD;
            n >>= 1ll;
        }
        return ans;
    };
    auto is_p = []<class T>(T num) -> bool {
        if (num == 2) {
            return true;
        }
        if (num < 2 || num % 2 == 0) {
            return false;
        }
        double sqrtNum = sqrt(num);
        for (T i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    };
    auto factorial = []<class T>(T N) -> T {
        T ans = 1;
        while (N > 0) {
            ans *= N;
            N--;
        }
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
        if (N > 1) {
            P[N]++;
        }
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
            if (a % i != 0) {
                continue;
            }
            ans.push_back(i);
            if (a / i != i) {
                ans.push_back(a / i);
            }
        }
        return ans;
    };
    vector<long long> mf;
    auto modfact = [&](int x) -> long long {
        if (mf.size() > x) {
            return mf[x];
        }
        if (mf.empty()) {
            mf.push_back(1);
        }
        for (int i = mf.size(); i <= x; i++) {
            long long next = mf.back() * i % MOD;
            mf.push_back(next);
        }
        return mf[x];
    };
    auto eratosthenes = []<class T>(T N) -> vector<bool> {
        vector<bool> is_P(N + 1, true);
        is_P[0] = is_P[1] = false;
        for (T i = 2; i * i <= N; i++) {
            if (!is_P[i]) {
                continue;
            }
            for (T j = i * i; j <= N; j += i) {
                is_P[j] = false;
            }
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
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    };
    Extended_Euclid_inverse_calc();
    auto nCk = [&](int n, int k) -> long long {
        if (n < k or n < 0 or k < 0) {
            return 0;
        }
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    };
}
