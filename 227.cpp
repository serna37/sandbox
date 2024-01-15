#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    const int MOD = 1000000007;
    map<int, int> mp;
    int ans = 1;
    for (int i = 0; i < N; i++) {
        int cnt = mp[A[i] - 1] - mp[A[i]];
        if (A[i] == 0) {
            cnt = 3 - mp[0];
        }
        ans *= cnt;
        ans %= MOD;
        mp[A[i]]++;
    }
    cout << ans << endl;
}
