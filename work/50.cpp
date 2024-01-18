#include <bits/stdc++.h>
using namespace std;
const long long INF = 1001001001001001001ll;
template <typename T> struct SegTree {
  using F = function<T(T, T)>;
  int n;
  vector<T> node;
  F combine;
  T identify;
  SegTree(int n, F combine, T identify)
      : n(n), node(n << 1, identify), combine(combine), identify(identify){};
  T operator[](int i) {
    return node[i + n];
  }
  void build(vector<T> a) {
    for (int i = 0; i < N; i++) {
      node[i + N] = a[i];
    }
    for (int i = N - 1; i >= 0; i--) {
      node[i] = combine(node[i << 1 | 0], node[i << 1 | 1]);
    }
  }
  void set(int i, T x) {
    node[i += n] = x;
    while (i >>= 1) {
      node[i] = combine(node[i << 1 | 0], node[i << 1 | 1]);
    }
  }
  T fold(int l, int r) {
    T vl = identify, vr = identify;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        vl = combine(vl, node[l++]);
      }
      if (r & 1) {
        vr = combine(node[--r], vr);
      }
    }
    return combine(vl, vr);
  }
};
int main() {
    int N;
    cin>>N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    auto combine = []( long long  x, long long  y) { return min(x, y); };
    SegTree<long long > seg(N, combine, INF);
    seg.build(A);
}
