#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<pair<int, int>> vw;
    vector<int> X(M);
    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        vw.push_back({v, w});
    }
    sort(vw.rbegin(), vw.rend());
    for (int i = 0; i < M; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        L--;
        multiset<int> X2;
        for (int i = 0; i < N; i++) {
            if (L <= i and i < R) {
                continue;
            }
            X2.insert(X[i]);
        }
        int ans = 0;
        for (auto v : vw) {
            auto itr = X2.lower_bound(v.second);
            if (itr == X2.end()) {
                continue;
            }
            X2.erase(itr);
            ans += v.first;
        }
        cout << ans << endl;
    }
}
