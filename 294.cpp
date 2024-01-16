#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> S1(N + 1), S2(N + 1);
    for (int i = 0; i < N; i++) {
        S1[i + 1] = S1[i] + A[i];
        S2[i + 1] = S2[i] + (long long)i * A[i];
    }
    const long long INF = 1001001001001001001ll;
    long long ans = -INF;
    for (int i = 0; i < N - M + 1; i++) {
        ans = max(ans, S2[i + M] - S2[i] + (1 - i) * (S1[i + M] - S1[i]));
    }
    cout << ans << endl;
}
