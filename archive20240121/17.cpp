#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> W(N), V(N), X(M);
    vector<pair<int, int>> wx(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> V[i];
        wx[i] = {V[i], W[i]};
    }
    sort(wx.rbegin(), wx.rend());
    for (int i = 0; i < M; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        multiset<int> x;
        for (int j = 0; j < M; j++) {
            if (L <= j and j <= R) {
                continue;
            }
            x.insert(X[j]);
        }
        int ans = 0;
        for (int j = 0; j < N; j++) {
            auto itr = x.lower_bound(wx[j].second);
            if (itr == x.end()) {
                continue;
            }
            ans += wx[j].first;
            x.erase(itr);
        }
        cout << ans << endl;
    }
}
