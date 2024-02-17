#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
vector<long long> mf;
long long modfact(int x) {
    if ((int)mf.size() > x) return mf[x];
    if (mf.empty()) mf.push_back(1);
    for (int i = mf.size(); i <= x; i++) mf.push_back(mf.back() * i % MOD);
    return mf[x];
}
template <typename T> T factorial(T N) {
    T ans = 1;
    while (N > 0) ans *= N--;
    return ans;
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
template <typename T> T modinv(T a) {
    return modpow(a, MOD - 2);
}
long long mod_combination(int n, int k) {
    return modfact(n) * modinv(modfact(k)) % MOD * modinv(modfact(n - k)) % MOD;
}
int main() {
}
