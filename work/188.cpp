#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, D, K;
    cin >> N >> D >> K;
    vector<int> L(D), R(D);
    for (int i = 0; i < D; i++) {
        cin >> L[i] >> R[i];
    }
    vector<int> S(K), T(K);
    for (int i = 0; i < K; i++) {
        cin >> S[i] >> T[i];
    }
    for (int i = 0; i < K; i++) {
        bool right = S[i] <= T[i];
        for (int j = 0; j < D; j++) {
            if (right) {
                if (L[j] <= S[i] and S[i] <= R[j]) {
                    S[i] = R[j];
                }
                if (T[i] <= S[i]) {
                    cout << j + 1 << endl;
                    break;
                }
            } else {
                if (L[j] <= S[i] and S[i] <= R[j]) {
                    S[i] = L[j];
                }
                if (S[i] <= T[i]) {
                    cout << j + 1 << endl;
                    break;
                }
            }
        }
    }
}
