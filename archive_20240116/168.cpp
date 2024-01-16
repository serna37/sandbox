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
    vector<priority_queue<int>> q;
    for (int i = 0; i < N; i++) {
        int mintop = INF, idx = -1;
        for (int ii = 0; ii < (int)q.size(); ii++) {
            int t = -q[ii].top();
            if (t >= w[i] and mintop > t) {
                mintop = t;
                idx = ii;
            }
        }
        if (idx == -1) {
            priority_queue<int> tmp;
            tmp.push(-w[i]);
            q.push_back(tmp);
        } else {
            q[idx].push(-w[i]);
        }
    }
    cout << q.size() << endl;
}
