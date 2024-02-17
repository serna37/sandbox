#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
int main() {
    int N;
    cin >> N;
    vector<int> h(N + 1);
    for (int i = 1; i < N + 1; i++) {
        cin >> h[i];
    }
    vector<int> dp(N + 1);
    dp[1] = 0;
    dp[2] = abs(h[1] - h[2]);
    for (int i = 3; i <= N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                    dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[N] << endl;
}
