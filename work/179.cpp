#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
  private:
    int N;
    vector<int> par;

  public:
    UnionFind(int N) : N(N), par(N) {
        iota(par.begin(), par.end(), 0);
    }
    int getRoot(const int &i) {
        return par[i] == i ? i : par[i] = getRoot(par[i]);
    }
    void unite(int x, int y) {
        int rx = getRoot(x), ry = getRoot(y);
        if (rx == ry) return;
        par[rx] = ry;
    }
    bool isSameRoot(int x, int y) {
        return getRoot(x) == getRoot(y);
    }
    bool isRoot(int i) {
        return getRoot(i) == i;
    }
    int getRootCnt() {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (isRoot(i)) cnt++;
        }
        return cnt;
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
        UnionFind uf(N);
        for (int j = 0; j < M; j++) {
            if (i == j) continue;
            uf.unite(a[j], b[j]);
        }
        if (1 < uf.getRootCnt()) ans++;
    }
    cout << ans << endl;
}
