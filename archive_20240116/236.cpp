#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    n %= 12;
    double h = 30.0 * n;
    h += 30.0 * m / 60;
    double mi = 360.0 * m / 60;
    double ans = h - mi;
    if (ans < 0) {
        ans += 360;
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
}
