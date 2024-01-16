#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int R, G, B;
        cin >> R >> G >> B;
        if ((R % 3 == G % 3) or (G % 3 == B % 3) or (B % 3 == R % 3)) {
            int ans = INF;
            if (R % 3 == G % 3) {
                ans = min(ans, max(R, G));
            }
            if (G % 3 == B % 3) {
                ans = min(ans, max(G, B));
            }
            if (B % 3 == R % 3) {
                ans = min(ans, max(B, R));
            }
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
