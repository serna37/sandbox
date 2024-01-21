#include <bits/stdc++.h>
using namespace std;
int main() {
    const long long MOD = 998244353;
    auto mod_pow = [&](long long a, long long n) -> long long {
        long long ans = 1;
        while (n > 0) {
            if (n & 1) {
                ans = ans * a % MOD;
            }
            a = a * a % MOD;
            n >>= 1ll;
        }
        return ans;
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
wmodfacin:wq
}
