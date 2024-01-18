#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K, X;
    cin >> N >> K >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long c = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        c += A[i] / X;
    }
    if (K <= c) {
        long long ans = sum - (long long)K * X;
        cout << ans << endl;
        return 0;
    }
    K -= c;
    for (int i = 0; i < N; i++) {
        A[i] %= X;
    }
    sort(A.rbegin(), A.rend());
    for (int i = 0; i < min(K, N); i++) {
        A[i] = 0;
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i];
    }
    cout << ans << endl;
}
