#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    vector<int> dp(H + 1, INF);
    dp[H] = 0;
    for (int i = H; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            dp[i] = min(dp[i], dp[min(i + A[j], H)] + B[j]);
        }
    }
    cout << dp[0] << endl;
}
