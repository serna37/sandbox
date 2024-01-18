#include <bits/stdc++.h>
using namespace std;
template <typename T> struct SegT {
  using F = function<T(T, T)>;
  int n;
  vector<T> node;
  F combine;
  T identify;
  SegT(int n, F combine, T identify)
      : n(n), node(n << 1, identify), combine(combine), identify(identify){};
  T operator[](int i) {
    return node[i + n];
  }
  void set(int i, T x) {
    node[i += n] = x;
    while (i >>= 1) {
      node[i] = combine(node[i << 1 | 0], node[i << 1 | 1]);
    }
  }
  T fold(int l, int r) {
    T ans = identify;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        ans = combine(ans, node[l++]);
      }
      if (r & 1) {
        ans = combine(ans, node[--r]);
      }
    }
    return ans;
  }
};
int main() {
  int n, q;
  cin >> n >> q;
  auto combine = [](int x, int y) { return x + y; };
  SegT<int> seg(n, combine, 0);
  for (int i = 0; i < q; i++) {
    int com, x, y;
    cin >> com >> x >> y;
    x--;
    if (com == 1) {
      cout << seg.fold(x, y) << endl;
    } else {
      seg.set(x, seg[x] + y);
    }
  }
}
