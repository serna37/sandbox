#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
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
    int N, M;
    cin >> N >> M;
    vector<vector<pair<long long, int>>> G(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        long long C;
        cin >> A >> B >> C;
        A--, B--;
        G[A].push_back({-C, B});
    }
    auto [dis, route] = BellmanFord<long long>(G, 0);
    if (dis[N - 1] == -inf<long long>) {
        cout << "inf" << endl;
    } else {
        cout << -dis[N - 1] << endl;
    }
}
