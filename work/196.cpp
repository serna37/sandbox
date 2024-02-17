#include <bits/stdc++.h>
using namespace std;
int main() {
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    int dy = gy - sy;
    int dx = gx - sx;
    string ans = "";
    ans += string(dy, 'U');
    ans += string(dx, 'R');
    ans += string(dy, 'D');
    ans += string(dx + 1, 'L');
    ans += string(dy + 1, 'U');
    ans += string(dx + 1, 'R');
    ans += "DR";
    ans += string(dy + 1, 'D');
    ans += string(dx + 1, 'L');
    ans += 'U';
    cout << ans << endl;
}
