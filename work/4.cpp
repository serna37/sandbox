#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, D, K;
    cin >> N >> D >> K;
    vector<int> L(D), R(D), S(K), T(K);
    for (int i = 0; i < D; i++) {
        cin >> L[i] >> R[i];
    }
    for (int i = 0; i < K; i++) {
        cin >> S[i] >> T[i];
    }
    for (int i = 0; i < K; i++) {
        bool left = S[i] < T[i];
        int ans = 0;
        for (int j = 0; j < D; j++) {
            if (L[j] <= S[i] and S[i] <= R[j]) {
                if (left) {
                    S[i] = R[j];
                } else {
                    S[i] = L[j];
                }
            }
            if (left and S[i] >= T[i]) {
                ans = j + 1;
                break;
            }
            if (!left and S[i] <= T[i]) {
                ans = j + 1;
                break;
            }
        }
        cout << ans << endl;
    }
}
