#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    string S1, S2;
    cin >> S1 >> S2;
    const long long MOD = 1000000007;
    vector<int> S;
    for (int i = 0; i < N; i++) {
        if (S1[i] == S2[i]) {
            S.push_back(1);
        } else {
            S.push_back(0);
            i++;
        }
    }
    long long ans = 3;
    if (S[0] == 0) {
        ans = 6;
    }
    for (int i = 1; i < (int)S.size(); i++) {
        if (S[i] == 1) {
            ans *= 2;
        } else if (S[i] == 0) {
            ans *= 3;
        }
        ans %= MOD;
    }
    cout << ans << endl;
}
