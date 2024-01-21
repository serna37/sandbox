#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> seg(N << 1, INF);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        seg[i + N] = a;
    }
    for (int i = N - 1; i >= 0; i--) {
        seg[i] = min(seg[i << 1 | 0], seg[i << 1 | 1]);
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        auto vl = INF, vr = INF;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                vl = min(vl, seg[l++]);
            }
            if (r & 1) {
                vr = min(vr, seg[--r]);
            }
        }
        cout << min(vl, vr) << '\n';
    }
}
