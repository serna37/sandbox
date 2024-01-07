#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i += 2) {
        int cnt = 0;
        for (int ii = 1; ii <= i; ii++) {
            if (i % ii == 0) {
                cnt++;
            }
        }
        if (cnt == 8) {
            ans++;
        }
    }
    cout << ans << endl;
}
