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
    for (int i = 1; i <= N; i++) {
        long long ans = 0;
        for (int j = 0; j < N; j++) {
            ans = max(ans, S[i + j] - S[j]);
        }
        cout << ans << endl;
    }
}
