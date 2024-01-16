#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    vector<vector<int>> G(N);
    queue<int> q;
    while (!q.empty()) {
        auto a = q.front();
        q.pop();
        for (int v : G[a]) {
            q.push(v);
        }
    }
}
