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
        for (int ii = 1; ii <= 10; ii++) {
            if (i == ii) {
                continue;
            }
            int tmp = 0;
            for (int k = 0; k < n; k++) {
                if (k % 2 == 0) {
                    if (a[k] != i) {
                        tmp += c;
                    }
                } else {
                    if (a[k] != ii) {
                        tmp += c;
                    }
                }
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
}
