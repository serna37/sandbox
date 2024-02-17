#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (w[i] <= j) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[N][W] << endl;
}
