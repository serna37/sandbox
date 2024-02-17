#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    int S = reduce(T.begin(), T.end());
    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            if (dp[i][j]) {
                dp[i + 1][j] = true;
                dp[i + 1][j + T[i]] = true;
            }
        }
    }
    int ans = S;
    for (int i = 0; i <= S; i++) {
        if (dp[N][i]) {
            ans = min(ans, max(i, S - i));
        }
    }
    cout << ans << endl;
}
