#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
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
    vector<vector<pair<int, int>>> dp(K + 1,
                                      vector<pair<int, int>>(N + 1, {0, 0}));
    dp[0][S].first = 1;
    for (int e = 0; e < K; e++) {
        for (int v = 0; v <= N; v++) {
            if (v == X) {
                swap(dp[e][v].first, dp[e][v].second);
            }
            for (auto &n : G[v]) {
                dp[e + 1][n].first += dp[e][v].first;
                dp[e + 1][n].second += dp[e][v].second;
                dp[e + 1][n].first %= MOD;
                dp[e + 1][n].second %= MOD;
            }
        }
    }
    cout << dp[K][T].first << endl;
}
