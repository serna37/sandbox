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
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
        }
    }
    cout << dp[N - 1] << endl;
}
