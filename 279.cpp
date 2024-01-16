#include <bits/stdc++.h>
using namespace std;
int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx;
    int dy = ty - sy;
    string ans = "";
    ans += string(dy, 'U');
    ans += string(dx, 'R');
    ans += string(dy, 'D');
    ans += string(dx, 'L');
    ans += 'L';
    ans += string(dy + 1, 'U');
    ans += string(dx + 1, 'R');
    ans += "DR";
    ans += string(dy + 1, 'D');
    ans += string(dx + 1, 'L');
    ans += 'U';
    cout << ans << endl;
}
