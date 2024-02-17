#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    vector<pair<int, int>> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        X[i] = {x[i], i};
        Y[i] = {y[i], i};
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    int top, down;
    if (X.back().first - X.front().first > Y.back().first - Y.front().first) {
        top = X.back().second;
        down = X.front().second;
    } else {
        top = Y.back().second;
        down = Y.front().second;
    }
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 and j != top) {
                ans = max(ans, abs(x[down] - x[j]));
                ans = max(ans, abs(y[down] - y[j]));
            }
            if (i == 1 and j != down) {
                ans = max(ans, abs(x[top] - x[j]));
                ans = max(ans, abs(y[top] - y[j]));
            }
        }
    }
    cout << ans << endl;
}
