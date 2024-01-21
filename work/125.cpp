#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<int> Z(N + 1);
    for (int i = 0; i < N; i++) {
        Z[i + 1] = Z[i] + (S[i] == 'W');
    }
    vector<int> R(N + 1);
    for (int i = N - 1; i >= 0; i--) {
        R[i] = R[i + 1] + (S[i] == 'E');
    }
    const int INF = 1001001001;
    int ans = INF;
    for (int i = 0; i < N; i++) {
        ans = min(ans, Z[i] + R[i + 1]);
    }
    cout << ans << endl;
}
