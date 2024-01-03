#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K, X;
    cin >> N >> K >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long sum = 0, canuse = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        canuse += A[i] / X;
    }
    if (canuse <= K) {
        cout << sum - (long long)K * X << endl;
        return 0;
    }
    K -= canuse;
    for (int i = 0; i < N; i++) {
        A[i] %= X;
    }
    sort(A.rbegin(), A.rend());
    for (int i = 0; i < min(N, K); i++) {
        A[i] = 0;
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i];
    }
    cout << ans << endl;
}
