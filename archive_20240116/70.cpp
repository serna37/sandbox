#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 10;
    vector<int> A(N);
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        S[i] = S[i + 1] + A[i];
    }

    vector<long long> L(N + 1);
    for (int i = 0; i < N; i++) {
        L[i + 1] = L[i] + A[i];
    }
    vector<long long> R(N + 1);
    for (int i = N - 1; i >= 0; i--) {
        R[i] = R[i + 1] + A[i];
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += lower_bound(S.begin(), S.end(), S[i]) - S.begin();
    }
    cout << ans << endl;
    for (int bit = 0; bit < 1 << N; bit++) {
        long long tmp = 0;
        for (int k = 0; k < N; k++) {
            if (N & (1ll << k)) {
                tmp |= A[k];
            }
        }
    }
    for (int bit = 0; bit < 1 << N; bit++) {
        long long tmp = 0;
        for (int k = 0; k < N; k++) {
            if (N & (1ll << k)) {
                tmp |= A[k];
            }
        }
    }
    vector<long long> LL(N + 1);
    for (int i = 0; i < N; i++) {
        LL[i + 1] = LL[i] + A[i];
    }
    vector<long long> RR(N + 1);
    for (int i = N - 1; i >= 0; i--) {
        RR[i] = RR[i + 1] + A[i];
    }
    for (int i = 0; i < N; i++) {
        ans += lower_bound(A.begin(), A.end(), A[i]) - A.begin();
    }
    int ans = 0;
    int r = 0;
    for (int l = 0; l < N; l++) {
        while (r < N and A[r] == A[l]}) {
            ++r;
        }
        ans = max(ans, r - l);
    }   
}
