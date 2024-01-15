#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> w(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    vector<priority_queue<int>> qs;
    const int INF = 1001001001;
    for (int i = 0; i < N; i++) {
        int now = w[i];
        int mintop = INF;
        int idx = -1;
        for (int ii = 0; ii < (int)qs.size(); ii++) {
            int top = -qs[ii].top();
            if (now <= top and mintop > top) {
                mintop = top;
                idx = ii;
            }
        }
        if (idx == -1) {
            priority_queue<int> nq;
            nq.push(-now);
            qs.push_back(nq);
        } else {
            qs[idx].push(-now);
        }
    }
    cout << qs.size() << endl;
}
