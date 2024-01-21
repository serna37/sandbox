#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int R, G, B;
        cin >> R >> G >> B;
        int ans = INF;
        bool a = abs(R - B) % 3 == 0;
        bool b = abs(B - G) % 3 == 0;
        bool c = abs(G - R) % 3 == 0;
        if (a) {
            ans = min(ans, max(R, B));
        }
        if (b) {
            ans = min(ans, max(B, G));
        }
        if (c) {
            ans = min(ans, max(G, R));
        }
        if (!a and !b and !c) {
            ans = -1;
        }
        cout << ans << endl;
    }
}
