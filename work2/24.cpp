#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> c(M);
    for (int i = 0; i < M; i++) {
        cin >> c[i];
    }
    vector<int> dp(N + 1, inf<int>);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int a = i + c[j];
            if (a <= N) {
                dp[a] = min(dp[a], dp[i] + 1);
            }
        }
    }
    cout << dp[N] << endl;
}
