#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long ans = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        ans += (N - 1) * A[i] * A[i];
        sum += A[i];
    }
    for (int i = 0; i < N; i++) {
        ans -= A[i] * (sum - A[i]);
    }
    cout << ans << endl;
}
