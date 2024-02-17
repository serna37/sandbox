#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    long long P, Q, R;
    cin >> N >> P >> Q >> R;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    for (int x = 0; x < N + 1; x++) {
        long long y = S[x] + P;
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
