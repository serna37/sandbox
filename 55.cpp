#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W;
    cin >> H >> W;
    int ans = 0;
    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        for (int ii = 0; ii < W; ii++) {
            if (s[ii] == '#') {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
