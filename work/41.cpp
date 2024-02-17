#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        G[u].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> G[u][j];
        }
    }
    queue<int> q;
    q.push(1);
    vector<int> d(n + 1, -1);
    d[1] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int nv : G[v]) {
            if (d[nv] == -1) {
                d[nv] = d[v] + 1;
                q.push(nv);
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        cout << i << " " << d[i] << endl;
    }
}
