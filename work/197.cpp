#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    vector<pair<int, int>> X, Y;
    for (int i = 0; i < N; i++) {
        X.push_back({x[i], i});
        Y.push_back({y[i], i});
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    int top = 0, down = 0;
    bool xy =
        X.back().first - X.front().first > Y.back().first - Y.front().first;
    top = xy ? X.back().second : Y.back().second;
    down = xy ? X.front().second : Y.front().second;
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 and j != top) {
                ans = max(ans, max(abs(x[down] - x[j]), abs(y[down] - y[j])));
            }
            if (i == 1 and j != down) {
                ans = max(ans, max(abs(x[top] - x[j]), abs(y[top] - y[j])));
            }
        }
    }
    cout << ans << endl;
}
