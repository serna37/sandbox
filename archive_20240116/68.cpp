#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long> a(N);
    vector<long long> x(Q);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < Q; i++) {
        cin >> x[i];
    }
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + a[i];
    }
    for (int i = 0; i < Q; i++) {
        long long ans = 0;
        for (int l = 0; l < N; l++) {
            int r =
                upper_bound(S.begin(), S.end(), S[l] + x[i]) - S.begin() - 1;
            ans += r - l;
        }
        cout << ans << endl;
    }
}
