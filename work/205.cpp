#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <typename T> struct RxQmin {
    using value_type = T;
    static constexpr T e = inf<T>;
    static constexpr T ope(const T &x, const T &y) noexcept {
        return min(x, y);
    }
};
template <class M> class DynamicSegTree {
    using T = typename M::type_value;

  public:
    DynamicSegTree(int n) : N(n), root(nullptr){};
    int operator[](int i) {
        return get(root, 0, N, i);
    }
    void set(int i, T x) {
        set(root, 0, N, i, x);
    }
    int get(int l, int r) {
        return prod(root, 0, N, l, r);
    }

  private:
    struct node {
        T value;
        node *left;
        node *right;
        node(T v) : value(v), left(nullptr), right(nullptr){};
    };
    int N;
    node *root;
    void set(node *&n, int l, int r, int i, T x) {
        if (!n) {
            // TODO Monoid
            n = new node(0);
        }
        if (r - l == 1) {
            n->value = x;
            return;
        }
        int mid = (l + r) >> 1;
        if (i < mid) {
            set(n->left, l, mid, i, x);
        } else {
            set(n->right, mid, r, i, x);
        }
        // TODO Monoid
        n->value = 0;
        // TODO ope
        if (n->left) {
            n->value += n->left->value;
        }
        if (n->right) {
            n->value += n->right->value;
        }
    }
    int get(node *&n, int l, int r, int i) {
        if (!n) {
            // TODO Monoid
            return 0;
        }
        if (r - l == 1) {
            return n->value;
        }
        int mid = (l + r) >> 1;
        if (i < mid) {
            return get(n->left, l, mid, i);
        } else {
            return get(n->right, mid, r, i);
        }
    }
    int prod(node *&n, int a, int b, int l, int r) {
        if (!n or b <= l or r <= a) {
            // TODO Monoid
            return 0;
        }
        if (l <= a and b <= r) {
            return n->value;
        }
        int mid = (l + r) >> 1;
        // TODO ope
        return prod(n->left, a, mid, l, r) + prod(n->right, mid, b, l, r);
    }
};
