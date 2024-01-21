#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int atom = 0;
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
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                vl = max(vl, seg[l++]);
            }
            if (r & 1) {
                vr = max(vr, seg[--r]);
            }
        }
        return max(vl, vr);
    };
    auto update = [&](int i, int x) -> void {
        seg[i += N] = x;
        while (i >>= 1) {
            seg[i] = max(seg[i << 1 | 0], seg[i << 1 | 1]);
        }
    };
}
