#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int atom = 0;
    vector<int> seg(N << 1, atom);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        seg[i + N] = A[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        seg[i] = gcd(seg[i << 1 | 0], seg[i << 1 | 1]);
    }
    auto fold = [&](int l, int r) -> int {
        auto vl = atom, vr = atom;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                vl = gcd(vl, seg[l++]);
            }
            if (r & 1) {
                vr = gcd(seg[--r], vr);
            }
        }
        return gcd(vl, vr);
    };
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int g = atom;
        g = gcd(g, fold(0, i));
        g = gcd(g, fold(i + 1, N));
        ans = max(ans, g);
    }
    cout << ans << endl;
}
