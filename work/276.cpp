#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    map<long long, long long> mp;
    auto func = [&](auto f, long long a) -> long long {
        if (a == 1) return 0;
        if (mp.count(a)) return mp[a];
        mp[a] = a + f(f, a / 2) + f(f, (a + 1) / 2);
        return mp[a];
    };
    cout << func(func, N) << endl;
}
