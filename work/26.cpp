#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    int n = 2 * 1e5 + 1;
    const int INF = 1001001001;
    int e = INF;
    vector<int> seg(n << 1, e);
    vector<multiset<int>> local(n);
    for (int i = 0; i < N; i++) {
        local[B[i]].insert(A[i]);
    }
    for (int i = 0; i < N; i++) {
        seg[B[i] + n] = *--local[B[i]].end();
    }
    for (int i = n - 1; i >= 0; i--) {
        seg[i] = min(seg[i << 1 | 0], seg[i << 1 | 1]);
    }
    auto f = [&](int C) -> void {
        int leaf = B[C] + n;
        seg[leaf] = local[B[C]].empty() ? INF : *--local[B[C]].end();
        while (leaf >>= 1) {
            seg[leaf] = min(seg[leaf << 1 | 0], seg[leaf << 1 | 1]);
        }
    };
    while (Q--) {
        int C, D;
        cin >> C >> D;
        C--;
        local[B[C]].erase(local[B[C]].find(A[C]));
        f(C);
        B[C] = D;
        local[D].insert(A[C]);
        f(C);
        cout << seg[1] << endl;
    }
}
