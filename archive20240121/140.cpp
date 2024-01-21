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
    int cs = t.size();
    long long ans = 0;
    int e = 0;
    vector<long long> seg(cs << 1, e);
    for (auto v : Z) {
        auto vl = e, vr = e;
        for (int l = cs, r = v + 1 + cs; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                vl += seg[l++];
            }
            if (r & 1) {
                vr += seg[--r];
            }
        }
        ans += vl + vr;
        int i = v + cs;
        seg[i]++;
        while (i >>= 1) {
            seg[i] = seg[i << 1 | 0] + seg[i << 1 | 1];
        }
    }
    cout << ans << endl;
}
