#include <bits/stdc++.h>
using namespace std;
template <typename T> struct Edge {
    int from, to;
    T cost;
    int id;
};
template <typename T> using Graph = vector<vector<Edge<T>>>;
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
int main() {
    int N, M;
    cin >> N >> M;
    Graph<long long> G(N);
    map<pair<int, int>, int> edges;
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;

        // 多重辺
        if (from > to) swap(from, to);
        if (edges.count({from, to})) {
            cout << 2 << endl;
            cout << from << " " << to << endl;
            cout << edges[{from, to}] << " " << i << endl;
            return 0;
        }
        edges[{from, to}] = i;

        G[from].push_back({from, to, 1, i});
        G[to].push_back({to, from, 1, i});
    }
    vector<Edge<long long>> res = cycle_detect(G, false);
    if (res.empty()) {
        cout << -1 << endl;
    } else {
        cout << res.size() << endl;
        for (auto e : res) cout << e.from << " ";
        cout << endl;
        for (auto e : res) cout << e.id << " ";
        cout << endl;
    }
}
