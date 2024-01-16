#include <bits/stdc++.h>
using namespace std;
int main() {
    const int MOD = 1000000007;
    int W, H;
    cin >> W >> H;
    int N = H + W - 2;
    int K = min(H - 1, W - 1);
    const int MAX = 3e5;
    long long fac[MAX], finv[MAX], inv[MAX];
    auto pre_nCk = [&]() -> void {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    };
    pre_nCk();
    auto nCk = [&](int n, int k) -> long long {
        if (n < k or n < 0 or k < 0) {
            return 0;
        }
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    };
    cout << nCk(N, K) << endl;
}
