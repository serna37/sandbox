#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    int K, S, T, X;
    cin >> K >> S >> T >> X;
    vector<vector<int>> G(N + 1);
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    const long long MOD = 998244353;
    vector<vector<pair<int, int>>> dp(K + 1,
                                      vector<pair<int, int>>(N + 1, {0, 0}));
    dp[0][S].first = 1;
    for (int i = 0; i < K; i++) {
        for (int j = 1; j <= N; j++) {
            if (j == X) {
                swap(dp[i][j].first, dp[i][j].second);
            }
            for (auto &v : G[j]) {
                dp[i + 1][v].first += dp[i][j].first;
                dp[i + 1][v].second += dp[i][j].second;
                dp[i + 1][v].first %= MOD;
                dp[i + 1][v].second %= MOD;
            }
        }
    }
    cout << dp[K][T].first << endl;
}
