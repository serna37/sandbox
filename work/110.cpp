#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
template <typename T> struct SegTree {
    int e = INF;
    int N;
    vector<T> node;
    SegTree(int n) : N(n), node(n << 1, e){};
    T operator[](int i) {
        return node[i + N];
    }
    T bind(T a, T b) {
        return min(a, b);
    }
    void build(vector<T> a) {
        for (int i = 0; i < N; i++) {
            node[i + N] = a[i];
        }
        for (int i = N - 1; i >= 0; i--) {
            node[i] = bind(node[i << 1 | 0], node[i << 1 | 1]);
        }
    }
    void set(int i, T x) {
        node[i += N] = x;
        while (i >>= 1) {
            node[i] = bind(node[i << 1 | 0], node[i << 1 | 1]);
        }
    }
    T fold(int l, int r) {
        T vl = e, vr = e;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                vl = bind(vl, node[l++]);
            }
            if (r & 1) {
                vr = bind(node[--r], vr);
            }
        }
        return bind(vl, vr);
    }
    T top() {
        return node[1];
    }
};
int main() {
    int N, Q;
    cin >> N >> Q;
    int M = 2 * 1e5;
    SegTree<int> seg(M);
    vector<multiset<int>> st(M);
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        st[B[i]].insert(A[i]);
    }
    auto get = [&](multiset<int> s) -> int {
        return s.empty() ? INF : *--s.end();
    };
    vector<int> tmp;
    for (auto &v : st) {
        tmp.push_back(get(v));
    }
    seg.build(tmp);
    while (Q--) {
        int C, D;
        cin >> C >> D;
        C--;
        int asis = B[C];
        st[asis].erase(st[asis].find(A[C]));
        seg.set(asis, get(st[asis]));
        B[C] = D;
        st[D].insert(A[C]);
        seg.set(D, get(st[D]));
        cout << seg.top() << endl;
    }
}
