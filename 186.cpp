#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S1, S2;
    cin >> N >> S1 >> S2;
    if (N == 1) {
        cout << 3 << endl;
        return 0;
    }
    const int MOD = 1000000007;
    vector<int> D;
    for (int i = 0; i < N; i++) {
        if (S1[i] == S2[i]) {
            D.push_back(1);
        } else {
            D.push_back(0);
            i++;
        }
    }
    long long ans = 1;
    if (D[0] == 1) {
        ans = 3;
    } else {
        ans = 6;
    }
    for (int i = 1; i < (int)D.size(); i++) {
        if (D[i - 1] == 1) {
            ans *= 2;
        } else if (D[i] == 0) {
            ans *= 3;
        }
        ans %= MOD;
    }
    cout << ans << endl;
}
