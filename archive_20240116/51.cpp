#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W;
    cin >> H >> W;
    int ans = 0;
    for (int i = 0; i < H; i++) {
        string S;
        cin >> S;
        for (char v : S) {
            if (v == '#') {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
