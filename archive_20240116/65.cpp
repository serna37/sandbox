#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long > a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<long long > x(Q);
    for (int i = 0; i < Q; i++) {
        cin >> x[i];
    }
    vector<long long > S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + a[i];
    }
    for (int q = 0; q < Q; q++) {
        long long  ans = 0;
        for (int l = 0; l <= N; l++) {
            int r =
                upper_bound(S.begin(), S.end(), S[l] + x[q]) - S.begin() - 1;
            ans += r - l;
        }
        cout << ans << endl;
    }
}
