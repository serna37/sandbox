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
    vector<int> d;
    for (int i = 0; i < N; i++) {
        if (S1[i] == S2[i]) {
            d.push_back(1);
        } else {
            d.push_back(0);
            i++;
        }
    }
    int M = d.size();
    const int MOD = 1000000007;
    long long ans = 3;
    if (d[0] == 0) {
        ans = 6;
    }
    for (int i = 1; i < M; i++) {
        if (d[i - 1] == 1) {
            ans *= 2;
        } else if (d[i] == 0) {
            ans *= 3;
        }
        ans %= MOD;
    }
    cout << ans << endl;
}
