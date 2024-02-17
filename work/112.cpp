#include <bits/stdc++.h>
using namespace std;
template <typename T> struct SegTree {
  private:
    int e = 0;
    int N;
    vector<T> node;
    T bind(T a, T b) {
        return a + b;
    }

  public:
    SegTree(int n) : N(n), node(n << 1, e){};
    T operator[](int i) {
        return node[i + N];
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
    int n, q;
    cin >> n >> q;
    SegTree<int> seg(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        x--;
        if (com == 0) {
            seg.set(x, seg[x] + y);
        } else {
            cout << seg.fold(x, y) << endl;
        }
    }
}
