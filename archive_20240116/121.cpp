#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    vector<int> d(m - 1);
    for (int i = 0; i < m - 1; i++) {
        d[i] = x[i + 1] - x[i];
    }
    sort(d.rbegin(), d.rend());
    long long ans = 0;
    for (int i = n - 1; i < m - 1; i++) {
        ans += d[i];
    }
    cout << ans << endl;
}
