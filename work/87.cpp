#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        S[i + 1] = S[i] + a - K;
    }
    vector<long long> cvt = S;
    sort(cvt.begin(), cvt.end());
    cvt.erase(unique(cvt.begin(), cvt.end()), cvt.end());
    for (auto &v : S) {
        v = lower_bound(cvt.begin(), cvt.end(), v) - cvt.begin();
    }
    int cnt = cvt.size();
    long long ans = 0;
    vector<int> fwk(cnt + 1, 0);
    for (int i = 0; i < N + 1; i++) {
        for (int f = S[i] + 1; f; f -= f & -f) {
            ans += fwk[f];
        }
        for (int f = S[i] + 1; f <= cnt; f += f & -f) {
            fwk[f]++;
        }
    }
    cout << ans << endl;
}
