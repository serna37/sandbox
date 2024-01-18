#include <bits/stdc++.h>
using namespace std;
struct segment_tree {
  int n;
  vector<int> node;
  segment_tree(int n) : n(n), node(n << 1, INT_MAX){};
  int operator[](int i) {
    return node[i + n];
  }
  int combine(int a, int b) {
    return min(a, b);
    // return a + b;
  }
  void set(int i, int x) {
    node[i += n] = x;
    while (i >>= 1) {
      node[i] = combine(node[i << 1 | 0], node[i << 1 | 1]);
    }
  }
  int fold(int l, int r) {
    int ans = INT_MAX;
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
  segment_tree seg(n);
  for (int i = 0; i < q; i++) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 1) {
      cout << seg.fold(x, y + 1) << endl;
    } else {
      seg.set(x, y);
    }
  }
}
