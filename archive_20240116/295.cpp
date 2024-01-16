#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = n * c;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (i == j) continue;
            int tmp = 0;
            for (int k = 0; k < n; k++) {
                if (k & 1) {
                    if (a[k] != i) tmp += c;
                } else {
                    if (a[k] != j) tmp += c;
                }
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
}
