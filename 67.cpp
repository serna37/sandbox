#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += S.end() - lower_bound(S.begin(), S.end(), S[i] + K);
    }
    cout << ans << endl;
}
