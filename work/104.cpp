#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    vector<int> weight(N), value(N);
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (w < weight[i]) {
                dp[i + 1][w] = dp[i][w];
            } else {
                dp[i + 1][w] = max(dp[i][w], dp[i][w - weight[i]] + value[i]);
            }
            
        }
    }
    cout << dp[N][M] << endl;
}
