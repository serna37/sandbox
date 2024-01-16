#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> Graph(n);
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        u--;
        for (int ii = 0; ii < k; ii++) {
            int v;
            cin >> v;
            v--;
            Graph[u].push_back(v);
        }
    }
    for (int goal = 0; goal < n; goal++) {
        queue<pair<int, int>> q;
        bool reach = false;
        q.push({0, 0});
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            if (now.first == goal) {
                cout << goal + 1 << " " << now.second << endl;
                reach = true;
                break;
            }
            for (int v : Graph[now.first]) {
                q.push({v, now.second + 1});
            }
        }
        if (!reach) {
            cout << -1 << endl;
        }
    }
}
