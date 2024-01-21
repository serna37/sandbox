#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(20);
    int n, m;
    cin >> n >> m;
    double ans = n % 12 * 30;
    ans += (double)m / 2;
    ans -= (double)m * 6;
    ans = abs(ans);
    cout << min(ans, 360 - ans) << endl;
}
