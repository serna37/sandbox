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
    bool isRoot(int i) {
        return root(i) == i;
    }
};
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        UnionFind<int> uf(N);
        for (int j = 0; j < M; j++) {
            if (i == j) continue;
            uf.unite(a[j], b[j]);
        }
        int tmp = 0;
        for (int j = 0; j < N; j++) {
            if (uf.isRoot(j)) {
                tmp++;
            }
        }
        if (1 < tmp) {
            ans++;
        }
    }
    cout << ans << endl;
}
