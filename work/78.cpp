#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    map<int, int> mp;
    long long ans = 1;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            ans *= 3 - mp[0];
        } else {
            ans *= mp[A[i] - 1] - mp[A[i]];
        }
        ans %= MOD;
        mp[A[i]]++;
    }
    cout << ans << endl;
}
