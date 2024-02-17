#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j <= N; j++) {
            if (dp[i][j]) {
                dp[i + 1][j] = true;
                dp[i + 1][min(j + A[i], N)] = true;
            }
        }
    }
    cout << dp[N][M] << endl;
}
