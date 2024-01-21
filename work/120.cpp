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
        queue<int> q;
        q.push(i);
        vector<int> dis(N, -1);
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            if (dis[tmp] != -1) {
                continue;
            }
            dis[tmp] = tmp;
            for (int v : G[tmp]) {
                q.push(v);
            }
        }
    }
}
