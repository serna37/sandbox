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
    vector<long long> S(N + 1, 0);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + a[i];
    }
    vector<long long> t = S;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    for (long long &v : S) {
        v = lower_bound(t.begin(), t.end(), v) - t.begin();
    }
    int cnt = t.size();
    long long ans = 0;
    vector<int> fenwick(cnt + 1, 0);
    for (int i = 0; i < N + 1; i++) {
        for (int f = S[i] + 1; f; f -= f & -f) {
            ans += fenwick[f];
        }
        for (int f = S[i] + 1; f <= cnt; f += f & -f) {
            fenwick[f]++;
        }
    }
    cout << ans << endl;
}
