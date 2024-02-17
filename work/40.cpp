#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int R, G, B;
        cin >> R >> G >> B;
        int rg = abs(R - G);
        int gb = abs(G - B);
        int br = abs(B - R);
        if (rg % 3 != 0 and gb % 3 != 0 and br % 3 != 0) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        if (rg % 3 == 0) {
            ans = max(ans, max(R, G));
        }
        if (gb % 3 == 0) {
            ans = max(ans, max(G, B));
        }
        if (br % 3 == 0) {
            ans = max(ans, max(B, R));
        }
        cout << ans << endl;
    }
}
