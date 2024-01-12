#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    vector<vector<int>> G(N + 1);
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    const int MOD = 998244353;
    vector<vector<pair<int, int>>> dp(K + 1,
                                      vector<pair<int, int>>(N + 1, {0, 0}));
    dp[0][S].first = 1;
    for (int e = 0; e < K; e++) {
        for (int v = 1; v <= N; v++) {
            if (v == X) {
                swap(dp[e][v].first, dp[e][v].second);
            }
            for (int next : G[v]) {
                dp[e + 1][next].first += dp[e][v].first;
                dp[e + 1][next].first %= MOD;
                dp[e + 1][next].second += dp[e][v].second;
                dp[e + 1][next].second %= MOD;
            }
        }
    }
    cout << dp[K][T].first << endl;
}
