#include <bits/stdc++.h>
using namespace std;
template <typename T> struct SegTree {
    using F = function<T(T, T)>;
    int N;
    //vector<T> node;
    vector<unordered_map<T, int>> node;
    F combine;
    T identify;
    SegTree(int n, F combine, T identify)
        //: N(n), node(n << 1, identify), combine(combine),
        //: identify(identify){};
        : N(n), node(n << 1), combine(combine), identify(identify){};
    T operator[](int i) {
        return node[i + N];
    }
    void build(vector<T> a) {
        for (int i = 0; i < N; i++) {
            // node[i + N] = a[i];
            node[i + N][a[i]] = 1;
        }
        for (int i = N - 1; i >= 0; i--) {
            // node[i] = combine(node[i << 1 | 0], node[i << 1 | 1]);
            for (auto v : node[i << 1 | 0]) {
                node[i][v.first] += v.second;
            }
            for (auto v : node[i << 1 | 1]) {
                node[i][v.first] += v.second;
            }
        }
    }
    void set(int i, T x) {
        node[i += N] = x;
        while (i >>= 1) {
            node[i] = combine(node[i << 1 | 0], node[i << 1 | 1]);
        }
    }
    // T fold(int l, int r) {
    T fold(int l, int r, int x) {
        // T vl = identify, vr = identify;
        int ans = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                // vl = combine(vl, node[l++]);
                ans += node[l++][x];
            }
            if (r & 1) {
                // vr = combine(node[--r], vr);
                ans += node[--r][x];
            }
        }
        // return combine(vl, vr);
        return ans;
    }
};
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    auto combine = [](int x, int y) { return x + y; };
    SegTree<int> seg(N, combine, 0);
    seg.build(A);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R, X;
        cin >> L >> R >> X;
        cout << seg.fold(L - 1, R, X) << endl;
    }
}
