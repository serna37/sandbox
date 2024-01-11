#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    vector<char> ans(10, 'x');
    for (int i = 0; i < a; i++) {
        int p;
        cin >> p;
        ans[p] = '.';
    }
    for (int i = 0; i < b; i++) {
        int q;
        cin >> q;
        ans[q] = 'o';
    }
    cout << ans[7] << " " << ans[8] << " " << ans[9] << " " << ans[0] << endl;
    cout << " " << ans[4] << " " << ans[5] << " " << ans[6] << endl;
    cout << "  " << ans[2] << " " << ans[3] << endl;
    cout << "   " << ans[1] << endl;
}
