#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    vector<double> e(N);
    for (int i = 0; i < N; i++) {
        e[i] = (1.0 + p[i]) / 2;
    }
    vector<double> Z(N + 1);
    for (int i = 0; i < N; i++) {
        Z[i + 1] = Z[i] + e[i];
    }
    double ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, Z[i + K] - Z[i]);
    }
    cout << ans << endl;
}
