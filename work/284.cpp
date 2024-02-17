#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
  private:
    int N;
    vector<int> dat;
    void build() {
        dat.assign(N, -1);
    }

  public:
    UnionFind(int n = 0) : N(n) {
        build();
    }
    void reset() {
        build();
    }
    int operator[](int x) {
        while (dat[x] >= 0) {
            int pp = dat[dat[x]];
            if (pp < 0) return dat[x];
            x = dat[x] = pp;
        }
        return x;
    }
    long long size(int x) {
        x = (*this)[x];
        return -dat[x];
    }
    bool unite(int x, int y) {
        x = (*this)[x], y = (*this)[y];
        if (x == y) return false;
        if (-dat[x] < -dat[y]) swap(x, y);
        dat[x] += dat[y], dat[y] = x;
        return true;
    }
    vector<vector<int>> groups() {
        vector<vector<int>> ret(N);
        for (int i = 0; i < N; i++) {
            ret[(*this)[i]].emplace_back(i);
        }
        ret.erase(remove_if(begin(ret), end(ret),
                            [&](const vector<int> &v) { return v.empty(); }),
                  end(ret));
        return ret;
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
    UnionFind uf(N);
    int ans = 0;
    for (int i = 0; i < M; i++) {
        uf.reset();
        for (int j = 0; j < M; j++) {
            if (i == j) continue;
            uf.unite(a[j], b[j]);
        }
        // auto g = uf.groups();
        //  if ((int)g.size() > 1) ans++;
        if (uf.size(0) != N) ans++;
    }
    cout << ans << endl;
}
