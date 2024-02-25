#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
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
template <typename T> struct Edge {
    int from, to;
    T cost;
    int id;
    Edge(int from, int to, T cost = 1, int id = -1)
        : from(from), to(to), cost(cost), id(id){};
};
template <typename T> using Graph = vector<vector<Edge<T>>>;
template <typename T>
pair<vector<T>, vector<int>> dijkstra(const Graph<T> &G, int s) {
    int N = G.size();
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(0, s);
    vector<T> dis(N, inf<T>);
    dis[s] = 0;
    vector<int> route(N, -1);
    while (!q.empty()) {
        auto [dv, v] = q.top();
        q.pop();
        if (dv > dis[v]) continue;
        for (auto [from, to, cost, id] : G[v]) {
            T c = dv + cost;
            if (dis[to] > c) {
                dis[to] = c;
                q.emplace(dis[to], to);
                route[to] = v;
            }
        }
    }
    return {dis, route};
}
template <typename T>
pair<vector<T>, vector<int>> BellmanFord(const Graph<T> &G, int s) {
    int N = G.size(), loop = 0;
    vector<int> route(N, -1);
    vector<T> dis(N, inf<T>);
    dis[s] = 0;
    while (1) {
        ++loop;
        bool upd = 0;
        for (int v = 0; v < N; v++) {
            if (dis[v] == inf<T>) continue;
            for (auto [from, to, cost, id] : G[v]) {
                T asis = dis[to], tobe = dis[v] + cost;
                if (dis[v] == -inf<T>) tobe = -inf<T>;
                tobe = max(tobe, -inf<T>);
                if (asis > tobe) {
                    if (loop >= N) tobe = -inf<T>;
                    dis[to] = tobe;
                    route[to] = v;
                    upd = 1;
                }
            }
        }
        if (!upd) break;
    }
    return {dis, route};
}
vector<int> route_restore(const vector<int> &route, int goal) {
    vector<int> pth = {goal};
    while (route[pth.back()] != -1) pth.emplace_back(route[pth.back()]);
    reverse(pth.begin(), pth.end());
    return pth;
}
template <typename T>
vector<Edge<T>> cycle_detect(const Graph<T> &G, bool directed) {
    int sz = G.size();
    vector<bool> seen(sz), finished(sz);
    vector<Edge<T>> history;
    auto dfs = [&](auto f, int v, const Edge<T> &e) -> int {
        seen[v] = true;
        history.push_back(e);
        for (const auto &ne : G[v]) {
            auto [from, to, id, cost] = ne;
            if (!directed and to == e.from) continue;
            if (finished[to]) continue;
            if (seen[to] and !finished[to]) {
                history.push_back(ne);
                return to;
            }
            int pos = f(f, to, ne);
            if (pos != -1) return pos;
        }
        finished[v] = true;
        history.pop_back();
        return -1;
    };
    auto restruct = [&](int pos) -> vector<Edge<T>> {
        vector<Edge<T>> cycle;
        while (!history.empty()) {
            const Edge<T> &e = history.back();
            cycle.push_back(e);
            history.pop_back();
            if (e.from == pos) break;
        }
        reverse(cycle.begin(), cycle.end());
        return cycle;
    };
    int pos = -1;
    for (int v = 0; v < sz and pos == -1; ++v) {
        if (seen[v]) continue;
        history.clear();
        pos = dfs(dfs, v, Edge<T>({-1, -1, -1, -1}));
        if (pos != -1) return restruct(pos);
    }
    return vector<Edge<T>>();
}
template <typename T>
pair<vector<vector<T>>, bool> WarshallFroyd(const Graph<T> &G) {
    int N = G.size();
    vector<vector<T>> dis(N, vector<T>(N, inf<T>));
    for (int v = 0; v < N; v++) {
        dis[v][v] = 0;
        for (auto [from, to, cost, id] : G[v]) {
            dis[v][to] = min(dis[v][to], cost);
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (dis[i][k] == inf<T>) continue;
            for (int j = 0; j < N; j++) {
                if (dis[k][j] == inf<T>) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    bool negativeCycle = false;
    for (int i = 0; i < N; i++) {
        if (dis[i][i] < 0) {
            negativeCycle = true;
            break;
        }
    }
    return {dis, negativeCycle};
}
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
    vector<Edge<long long>> edges;
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        from--, to--;
        long long cost;
        cin >> cost;
        G[from].push_back({from, to, cost, i});
        G[to].push_back({to, from, cost, i});
        edges.push_back({from, to, cost, i});
    }
    auto [dis, route] = dijkstra<long long>(G, 0);
    auto [dis2, route2] = BellmanFord<long long>(G, 0);
    vector<int> rt = route_restore(route, N - 1);
    vector<Edge<long long>> res = cycle_detect(G, true);
    auto [dis3, negaCy] = WarshallFroyd<long long>(G);
    MinSpanTree<long long> mst = kruskal(edges, N);
}
