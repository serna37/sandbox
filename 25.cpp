#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> a(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        for (int ii = 0; ii < L; ii++) {
            cin >> a[i][ii];
        }
    }
    sort(a.begin(), a.end());
    int ans = 1;
    for (int i = 0; i < N - 1; i++) {
        if (a[i] == a[i + 1]) {
            ans++;
        }
    }
    cout << ans << endl;
}
