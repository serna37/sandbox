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
    long long ans = 1;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int a = mp[A[i] - 1] - mp[A[i]];
        if (A[i] == 0) {
            a = 3 - mp[0];
        }
        ans *= a;
        ans %= MOD;
        mp[A[i]]++;
    }
    cout << ans << endl;
}
