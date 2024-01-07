#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i] * A[i] * (N - 1);
        sum += A[i];
    }
    for (int i = 0; i < N; i++) {
        ans -= (sum - A[i]) * A[i];
    }
    cout << ans << endl;
}
