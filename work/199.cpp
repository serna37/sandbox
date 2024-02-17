#include <bits/stdc++.h>
using namespace std;
int main() {
    int K, T;
    cin >> K >> T;
    vector<int> a(T);
    for (int i = 0; i < T; i++) {
        cin >> a[i];
    }
    int mx = *max_element(a.begin(), a.end());
    int lim = (K + 2 - 1) / 2;
    if (mx <= lim) {
        cout << 0 << endl;
        return 0;
    }
    int ans = K - 1 - (K - mx) * 2;
    cout << ans << endl;
}
