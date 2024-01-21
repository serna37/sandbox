#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> fwk(N + 1, 0);
    int i = 3 + 1;
    for (int j = i; j <= N; j += j & -j) {
        fwk[j] += 5;
    }
    int t = 1 + 1;
    for (int j = t; j <= N; j += j & -j) {
        fwk[j] += 2;
    }
    int ans1 = 0;
    int ii = 2 + 1;
    for (int j = ii; j; j -= j & -j) {
        ans1 += fwk[j];
    }
    cout << ans1 << endl;
    int ans2 = 0;
    int tt = 4 + 1;
    for (int j = tt; j; j -= j & -j) {
        ans2 += fwk[j];
    }
    cout << ans2 << endl;
}
