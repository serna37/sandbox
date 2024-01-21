#include <bits/stdc++.h>
using namespace std;
int main() {
    const long long MOD = 1000000007;
    string S;
    cin >> S;
    string T = "chokudai";
    int N = S.size();
    vector<vector<long long>> dp(N + 1, vector<long long>(8 + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 8; j++) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;
            if (j < 8 and S[i] == T[j]) {
                dp[i + 1][j + 1] += dp[i][j];
                dp[i + 1][j + 1] %= MOD;
            }
        }
    }
    cout << dp[N][8] << endl;
}
