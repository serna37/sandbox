#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> S(N), C(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> C[i];
    }
    map<int, long long> mp;
    for (int i = 0; i < N; i++) {
        int k = __builtin_ctz(S[i]);
        mp[S[i] >> k] += (long long)C[i] << k;
    }
    long long ans = 0;
    for (auto v : mp) {
        ans += __builtin_popcountll(v.second);
    }
    cout << ans << endl;
}
