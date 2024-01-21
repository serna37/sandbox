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
    int n = t.size();
    long long ans = 0;
    vector<int> fwk(n + 1, 0);
    for (int i = 0; i < N; i++) {
        int l = Z[i] + 1;
        while (l) {
            ans += fwk[l];
            l -= l & -l;
        }
        l = Z[i] + 1;
        while (l <= n) {
            fwk[l]++;
            l += l & -l;
        }
    }
    cout << ans << endl;
}
