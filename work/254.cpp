#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    vector<vector<int>> dp(N + 1, vector<int>(X + 1, 0));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= X; j++) {
            dp[i + 1][j] = dp[i][j];
            if (B[i] <= j) {
                // knapsack
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - B[i]] + A[i]);
                // knapsack no limit
                dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - B[i]] + A[i]);
            }
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= X; j++) {
            // partial sum
            if (dp[i][j]) {
                dp[i + 1][j] = true;
                if (j + A[i] <= X) dp[i + 1][j + A[i]] = true;
            }
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= X; j++) {
            // partial sum multi
            if (!dp[i][j]) continue;
            for (int k = 0; k <= B[i]; k++) {
                int a = j + A[i] * k;
                if (a <= X) dp[i + 1][a] = true;
            }
        }
    }
    const int INF = 1001001001;
    vector<int> ddp(N + 1, INF);
    ddp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < X; j++) {
            if (i + A[j] <= N) {
                ddp[i + A[j]] = min(ddp[i + A[j]], ddp[i] + 1);
            }
        }
    }
}
