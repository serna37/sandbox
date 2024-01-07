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
    vector<priority_queue<int>> p(1);
    p[0].push(-w[0]);
    for (int i = 1; i < N; i++) {
        int m = INF;
        int tmp = -1;
        for (int ii = 0; ii < (int)p.size(); ii++) {
            int top = p[ii].top();
            if (-top >= w[i] and m > abs(top - w[i])) {
                m = abs(top - w[i]);
                tmp = ii;
            }
        }
        if (tmp == -1) {
            priority_queue<int> n;
            n.push(-w[i]);
            p.push_back(n);
        } else {
            p[tmp].push(-w[i]);
        }
    }
    cout << p.size() << endl;
}
