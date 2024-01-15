#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    string S1, S2;
    cin >> S1 >> S2;
    vector<int> D;
    for (int i = 0; i < N; i++) {
        if (S1[i] == S2[i]) {
            D.push_back(1);
        } else {
            D.push_back(0);
            i++;
        }
    }
    const int MOD = 1000000007;
    long long ans = 3;
    if (D[0] == 0) {
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
