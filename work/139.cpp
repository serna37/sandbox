#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    long long e = 0;
    vector<long long> seg(N << 1, e);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        seg[i + N] = A;
    }
    for (int i = N - 1; i >= 0; i--) {
        seg[i] = seg[i << 1 | 0] + seg[i << 1 | 1];
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            int i = b + N;
            seg[i] = b;
            while (i >>= 1) {
                seg[i] = seg[i << 1 | 0] + seg[i << 1 | 1];
            }
        }
        if (a == 2) {
            auto vl = e, vr = e;
            for (int l = N, r = 2 * N; l < r; l >>= 1, r >>= 1) {
                if (l & 1) {
                    vl += seg[l++];
                }
                if (r & 1) {
                    vr += seg[--r];
                }
            }
            cout << vl + vr << endl;
        }
    }
}
