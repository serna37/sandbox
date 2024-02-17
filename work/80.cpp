#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    int ans = 0;
    for (int bit = 0; bit < 1 << N; bit++) {
        map<char, int> mp;
        for (int k = 0; k < N; k++) {
            if (bit & (1 << k)) {
                for (auto &v : S[k]) {
                    mp[v]++;
                }
            }
        }
        int tmp = 0;
        for (auto &v : mp) {
            if (v.second == K) {
                tmp++;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
