#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(3));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }
    vector<vector<int>> dp(N + 1, vector<int>(3, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][k] + A[i][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, dp[N][i]);
    }
    cout << ans << endl;
}
