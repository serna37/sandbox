#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> cnt(N);
    for (int i = 0; i < N; i++) {
        cnt[A[i]]++;
    }
    vector<vector<int>> dp(N, vector<int>(3, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 3; j++) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j + 1] += dp[i][j] * cnt[i];
        }
    }
    cout << dp[N][3] << endl;
}
