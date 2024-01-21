#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    unordered_map<int, int> atom;
    vector<unordered_map<int, int>> seg(N << 1, atom);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        seg[i + N][A] = 1;
    }
    for (int i = N - 1; i >= 0; i--) {
        for (auto v : seg[i << 1 | 0]) {
            seg[i][v.first] += v.second;
        }
        for (auto v : seg[i << 1 | 1]) {
            seg[i][v.first] += v.second;
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r, X;
        cin >> l >> r >> X;
        int ans = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                if (seg[l].count(X)) {
                    ans += seg[l][X];
                }
                l++;
            }
            if (r & 1) {
                --r;
                if (seg[r].count(X)) {
                    ans += seg[r][X];
                }
            }
        }
        cout << ans << endl;
    }
}
