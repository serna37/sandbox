#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    map<long long, long long> mp;
    auto func = [&](auto f, long long n) -> long long {
        if (n == 1) return 0;
        if (mp.count(n)) return mp[n];
        mp[n] = n + f(f, n / 2) + f(f, (n + 1) / 2);
        return mp[n];
    };
    cout << func(func, N) << endl;
}
