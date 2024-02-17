#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        G[A].push_back(B);
    }
    for (int i = 0; i < N; i++) {
        queue<int> q;
        q.push(i);
        vector<int> d(N, -1);
        d[i] = 0;
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
        bool alma = true;
        for (int j = 0; j < N; j++) {
            alma &= d[j] != -1;
        }
        if (alma) {
            cout << ++i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
