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
        vector<int> A(26);
        for (int k = 0; k < N; k++) {
            if (bit & (1ll << k)) {
                for (auto &v : S[k]) {
                    A[v - 'a']++;
                }
            }
        }
        int tmp = 0;
        for (int i = 0; i < 26; i++) {
            if (A[i] == K) {
                tmp++;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
