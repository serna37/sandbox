#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> S(N + 1), B(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
        B[i + 1] = B[i] + (long long)i * A[i];
    }
    const long long INF = 1001001001001001001ll;
    long long ans = -INF;
    for (int i = 0; i < N - M + 1; i++) {
        ans = max(ans, B[i + M] - B[i] + (i - 1) * (S[i + M] - S[i]));
    }
}
