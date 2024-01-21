#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    // def
    int e = 0;
    vector<int> SegTree(N << 1, e);
    vector<int> Fenwick(N + 1, e);
    // build
    for (int i = 0; i < N; i++) {
        SegTree[i + N] = A[i];
        int f = i + 1;
        while (f <= N) {
            Fenwick[f] += A[i];
            f += f & -f;
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        SegTree[i] = SegTree[i << 1 | 0] + SegTree[i << 1 | 1];
    }
    cout << "debug_SegTree:";                // TODO debug
    for (auto v : SegTree) cout << " " << v; // TODO debug
    cout << endl;                            // TODO debug
    cout << "debug_Fenwick:";                // TODO debug
    for (auto v : Fenwick) cout << " " << v; // TODO debug
    cout << endl;                            // TODO debug
    // update
    int sa = 3, sx = 5;
    SegTree[sa += N] += sx;
    while (sa >>= 1) {
        SegTree[sa] = SegTree[sa << 1 | 0] + SegTree[sa << 1 | 1];
    }
    int fa = 2, fx = 5;
    while (fa <= N) {
        Fenwick[fa] += fx;
        fa += fa & -fa;
    }
    cout << "debug_SegTree:";                // TODO debug
    for (auto v : SegTree) cout << " " << v; // TODO debug
    cout << endl;                            // TODO debug
    cout << "debug_Fenwick:";                // TODO debug
    for (auto v : Fenwick) cout << " " << v; // TODO debug
    cout << endl;                            // TODO debug
    // query
    int sans = 0;
    for (int l = 0 + N, r = N + N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            sans += SegTree[l++];
        }
        if (r & 1) {
            sans += SegTree[--r];
        }
    }
    cout << sans << endl;
    int fans = 0;
    int r = N;
    while (r) {
        fans += Fenwick[r];
        r -= r & -r;
    }
    cout << fans << endl;
}
