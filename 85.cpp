#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N), c(Q);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < Q; i++) {
        cin >> c[i];
        c[i]--;
    }
    c.push_back(0);
    const int MOD = 1000000007;
    auto mod_pow = [](long long a, long long n, long long mod) -> long long {
        long long res = 1;
        while (n > 0) {
            if (n & 1) {
                res = res * a % mod;
            }
            a = a * a % mod;
            n >>= 1ll;
        }
        return res;
    };
    vector<long long> D(N - 1);
    for (int i = 0; i < N - 1; i++) {
        D[i] = mod_pow(a[i], a[i + 1], MOD);
    }
    vector<long long> S(N);
    for (int i = 0; i < N - 1; i++) {
        S[i + 1] = S[i] + D[i];
    }
    long long ans = 0;
    int cur = 0;
    for (int i = 0; i < Q + 1; i++) {
        ans += abs(S[cur] - S[c[i]]);
        ans %= MOD;
        cur = c[i];
    }
    cout << ans << endl;
}
