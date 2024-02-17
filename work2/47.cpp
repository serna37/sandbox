#include <bits/stdc++.h>
using namespace std;
// TODO グラフ構造を考えて、ダイクストラで試してみてる
template <typename T> using Edge = tuple<T, int, int>;
template <typename T> using Graph = vector<vector<Edge<T>>>;
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
        G[from].push_back({cost, to, i});
        G[to].push_back({cost, from, i});
    }
}

//}
// template <typename T> struct Edge {
// int from, to;
// T cost;
// int id;
//};
// template <typename T = int, bool directed = false> struct Graph {
// static constexpr bool is_directed = directed;
// using cost_type = T;
// using edge_type = Edge<T>;
// vector<vector<edge_type>> g;
// int N, M;
// Graph(int N) : N(N) {
// g.resize(N);
//};
// int size() const {
// return N;
// vector<edge_type> operator[](int i) const {
// return g[i];
//}
// void add(int from, int to, T cost = 1, int i = -1) {
// if (i == -1) i = M++;
// auto e = edge_type({from, to, cost, i});
// g[from].push_back(e);
//}
// void debug() {
// for (int i = 0; i < N; i++) {
// for (auto e : g[i]) {
// cout << "==" << e.id << "==cost:" << e.cost;
// cout << " " << e.from << "->" << e.to << endl;
//}
//}
//}
//};
// template <class T> constexpr T inf = 0;
// template <> constexpr int inf<int> = 1001001001;
// template <> constexpr long long inf<long long> = 1001001001001001001ll;
// template <typename T, typename Graph>
// pair<vector<T>, vector<int>> dijkstra(const Graph &G, int s) {
// int N = G.size();
// using P = pair<T, int>;
// priority_queue<P, vector<P>, greater<P>> q;
// q.emplace(0, s);
// vector<T> dis(N, inf<T>);
// dis[s] = 0;
// vector<int> route(N, -1);
// while (!q.empty()) {
// auto [dv, v] = q.top();
// q.pop();
// if (dv > dis[v]) continue;
// for (auto [fr, to, cost, idx] : G[v]) {
// T c = dv + cost;
// if (dis[to] > c) {
// dis[to] = c;
// q.emplace(dis[to], to);
// route[to] = v;
//}
//}
//}
// return {dis, route};
//}
// int main() {
// int N, M;
// cin >> N >> M;
// Graph<long long, true> G(N);
// for (int i = 0; i < M; i++) {
// int A, B;
// long long C;
// cin >> A >> B >> C;
// A--, B--;
// G.add(A, B, C, i);
//}
//// G.debug();
// auto [dis, route] = dijkstra<long long>(G, 0);
// int sz = route.size();
// for (int i = 1; i < sz; i++) {
// if (i != 1) cout << " ";
// cout << route[i] + 1;
//}
// cout << endl;
//}
