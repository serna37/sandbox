#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        G[A].push_back(B);
    }
    for (int i = 0; i < N; i++) {
        vector<bool> vis(N);
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            if (vis[v]) {
                continue;
            }
            vis[v] = true;
            for (int n : G[v]) {
                q.push(n);
            }
        }
        bool alma = true;
        for (int j = 0; j < N; j++) {
            alma &= vis[j];
        }
        if (alma) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
