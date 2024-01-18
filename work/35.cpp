#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K, X;
    cin >> N >> K >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long cnt = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        cnt += A[i] / X;
    }
    if (K <= cnt) {
        long long ans = sum - (long long)K * X;
        cout << ans << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        A[i] %= X;
    }
    sort(A.rbegin(), A.rend());
    long long M = min((long long)K - cnt, (long long)N);
    for (int i = 0; i < M; i++) {
        A[i] = 0;
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i];
    }
    cout << ans << endl;
}
