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
        for (auto [cost, nv, i] : G[v]) {
            T c = dv + cost;
            if (dis[nv] > c) {
                dis[nv] = c;
                q.emplace(dis[nv], nv);
                route[nv] = i;
            }
        }
    }
    return {dis, route};
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<tuple<long long, int, int>>> G(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        long long C;
        cin >> A >> B >> C;
        A--, B--;
        G[A].push_back({C, B, i});
        G[B].push_back({C, A, i});
    }
    auto [dis, route] = dijkstra<long long>(G, 0);
    int sz = route.size();
    for (int i = 1; i < sz; i++) {
        if (i != 1) cout << " ";
        cout << route[i] + 1;
    }
    cout << endl;
}
