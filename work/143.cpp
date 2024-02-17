#include <bits/stdc++.h>
using namespace std;
template <typename T> struct SegTree {
  private:
    int N;
    vector<T> node;
    T e = INT_MAX;
    T ope(const T &a, const T &b) {
        return min(a, b);
    }
    void update(const int &i) {
        node[i] = ope(node[i << 1 | 0], node[i << 1 | 1]);
    }

  public:
    SegTree(int n) : N(n), node(n << 1, e){};
    SegTree(int n, const vector<T> &a) : N(n), node(n << 1, e) {
        for (int i = 0; i < N; i++) node[i + N] = a[i];
        for (int i = N - 1; i >= 0; i--) update(i);
    }
    T operator[](const int &i) {
        return node[i + N];
    }
    void set(int i, const T &x) {
        node[i += N] = x;
        while (i >>= 1) update(i);
    }
    T get(int l, int r) {
        T L = e, R = e;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = ope(L, node[l++]);
            if (r & 1) R = ope(node[--r], R);
        }
        return ope(L, R);
    }
    T top() {
        return node[1];
    }
};
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N, INT_MAX); // to test build feature
    SegTree<int> seg(N, A);
    while (Q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            seg.set(x, y);
        } else {
            cout << seg.get(x, y + 1) << endl;
        }
    }
}
