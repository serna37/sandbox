#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
template <typename T> struct SegTree {
    using F = function<T(T, T)>;
    int N;
    vector<T> node;
    F combine;
    T identify;
    SegTree(int n, F combine, T identify)
        : N(n), node(n << 1, identify), combine(combine), identify(identify){};
    T operator[](int i) {
        return node[i + N];
    }
    void build(vector<T> a) {
        for (int i = 0; i < N; i++) {
            node[i + N] = a[i];
        }
        for (int i = N - 1; i >= 0; i--) {
            node[i] = combine(node[i << 1 | 0], node[i << 1 | 1]);
        }
    }
    void set(int i, T x) {
        node[i += N] = x;
        while (i >>= 1) {
            node[i] = combine(node[i << 1 | 0], node[i << 1 | 1]);
        }
    }
    T fold(int l, int r) {
        T vl = identify, vr = identify;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                vl = combine(vl, node[l++]);
            }
            if (r & 1) {
                vr = combine(node[--r], vr);
            }
        }
        return combine(vl, vr);
    }
};
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    auto combine = [](int x, int y) { return min(x, y); };
    SegTree<int> seg(N, combine, INF);
    seg.build(a);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << seg.fold(l, r) << endl;
    }
}
