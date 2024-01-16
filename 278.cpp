#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(20);
    int n, m;
    cin >> n >> m;
    double tmp = 30 * (n % 12 + m / 60.0) - m * 6;
    tmp = abs(tmp);
    cout << min(360 - tmp, tmp) << endl;
}
