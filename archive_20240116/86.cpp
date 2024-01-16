#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
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
    const int MOD = 1000000007;
    cout << mod_pow(m, n, MOD) << endl;
}
