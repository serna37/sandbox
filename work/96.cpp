#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, P, Q, R;
    cin >> N >> P >> Q >> R;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    for (int i = 0; i < N + 1; i++) {
        long long y = S[i] + P;
        long long z = y + Q;
        long long w = z + R;
        bool ye = binary_search(S.begin(), S.end(), y);
        bool ze = binary_search(S.begin(), S.end(), z);
        bool we = binary_search(S.begin(), S.end(), w);
        if (ye and ze and we) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
