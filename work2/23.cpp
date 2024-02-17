#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
int main() {
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    int V = 1e5;
    vector<vector<long long>> dp(N + 1,
                                 vector<long long>(V + 1, inf<long long>));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= V; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (v[i] <= j) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= V; i++) {
        if (dp[N][i] <= W) {
            ans = max(ans, i);
        }
    }
    cout << ans << endl;
}
