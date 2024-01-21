#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<unordered_map<int, int>> seg(N << 1);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        seg[i + N][A] = 1;
    }
    for (int i = N - 1; i >= 0; i--) {
        for (pair<int, int> v : seg[i << 1 | 0]) {
            seg[i][v.first] += v.second;
        }
        for (pair<int, int> v : seg[i << 1 | 1]) {
            seg[i][v.first] += v.second;
        }
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R, X;
        cin >> L >> R >> X;
        L--;
        int ans = 0;
        for (L += N, R += N; L < R; L >>= 1, R >>= 1) {
            if (L & 1) {
                ans += seg[L++][X];
            }
            if (R & 1) {
                ans += seg[--R][X];
            }
        }
        cout << ans << endl;
    }
}
