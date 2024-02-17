#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + a[i];
    }
    long long ans = 0;
    for (int i = 0; i < N + 1; i++) {
        auto itr = lower_bound(S.begin(), S.end(), S[i] + K);
        if (itr != S.end()) {
            ans += S.end() - itr;
        }
    }
    cout << ans << endl;
}
