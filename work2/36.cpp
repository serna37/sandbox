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
        for (auto [cost, ti, nv] : G[v]) {
            T c = (dv + ti - 1) / ti * ti + cost;
            if (dis[nv] > c) {
                dis[nv] = c;
                q.emplace(dis[nv], nv);
                route[nv] = v;
            }
        }
    }
    return {dis, route};
}
int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    X--, Y--;
    vector<vector<tuple<long long, long long, int>>> G(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        long long T, K;
        cin >> A >> B >> T >> K;
        A--, B--;
        G[A].push_back({T, K, B});
        G[B].push_back({T, K, A});
    }
    auto [dis, route] = dijkstra<long long>(G, X);
    if (dis[Y] == inf<long long>) {
        cout << -1 << endl;
    } else {
        cout << dis[Y] << endl;
    }
}
