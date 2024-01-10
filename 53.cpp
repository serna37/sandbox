#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<int> L(N + 1), R(N + 1);
    for (int i = 0; i < N; i++) {
        L[i + 1] = L[i] + (S[i] == 'W');
    }
    for (int i = N - 1; i >= 0; i--) {
        R[i] = R[i + 1] + (S[i] == 'E');
    }
    const int INF = 1001001001;
    int ans = INF;
    for (int i = 0; i < N; i++) {
        ans = min(ans, L[i] + R[i + 1]);
    }
    cout << ans << endl;
}
