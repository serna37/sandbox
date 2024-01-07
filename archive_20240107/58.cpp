#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
    int N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    vector<vector<int>> Graph(N + 1);
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        Graph[U].push_back(V);
        Graph[V].push_back(U);
    }
    vector<vector<pair<int, int>>> dp(K + 1,
                                      vector<pair<int, int>>(N + 1, {0, 0}));
    dp[0][S].first = 1;
    for (int i = 0; i < K; i++) {
        for (int v = 1; v < N + 1; v++) {
            if (v == X) {
                swap(dp[i][v].first, dp[i][v].second);
            }
            for (int nv : Graph[v]) {
                dp[i + 1][nv].first += dp[i][v].first;
                dp[i + 1][nv].second += dp[i][v].second;
                dp[i + 1][nv].first %= MOD;
                dp[i + 1][nv].second %= MOD;
            }
        }
    }
    cout << dp[K][T].first << endl;
}
