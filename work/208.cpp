#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 2147483647;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <typename T> struct Mmin {
    using value_type = T;
    static constexpr T e = inf<T>;
    static constexpr T op(const T &x, const T &y) noexcept {
        return min(x, y);
    }
};
template <class Monoid> struct SegTree {
    using M = Monoid;
    using T = typename M::value_type;

  private:
    int N, log, size;
    vector<T> node;
    void init() {
        log = 1;
        while ((1 << log) < N) ++log;
        size = 1 << log;
        node.assign(size << 1, M::e);
    }
    void update(const int &i) {
        node[i] = M::op(node[i << 1 | 0], node[i << 1 | 1]);
    }

  public:
    SegTree(int n) : N(n) {
        init();
    }
    SegTree(const vector<T> &a) : N(a.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + size] = a[i];
        for (int i = size - 1; i > 0; --i) update(i);
    }
    T operator[](int i) {
        return node[i + size];
    }
    void set(int i, const T &x) {
        node[i += size] = x;
        while (i >>= 1) update(i);
    }
    void act(int i, const T &x) {
        i += size;
        node[i] = M::op(node[i], x);
        while (i >>= 1) update(i);
    }
    T get(int l, int r) {
        T L = M::e, R = M::e;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = M::op(L, node[l++]);
            if (r & 1) R = M::op(node[--r], R);
        }
        return M::op(L, R);
    }
    T top() {
        return node[1];
    }
};
int main() {
    int n, q;
    cin >> n >> q;
    SegTree<Mmin<int>> seg(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            seg.set(x, y);
        }
        if (com == 1) {
            cout << seg.get(x, ++y) << endl;
        }
    }
}
