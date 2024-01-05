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
    vector<double> pE(N);
    for (int i = 0; i < N; i++) {
        pE[i] = 1.0 * (1 + p[i]) / 2;
    }
    vector<double> rui(N);
    for (int i = 0; i < N; i++) {
        rui[i + 1] = rui[i] + pE[i];
    }
    double ans = 0;
    for (int i = 0; i < N - K; i++) {
        ans = max(ans, rui[i + K] - rui[i]);
    }
    cout << ans << endl;
}
