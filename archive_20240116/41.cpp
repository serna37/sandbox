#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    int ans = 1;
    int cur = 0;
    while (true) {
        if (a[cur] == 1) {
            break;
        }
        if (ans > N) {
            cout << -1 << endl;
            return 0;
        }
        cur = a[cur];
        ans++;
    }
    cout << ans << endl;
}
