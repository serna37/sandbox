#include <bits/stdc++.h>
using namespace std;
int main() {
    int W, H;
    cin >> W >> H;
    W--;
    H--;
    const int MOD = 1000000007;
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
    assert(nCk(H + W, W) == mod_combination(H + W, W));
    cout << mod_combination(H + W, W) << endl;
}
