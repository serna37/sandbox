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
    vector<priority_queue<int>> ans(1);
    ans[0].push(-w[0]);
    for (int i = 1; i < N; i++) {
        int tmp = -1;
        int diff = INF;
        for (int id = 0; id < (int)ans.size(); id++) {
            priority_queue<int> q = ans[id];
            if (-q.top() >= w[i]) {
                int d = min(diff, -q.top() - w[i]);
                if (d < diff) {
                    tmp = id;
                }
            }
        }
        if (tmp == -1) {
            priority_queue<int> nq;
            nq.push(-w[i]);
            ans.push_back(nq);
        } else {
            ans[tmp].push(-w[i]);
        }
    }
    cout << ans.size() << endl;
}
