#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    int q;
    cin >> q;
    set<int> T;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        T.insert(t);
    }
    int ans = 0;
    for (int t : T) {
        int i = lower_bound(S.begin(), S.end(), t) - S.begin();
        if (S[i] == t) {
            ans++;
        }
    }
    cout << ans << endl;
}
