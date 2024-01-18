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
    for (int i = 0; i < N; i++) {
        int M = p.size();
        int mn = INF;
        int idx = -1;
        for (int j = 0; j < M; j++) {
            int tmp = -p[j].top();
            if (w[i] <= tmp) {
                if (mn > tmp) {
                    mn = tmp;
                    idx = j;
                }
            }
        }
        if (idx == -1) {
            priority_queue<int> tmp;
            tmp.push(-w[i]);
            p.push_back(tmp);
        } else {
            p[idx].push(-w[i]);
        }
    }
    cout << p.size() << endl;
}
