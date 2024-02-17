#include <bits/stdc++.h>
using namespace std;
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
            if (l & 1) L = ope(L, node[l++]);
            if (r & 1) R = ope(node[--r], R);
        }
        return ope(L, R);
    }
    T top() {
        return node[1];
    }
};
template <typename T> struct RxQsum {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T ope(const T &x, const T &y) noexcept {
        return x + y;
    }
};
int main() {
    int N = 5;
    vector<int> A = {1, 2, 3, 4, 5};
    SegTree<RxQsum<int>> seg(N, A);
}
