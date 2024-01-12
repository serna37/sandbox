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
        vector<int> box;
        for (int i = 0; i < M; i++) {
            if (L <= i and i < R) {
                continue;
            }
            box.push_back(X[i]);
        }
        sort(box.begin(), box.end());
        int ans = 0;
        int B = box.size();
        priority_queue<int> q;
        int under = 0;
        for (int b = 0; b < B; b++) {
            for (int n = 0; n < N; n++) {
                if (under < W[n] and W[n] <= box[b]) {
                    q.push(V[n]);
                }
            }
            under = box[b];
            if (!q.empty()) {
                ans += q.top();
                q.pop();
            }
        }
        cout << ans << endl;
    }
}
