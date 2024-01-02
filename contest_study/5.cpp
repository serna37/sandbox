#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> W(N), X(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> X[i];
    }
    int ans = 0;
    for (int i = 0; i < 24; i++) {
        int tmp = 0;
        for (int ii = 0; ii < N; ii++) {
            int t = i + X[ii];
            t %= 24;
            if (9 <= t and t + 1 <= 18) {
                tmp += W[ii];
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
