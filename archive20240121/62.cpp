#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N;
    cin >> N;
    int atom = -INF;
    vector<int> seg(N << 1, atom);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        seg[i + N] = A;
    }
    for (int i = N - 1; i >= 0; i--) {
        seg[i] = max(seg[i << 1 | 0], seg[i << 1 | 1]);
    }
    auto fold = [&](int l, int r) -> int {
        auto vl = atom, vr = atom;
        int ans = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                vl = max(vl, seg[l++]);
            }
            if (r & 1) {
                vr = max(seg[--r], vr);
            }
        }
        return max(vl, vr);
    };
    auto upd = [&](int i, int x) -> void {
        seg[i += N] = x;
        while (i >>= 1) {
            seg[i] = max(seg[i << 1 | 0], seg[i << 1 | 1]);
        }
    };
}
