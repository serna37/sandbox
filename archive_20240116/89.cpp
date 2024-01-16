#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    long long ans = 0;
    for (int k = 1; k <= N; k++) {
        for (int i = 0; i + k <= N; i++) {
            ans = max(ans, S[i + k] - S[i]);
        }
        cout << ans << endl;
    }
}
