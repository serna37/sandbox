#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> G(N + 1);
    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;
        G[L].push_back(R);
    }
    vector<vector<int>> S(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (auto v : G[i]) {
            S[i][v]++;
        }
        for (int j = 1; j < N; j++) {
            S[i][j + 1] += S[i][j];
        }
    }
    while (Q--) {
        int p, q;
        cin >> p >> q;
        int ans = 0;
        for (int i = p; i <= q; i++) {
            ans += S[i][q] - S[i][p - 1];
        }
        cout << ans << endl;
    }
}
