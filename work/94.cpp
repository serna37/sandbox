#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
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
    auto mod_pow = [&](long long a, long long n) -> long long {
        long long res = 1;
        while (n > 0) {
            if (n & 1) {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            n >>= 1ll;
        }
        return res;
    };
    auto modinv_fermat = [&](long long a) -> long long {
        return mod_pow(a, MOD - 2);
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
    auto comp = []<class T>(vector<T> vec) -> vector<T> {
        auto v = vec;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < (int)vec.size(); i++) {
            vec[i] = lower_bound(v.begin(), v.end(), vec[i]) - v.begin();
        }
        return vec;
    };
    auto digitsum = []<class T>(T a, int N = 10) -> T {
        T ans = 0;
        while (a != 0) {
            ans += a % N;
            a /= N;
        }
        return ans;
    };
}
