#include <bits/stdc++.h>
using namespace std;
int main() {
    long long X, Y;
    cin >> X >> Y;
    long long ans = 0;
    while (X <= Y) {
        ans++;
        X *= 2;
    }
    cout << ans << endl;
}
