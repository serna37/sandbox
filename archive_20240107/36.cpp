#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    vector<double> pE(N);
    for (int i = 0; i < N; i++) {
        pE[i] = (1.0 + p[i]) / 2;
    }
    vector<double> sum(N + 1);
    for (int i = 0; i < N; i++) {
        sum[i + 1] = sum[i] + pE[i];
    }
    double ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, sum[i + K] - sum[i]);
    }
    cout << fixed << setprecision(20);
    cout << ans << endl;
}
