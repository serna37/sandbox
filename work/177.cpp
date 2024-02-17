#include <bits/stdc++.h>
using namespace std;
template <class T> struct UnionFind {
  private:
    vector<T> par;

  public:
    UnionFind(int N) : par(N) {
        iota(par.begin(), par.end(), 0);
    }
    T root(int i) {
        return par[i] == i ? i : par[i] = root(par[i]);
    }
    void unite(T x, T y) {
        T rx = root(x), ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }
    bool same(T x, T y) {
        return root(x) == root(y);
    }
};
int main() {
    int n, q;
    cin >> n >> q;
    UnionFind<int> uf(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            uf.unite(x, y);
        }
        if (com == 1) {
            cout << uf.same(x, y) << endl;
        }
    }
}
