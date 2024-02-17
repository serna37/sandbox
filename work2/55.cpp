#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <typename T> struct Edge {
    int from, to;
    T cost;
    int id;
};
template <typename T> using Graph = vector<vector<Edge<T>>>;
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
int main() {
    int N, M;
    cin >> N >> M;
    Graph<long long> G(N);
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        long long cost;
        cin >> cost;
        G[from].push_back({from, to, cost, i});
    }
    auto [dis, negaCy] = WarshallFroyd<long long>(G);
    if (negaCy) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    int sz = dis.size();
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (j) cout << " ";
            if (dis[i][j] == inf<long long>) {
                cout << "INF";
            } else {
                cout << dis[i][j];
            }
        }
        cout << endl;
    }
}
