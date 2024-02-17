#include <bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    queue<long long> q;
    int Q;
    cin >> Q;
    while (Q--) {
        long long n, x;
        cin >> n;
        if (n == 1) {
            cin >> x;
            q.push(x);
        } else if (n == 2) {
            if (pq.empty()) {
                pq.push(q.front());
                q.pop();
            }
            cout << pq.top() << endl;
            pq.pop();
        } else {
            while (!q.empty()) {
                pq.push(q.front());
                q.pop();
            }
        }
    }
}
