#include <bits/stdc++.h>
using namespace std;
const long long INF = 1001001001001001001ll;
int main() {
    long long x, y;
    cin >> x >> y;
    long long ans = INF;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (x <= y) {
                ans = min(ans, y - x + i + j);
            }
            x *= -1;
        }
        y *= -1;
    }
    cout << ans << endl;
}
