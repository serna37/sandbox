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
        for (auto &&n : G[v]) {
            int cost = n.first, nv = n.second;
            if (dis[nv] > dis[v] + cost) {
                dis[nv] = dis[v] + cost;
                q.emplace(dis[nv], nv);
                route[nv] = v;
            }
        }
    }
    return {dis, route};
}
int main() {
    int N, M;
    cin >> N >> M;
    int r;
    cin >> r;
    vector<vector<pair<int, int>>> G(N);
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        G[A].push_back({C, B});
    }
    auto [dist, route] = dijkstra<int>(G, r);
    for (auto &v : dist) {
        if (v == inf<int>) {
            cout << "INF" << endl;
        } else {
            cout << v << endl;
        }
    }
}
