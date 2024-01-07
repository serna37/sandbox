#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
    int N;
    string S1, S2;
    cin >> N >> S1 >> S2;
    string S;
    for (int i = 0; i < N; i++) {
        if (S1[i] == S2[i]) {
            S += 'a';
        } else {
            S += 'b';
            i++;
        }
    }
    int M = S.size();
    long long ans = 1;
    if (S[0] == 'a') {
        ans = 3;
    } else {
        ans = 6;
    }
    for (int i = 1; i < M; i++) {
        if (S[i - 1] == 'a') {
            ans *= 2;
        } else if (S[i] == 'b') {
            ans *= 3;
        }
        ans %= MOD;
    }
    cout << ans << endl;
}
