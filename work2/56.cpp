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
template <typename T = int> struct Edge {
    int from, to;
    T cost;
    int id;
    Edge(int from, int to, T cost = 1, int id = -1)
        : from(from), to(to), cost(cost), id(id){};
};
template <typename T> using Graph = vector<vector<Edge<T>>>;
template <typename T> struct MinSpanTree {
    T cost;
    vector<Edge<T>> edges;
};
template <typename T> MinSpanTree<T> kruskal(vector<Edge<T>> edges, int v_cnt) {
    sort(edges.begin(), edges.end(),
         [](const Edge<T> &a, const Edge<T> &b) { return a.cost < b.cost; });
    UnionFind tree(v_cnt);
    T total = T();
    vector<Edge<T>> es;
    for (auto &&e : edges) {
        if (tree.unite(e.from, e.to)) {
            es.emplace_back(e);
            total += e.cost;
        }
    }
    return {total, es};
}
int main() {
    int N, M;
    cin >> N >> M;
    Graph<long long> G(N);
    vector<Edge<long long>> es;
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        from--, to--;
        long long cost;
        cin >> cost;
        // G[from].push_back({from, to, cost, i});
        G[from].push_back({from, to});
        // G[to].push_back({to, from, cost, i});
        es.push_back({from, to, cost, i});
    }
    for (int i = 0; i < N; i++) {
        for (auto e : G[i]) {
            cout << e.from << e.to << e.cost << e.id << endl;
        }
    }
    MinSpanTree<long long> mst = kruskal(es, N);
    cout << mst.cost << endl;
    for (auto &&e : mst.edges) {
        cout << e.from << e.to << e.cost << e.id << endl;
    }
}
