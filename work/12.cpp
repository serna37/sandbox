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
    for (int i = 0; i < N + 1; i++) {
        long long x = S[i];
        long long y = x + P;
        long long z = y + Q;
        long long w = z + R;
        bool ey = binary_search(S.begin(), S.end(), y);
        bool ez = binary_search(S.begin(), S.end(), z);
        bool ew = binary_search(S.begin(), S.end(), w);
        if (ey and ez and ew) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
