#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int Q;
    cin >> Q;
    int N = Q;
    int atom = INF;
    vector<int> seg(N << 1, atom);
    vector<int> tmp;
    bool sorted = false;
    int idx = 0;
    while (Q--) {
        int q;
        cin >> q;
        if (q == 1) {
            int x;
            cin >> x;
            tmp.push_back(x);
            sorted = false;
        } else if (q == 2) {
            for (auto &v : tmp) {
                seg[idx += N] = v;
                while (idx >>= 1) {
                    seg[idx] = min(seg[idx << 1 | 0], seg[idx << 1 | 1]);
                }
                idx++;
            }
            int l = 0, r = N;
            auto vl = atom, vr = atom;
            int ans = 0;
            for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
                if (l & 1) {
                    vl = min(vl, seg[l++]);
                }
                if (r & 1) {
                    vr = min(vr, seg[--r]);
                }
            }
            cout << min(vl, vr) << endl;
        } else {
            sorted = true;
        }
    }
}
