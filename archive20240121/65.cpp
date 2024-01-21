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
    vector<int> ans;
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
        for (auto v : vis) {
            alma &= v;
        }
        if (alma) {
            ans.push_back(i + 1);
        }
    }
    if (ans.size() != 1) {
        cout << -1 << endl;
    } else {
        cout << ans.front() << endl;
    }
}
