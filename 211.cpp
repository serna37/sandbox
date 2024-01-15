#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> w(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    vector<priority_queue<int>> q;
    const int INF = 1001001001;
    for (int i = 0; i < N; i++) {
        int idx = -1;
        int mt = INF;
        for (int ii = 0; ii < (int)q.size(); ii++) {
            int tmp = -q[ii].top();
            if (tmp >= w[i] and mt > tmp) {
                mt = tmp;
                idx = ii;
            }
        }
        if (idx == -1) {
            priority_queue<int> nn;
            nn.push(-w[i]);
            q.push_back(nn);
        } else {
            q[idx].push(-w[i]);
        }
    }
    cout << q.size() << endl;
}
