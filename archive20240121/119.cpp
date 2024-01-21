#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        u--;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            v--;
            G[u].push_back(v);
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<int> dis(n, -1);
    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();
        if (dis[tmp.first] != -1) {
            continue;
        }
        dis[tmp.first] = tmp.second;
        for (int v : G[tmp.first]) {
            q.push({v, tmp.second + 1});
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << dis[i] << endl;
    }
}
