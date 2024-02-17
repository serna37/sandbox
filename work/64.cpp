#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }
    vector<int> dp(N + 1, INF);
    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (1 <= i - j) {
                dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
            }
        }
    }
    cout << dp[N] << endl;
}
