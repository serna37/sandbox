#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> W(N), V(N);
    vector<pair<int, int>> vw;
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> V[i];
        vw.push_back({V[i], -W[i]});
    }
    sort(vw.rbegin(), vw.rend());
    vector<int> X(M);
    for (int i = 0; i < M; i++) {
        cin >> X[i];
    }
    while (Q--) {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        set<int> x;
        for (int i = 0; i < M; i++) {
            if (L <= i and i <= R) {
                continue;
            }
            x.insert(X[i]);
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            auto itr = x.lower_bound(-vw[i].second);
            if (itr == x.end()) {
                continue;
            }
            ans += vw[i].first;
            x.erase(itr);
        }
        cout << ans << endl;
    }
}
