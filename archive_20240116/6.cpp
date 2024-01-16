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
        for (int ii = 0; ii < k; ii++) {
            int v;
            cin >> v;
            v--;
            G[u].push_back(v);
        }
    }
    for (int i = 0; i < n; i++) {
        queue<pair<int, int>> q;
        bool reach = false;
        q.push({0, 0});
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            if (tmp.first == i) {
                cout << i + 1 << " " << tmp.second << endl;
                reach = true;
                break;
            }
            for (int v : G[tmp.first]) {
                q.push({v, tmp.second + 1});
            }
        }
        if (!reach) {
            cout << i + 1 << " " << -1 << endl;
        }
    }
}
