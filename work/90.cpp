#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> dp(N + 1);
    iota(dp.begin(), dp.end(), 0);
    for (int i = 0; i <= N; i++) {
        for (int c = 6; i + c <= N; c *= 6) {
            dp[i + c] = min(dp[i + c], dp[i] + 1);
        }
        for (int c = 9; i + c <= N; c *= 9) {
            dp[i + c] = min(dp[i + c], dp[i] + 1);
        }
    }
    cout << dp[N] << endl;
}
