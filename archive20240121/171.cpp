#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> fwk(n + 1, 0);
    auto query = [&](int i) -> int {
        int ans = 0;
        for (int f = i; f; f -= f & -f) {
            ans += fwk[f];
        }
        return ans;
    };
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            for (int f = x; f <= n; f += f & -f) {
                fwk[f] += y;
            }
        }
        if (com == 1) {
            cout << query(y) - query(x - 1) << endl;
        }
    }
}
