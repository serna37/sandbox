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
    vector<long long> S(N + 1), B(N + 1);
    for (int i = 0; i < N; i++) {
        B[i + 1] = B[i] + A[i];
        S[i + 1] = S[i] + (long long)A[i] * i;
    }
    long long ans = -INF;
    for (int i = 0; i < N - M + 1; i++) {
        ans = max(ans, S[i + M] - S[i] + (B[i + M] - B[i]) * (1 - i));
    }
    cout << ans << endl;
}
