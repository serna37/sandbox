#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    const int INF = 1001001001;
    vector<int> dp(H + 1, INF);
    dp[H] = 0;
    for (int i = 0; i < N; i++) {
        for (int h = H; h >= 0; h--) {
            dp[h] = min(dp[h], dp[min(h + A[i], H)] + B[i]);
        }
    }
    cout << dp[0] << endl;
}
