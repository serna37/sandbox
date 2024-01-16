#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(20);
    int n, m;
    cin >> n >> m;
    double tmp = (n % 12 + (double)m / 60) * 30 - m * 6;
    if (tmp < 0) {
        tmp += 360;
    }
    cout << min(tmp, 360 - tmp) << endl;
}
