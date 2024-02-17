#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S1, S2;
    cin >> N >> S1 >> S2;
    vector<int> D;
    for (int i = 0; i < N; i++) {
        if (S1[i] == S2[i]) {
            D.push_back(1);
        } else {
            D.push_back(2);
            i++;
        }
    };
    int M = D.size();
    const long long MOD = 1000000007;
    long long ans = 1;
    if (D[0] == 1) {
        ans *= 3;
    } else {
        ans *= 6;
    }
    for (int i = 1; i < M; i++) {
        if (D[i - 1] == 1) {
            ans *= 2;
        } else if (D[i] == 2) {
            ans *= 3;
        };
        ans %= MOD;
    }
    cout << ans << endl;
}
