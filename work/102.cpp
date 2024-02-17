#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    stack<pair<int, int>> sta;
    for (int i = 0; i < N; i++) {
        if (sta.empty()) {
            sta.push({a[i], 1});
            cout << 1 << endl;
            continue;
        }
        pair<int, int> c = sta.top();
        if (c.first == a[i]) {
            if (c.second == a[i] - 1) {
                for (int j = 0; j < c.second; j++) {
                    sta.pop();
                }
            } else {
                sta.push({a[i], c.second + 1});
            }
        } else {
            sta.push({a[i], 1});
        }
        cout << sta.size() << endl;
    }
}
