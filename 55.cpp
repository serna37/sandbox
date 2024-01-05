#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<int> cnt(N, 2);
    for (int i = 0; i < K; i++) {
        cnt[A[i]]--;
    }
    vector<int> S;
    for (int i = 0; i < N; i++) {
        for (int ii = 0; ii < cnt[i]; ii++) {
            S.push_back(i);
        }
    }
    int M = S.size();
    if (M % 2 == 0) {
        int ans = 0;
        for (int i = 0; i < M / 2; i++) {
            ans += abs(S[i * 2] - S[i * 2 + 1]);
        }
        cout << ans << endl;
    } else {
        int m = M / 2;
        vector<int> L(m + 1), R(m + 1);
        for (int i = 0; i < m; i++) {
            L[i + 1] = L[i] + abs(S[i * 2] - S[i * 2 + 1]);
        }
        for (int i = m - 1; i >= 0; i--) {
            R[i] = R[i + 1] + abs(S[i * 2 + 1] - S[i * 2 + 2]);
        }
        int ans = INF;
        for (int i = 0; i < m; i++) {
            ans = min(ans, L[i] + R[i]);
        }
        cout << ans << endl;
    }
}
