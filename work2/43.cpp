#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <typename T, typename Graph>
pair<vector<T>, vector<int>> dijkstra(const Graph &G, int s) {
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
        for (auto [cost, nv] : G[v]) {
            T c = dv + cost;
            if (dis[nv] > c) {
                dis[nv] = c;
                q.emplace(dis[nv], nv);
                route[nv] = v;
            }
        }
    }
    return {dis, route};
}
template <typename T, typename Graph>
pair<vector<T>, vector<int>> BellmanFord(const Graph &G, int s) {
    int N = G.size(), loop = 0;
    vector<int> route(N, -1);
    vector<T> dis(N, inf<T>);
    dis[s] = 0;
    while (1) {
        ++loop;
        bool upd = 0;
        for (int v = 0; v < N; v++) {
            if (dis[v] == inf<T>) continue;
            for (auto [cost, nv] : G[v]) {
                T asis = dis[nv], tobe = dis[v] + cost;
                if (dis[v] == -inf<T>) tobe = -inf<T>;
                tobe = max(tobe, -inf<T>);
                if (asis > tobe) {
                    if (loop >= N) tobe = -inf<T>;
                    dis[nv] = tobe;
                    route[nv] = v;
                    upd = 1;
                }
            }
        }
        if (!upd) break;
    }
    return {dis, route};
}
int main() {
    auto [dis, route] = BellmanFord<long long>(G, 0);
    auto [dis, route] = dijkstra<long long>(G, start);
}
