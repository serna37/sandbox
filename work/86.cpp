#include <bits/stdc++.h>
using namespace std;
const long long INF = 1001001001001001001ll;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> S(N + 1), S2(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
        S2[i + 1] = S2[i] + (long long)(i + 1) * A[i];
    }
    long long ans = -INF;
    for (int i = 0; i < N - M + 1; i++) {
        ans = max(ans, S2[i + M] - S2[i] - (S[i + M] - S[i]) * i);
    }
    cout << ans << endl;
}
