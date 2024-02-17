#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int e = 0;
    vector<int> seg(N << 1, e);
    for (int i = 0; i < N; i++) {
        seg[i + N] = A[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        seg[i] = max(seg[i << 1 | 0], seg[i << 1 | 1]);
    }
    auto set = [&](int i, int x) -> void {
        int leaf = i + N;
        seg[leaf] = x;
        while (leaf >>= 1) {
            seg[leaf] = max(seg[i << 1 | 0], seg[i << 1 | 1]);
        }
    };
    auto fold = [&](int l, int r) -> int {
        int vl = e, vr = e;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                vl = max(vl, seg[l++]);
            }
            if (r & 1) {
                vr = max(vr, seg[-r]);
            }
        }
        return max(vl, vr);
    };
}
