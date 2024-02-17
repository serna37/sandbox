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
    int N, Q;
    cin >> N >> Q;
    UnionFind<int> uf(N);
    while (Q--) {
        int P, A, B;
        cin >> P >> A >> B;
        if (P == 0) {
            uf.unite(A, B);
        }
        if (P == 1) {
            cout << (uf.same(A, B) ? "Yes" : "No") << endl;
        }
    }
}
