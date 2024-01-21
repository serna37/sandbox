#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        a[i] -= K;
    }
    vector<long long> Z(N + 1);
    for (int i = 0; i < N; i++) {
        Z[i + 1] = Z[i] + a[i];
    }
    vector<long long> t = Z;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    for (auto &v : Z) {
        v = lower_bound(t.begin(), t.end(), v) - t.begin();
    }
    int cnt = t.size();
    long long ans = 0;
    vector<int> fwk(cnt + 1, 0);
    for (int i = 0; i < N + 1; i++) {
        for (int f = Z[i] + 1; f; f -= f & -f) {
            ans += fwk[f];
        }
        for (int f = Z[i] + 1; f <= cnt; f += f & -f) {
            fwk[f]++;
        }
    }
    cout << ans << endl;
}
