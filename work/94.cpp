#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N;
    cin >> N;
    vector<int> dp(N + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; i + j <= N; j *= 6) {
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
        for (int j = 1; i + j <= N; j *= 9) {
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }
    cout << dp[N] << endl;
}
