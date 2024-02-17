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
    dp[0] = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            dp[min(i + A[j], H)] = min(dp[min(i + A[j], H)], dp[i] + B[j]);
        }
    }
    cout << dp[H] << endl;
}
