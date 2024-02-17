#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> W(N), V(N);
    vector<pair<int, int>> wv(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> V[i];
        wv[i] = {W[i], -V[i]};
    }
    sort(wv.begin(), wv.end());
    vector<int> X(M);
    for (int i = 0; i < M; i++) {
        cin >> X[i];
    }
    while (Q--) {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        multiset<int> box;
        for (int i = 0; i < M; i++) {
            if (L <= i and i <= R) {
                continue;
            }
            box.insert(X[i]);
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            auto itr = box.lower_bound(wv[i].first);
            if (itr == box.end()) {
                continue;
            }
            ans += -wv[i].second;
            box.erase(itr);
        }
        cout << ans << endl;
    }
}
