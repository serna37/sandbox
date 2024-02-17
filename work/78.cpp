#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    vector<int> dp(N, INF);
    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            if (i - j < 0) {
                break;
            }
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }
    cout << dp[N - 1] << endl;
}
