#include <bits/stdc++.h>
using namespace std;
template <typename T> struct Edge {
    int from, to;
    T cost;
    int id;
};
template <typename T> using Graph = vector<vector<Edge<T>>>;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
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
template <typename STRING = string, typename CHAR = char>
vector<pair<CHAR, int>> run_length(STRING &S) {
    vector<pair<CHAR, int>> res;
    for (auto &&x : S) {
        if (res.empty() or res.back().first != x) {
            res.emplace_back(x, 0);
        }
        res.back().second++;
    }
    return res;
}
auto zip = []<class T>(vector<T> a) -> pair<vector<T>, vector<T>> {
    vector<T> c = a;
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for (auto &v : a) v = lower_bound(c.begin(), c.end(), v) - c.begin();
    return {a, c};
};
int main() {
    auto [dis, route] = dijkstra<long long>(G, start);
    auto [dis, route] = BellmanFord<long long>(G, start);
    vector<Edge<long long>> res = cycle_detect(G, true);
}
