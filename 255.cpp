#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long S = 0;
    for (int i = 0; i < N; i++) {
        S += A[i];
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += (N - 1) * A[i] * A[i] - A[i] * (S - A[i]);
    }
    cout << ans << endl;
}
