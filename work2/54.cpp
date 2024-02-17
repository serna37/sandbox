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
vector<int> route_restore(const vector<int> &route, int goal) {
    vector<int> pth = {goal};
    while (route[pth.back()] != -1) pth.emplace_back(route[pth.back()]);
    reverse(pth.begin(), pth.end());
    return pth;
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
template <typename T> vector<vector<T>> WarshallFroyd(const Graph<T> &G) {
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
    return dis;
}
int main() {
    int N, M;
    cin >> N >> M;
    Graph<long long> G(N);
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        from--, to--;
        long long cost;
        cin >> cost;
        G[from].push_back({from, to, cost, i});
    }
    auto [dis, route] = dijkstra<long long>(G, 0);
    auto [dis2, route2] = BellmanFord<long long>(G, 0);
    auto dis3 = WarshallFroyd<long long>(G);
    vector<int> rt = route_restore(route, N - 1);
    cout << dis3[0][3] << endl;
}
