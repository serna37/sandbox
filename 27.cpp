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
    vector<long long> s1(N + 1), s2(N + 1);
    for (int i = 0; i < N; i++) {
        s1[i + 1] = s1[i] + A[i];
        s2[i + 1] = s2[i] + (long long)i * A[i];
    }
    long long ans = -INF;
    for (int i = 0; i < N - M + 1; i++) {
        ans = max(ans, s2[i + M] - s2[i] + (s1[i + M] - s1[i]) * (1 - i));
    }
    cout << ans << endl;
}
