#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> dp(K + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= K; i++) {
        if (dp[i] == 0) continue;
        for (int j = 0; j < N; j++) {
            if (i + A[j] <= K) {
                dp[i + A[j]] = 1;
            }
        }
    }
    cout << "debug_dp:";                // TODO debug
    for (auto v : dp) cout << " " << v; // TODO debug
    cout << endl;                       // TODO debug
    cout << dp[K] << endl;
}
