#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    vector<double> E(N);
    for (int i = 0; i < N; i++) {
        E[i] = (1.0 + p[i]) / 2;
    }
    vector<double> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + E[i];
    }
    double ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, S[i + K] - S[i]);
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
}
