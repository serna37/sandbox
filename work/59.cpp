#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[j] <= i) {
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    cout << dp[n] << endl;
}
