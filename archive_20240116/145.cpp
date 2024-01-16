#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    long long P, Q, R;
    cin >> P >> Q >> R;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    bool anma = false;
    for (int i = 0; i < N + 1; i++) {
        long long x = S[i] + P;
        long long y = x + Q;
        long long z = y + R;
        bool ex = binary_search(S.begin(), S.end(), x);
        bool ey = binary_search(S.begin(), S.end(), y);
        bool ez = binary_search(S.begin(), S.end(), z);
        anma |= ex and ey and ez;
    }
    cout << (anma ? "Yes" : "No") << endl;
}
