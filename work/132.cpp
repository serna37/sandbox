#include <bits/stdc++.h>
using namespace std;
template <typename T> struct SegTree {
  private:
    int e = 0;
    int N;
    vector<T> v;
    T c(const T &a, const T &b) {
        return a + b;
    }

  public:
    SegTree(int n) : N(n), v(n << 1, e){};
    T operator[](const int &i) {
        return v[i + N];
    }
    void build(const vector<T> &a) {
        for (int i = 0; i < N; i++) v[i + N] = a[i];
        for (int i = N - 1; i >= 0; i--) v[i] = c(v[i << 1 | 0], v[i << 1 | 1]);
    }
    void set(int i, const T &x) {
        v[i += N] = x;
        while (i >>= 1) v[i] = c(v[i << 1 | 0], v[i << 1 | 1]);
    }
    T get(int l, int r) {
        T vl = e, vr = e;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = c(vl, v[l++]);
            if (r & 1) vr = c(v[--r], vr);
        }
        return c(vl, vr);
    }
    T top() {
        return v[1];
    }
};
int main() {
    int N, Q;
    cin >> N >> Q;
    SegTree<int> seg(N);
    while (Q--) {
        int com, x, y;
        cin >> com >> x >> y;
        x--;
        if (com == 0) {
            seg.set(x, seg[x] + y);
        } else {
            cout << seg.get(x, y) << endl;
        }
    }
}
