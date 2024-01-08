#include <bits/stdc++.h>
using namespace std;
const long long INF = 1001001001001001001ll;
int main() {
    int x, y;
    cin >> x >> y;
    long long ans = INF;
    for (int i = 0; i < 2; i++) {
        for (int ii = 0; ii < 2; ii++) {
            if (x <= y) {
                long long c = y - x + i + ii;
                ans = min(ans, c);
            }
            y *= -1;
        }
        x *= -1;
    }
    cout << ans << endl;
}
