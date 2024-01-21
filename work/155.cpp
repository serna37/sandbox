#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> Z(N + 1), S(N + 1);
    for (int i = 0; i < N; i++) {
        Z[i + 1] = Z[i] + A[i];
        S[i + 1] = S[i] + (long long)A[i] * i;
    }
    long long ans = -INF;
    for (int i = 0; i < N - M + 1; i++) {
        long long tmp = S[i + M] - S[i] - (Z[i + M] - Z[i]) * (i - 1);
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
