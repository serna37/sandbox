#include <bits/stdc++.h>
using namespace std;
// TODO 閉路 なおすぞ
template <typename T> struct Edge {
    int from, to;
    T cost;
    int id;
    Edge(int f = -1, int t = -1, T cost = -1, int id = -1)
        : from(f), to(t), cost(cost), id(id){};
};
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<Edge<int>>> G(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        // A--, B--;
        G[A].push_back({A, B, 1, i});
        // G[B].push_back(A);
    }
    vector<bool> go(N, 0), back(N, 0);
    stack<Edge<int>> history;
    auto dfs = [&](auto f, Edge<int> &e) -> int {
        go[e.to] = 1;
        history.push(e);
        for (auto e : G[e.to]) {
            if (back[e.to]) continue;
            if (go[e.to] and !back[e.to]) {
                history.push(e);
                return e.to;
            }
            int pos = f(f, e);
            if (pos != -1) return pos;
        }
        back[e.to] = 1;
        history.pop();
        return -1;
    };
    auto restruct = [&](int pos) -> vector<Edge<int>> {
        vector<Edge<int>> route;
        while (!history.empty()) {
            auto e = history.top();
            route.push_back(e);
            history.pop();
            if (e.from == pos) break;
        }
        reverse(route.begin(), route.end());
        return route;
    };
    auto detect = [&]() -> vector<Edge<int>> {
        int pos = -1, sz = G.size();
        for (int v = 0; v < sz and pos == -1; v++) {
            if (go[v]) continue;
            history = stack<Edge<int>>();
            Edge<int> e(0, 0, 0, 0);
            pos = dfs(dfs, e);
            if (pos != -1) return restruct(pos);
        }
        return {};
    };
    auto test = detect();
    if (test.empty()) {
        cout << -1 << endl;
    } else {
        cout << test.size() << endl;
        for (auto &e : test) {
            cout << e.id << endl;
        }
    }
}
