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
    int N;
    cin >> N;
    vector<vector<pair<long long, int>>> G(N);
    for (int i = 0; i < N - 1; i++) {
        long long A, B;
        int X;
        cin >> A >> B >> X;
        X--;
        G[i].push_back({A, i + 1});
        G[i].push_back({B, X});
    }
    auto [dis, route] = dijkstra<long long>(G, 0);
    cout << dis[N - 1] << endl;
}
