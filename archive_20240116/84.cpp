#include <bits/stdc++.h>
using namespace std;
int main() {
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
}
