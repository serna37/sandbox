#include <bits/stdc++.h>
using namespace std;
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
        for (int i = size - 1; i >= 1; --i) update(i);
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
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <typename T> struct Mmin {
    using value_type = T;
    static constexpr T e = inf<T>;
    static constexpr T op(const T &x, const T &y) noexcept {
        return min(x, y);
    }
};
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    SegTree<Mmin<int>> seg(A);
    int Q;
    cin >> Q;
    while (Q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            seg.act(b, c);
        }
        if (a == 1) {
            seg.set(b, c);
        }
        if (a == 2) {
            cout << seg.get(b, c) << endl;
        }
        if (a == 3) {
            cout << seg.top() << endl;
        }
    }
}
