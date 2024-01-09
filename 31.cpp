#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N;
    cin >> N;
    vector<int> w(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    vector<priority_queue<int>> p;
    p[0].push(-w[0]);
    for (int i = 1; i < N; i++) {
        int tmp = INF;
        int idx = -1;
        for (int v = 0; v < (int)p.size(); v++) {
            auto t = p[v].top() * (-1);
            int tt = min(tmp, abs(t - w[i]));
            if (tt < tmp) {
                tmp = tt;
                idx = v;
            }
        }
        if (idx == -1) {
            priority_queue<int> nn;
            nn.push(-w[i]);
            p.push_back(nn);
        } else {
            p[idx].push(-w[i]);
        }
    }
    cout << p.size() << endl;
}
