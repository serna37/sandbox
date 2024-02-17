#include <bits/stdc++.h>
using namespace std;
template <typename T> struct RxQsum {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T ope(const T &x, const T &y) noexcept {
        return x + y;
    }
};
template <class M> struct SegTree {
    using T = typename M::value_type;

  private:
    int N;
    vector<T> node;
    void update(const int &i) {
        node[i] = M::ope(node[i << 1 | 0], node[i << 1 | 1]);
    }

  public:
    SegTree(int n) : N(n), node(n << 1, M::e){};
    SegTree(int n, const vector<T> &a) : N(n), node(n << 1, M::e) {
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
        T L = M::e, R = M::e;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = M::ope(L, node[l++]);
            if (r & 1) R = M::ope(node[--r], R);
        }
        return M::ope(L, R);
    }
    T top() {
        return node[1];
    }
};
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    SegTree<RxQsum<long long>> seg(N, a);
    while (Q--) {
        int q, j, k;
        cin >> q >> j >> k;
        if (q == 0) {
            seg.set(j, seg[j] + k);
        } else {
            cout << seg.get(j, k) << endl;
        }
    }
}
