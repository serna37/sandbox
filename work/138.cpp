// https://atcoder.jp/contests/arc075/tasks/arc075_c
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
    vector<long long> seg(cs << 1, 0);
    long long ans = 0;
    vector<int> FenwickTree(cs + 1, 0);
    for (auto v : Z) {
        int i = v + 1;
        while (i > 0) {
            ans += FenwickTree[i];
            i -= i & -i;
        }
        i = v + 1;
        while (i <= cs) {
            FenwickTree[i]++;
            i += i & -i;
        }
    }
    cout << ans << endl;
}
