#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> W(N), V(N), X(M);
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> V[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        L--;
        vector<int> x;
        for (int i = 0; i < M; i++) {
            if (L <= i and i < R) {
                continue;
            }
            x.push_back(X[i]);
        }
        sort(x.begin(), x.end());
        int xx = x.size();
        int ans = 0;
        priority_queue<int> q;
        int under = 0;
        for (int k = 0; k < xx; k++) {
            for (int w = 0; w < N; w++) {
                if (under < W[w] and W[w] <= x[k]) {
                    q.push(V[w]);
                }
            }
            under = x[k];
            if (!q.empty()) {
                ans += q.top();
                q.pop();
            }
        }
        cout << ans << endl;
    }
}
