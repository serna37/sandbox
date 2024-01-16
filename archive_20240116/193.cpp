#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    const int INF = 1001001001;
    int ans = INF;
    for (int i = 0; i < 2; i++) {
        for (int ii = 0; ii < 2; ii++) {
            if (x <= y) {
                ans = min(ans, abs(x - y) + i + ii);
            }
            y *= -1;
        }
        x *= -1;
    }
    cout << ans << endl;
}
