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
    vector<long long> sum(N + 1), s2(N + 1);
    for (int i = 0; i < N; i++) {
        sum[i + 1] = sum[i] + A[i];
        s2[i + 1] = s2[i] + (long long)i * A[i];
    }
    long long ans = -INF;
    for (int i = 0; i < N; i++) {
        ans = max(ans, s2[i + M] - s2[i] + (1 - i) * (sum[i + M] - sum[i]));
    }
    cout << ans << endl;
}
