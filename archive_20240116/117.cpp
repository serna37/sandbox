#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> v(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        v[i].resize(L);
        for (int ii = 0; ii < L; ii++) {
            cin >> v[i][ii];
        }
    }
    sort(v.begin(), v.end());
    int ans = 1;
    for (int i = 0; i < N - 1; i++) {
        if (v[i] != v[i + 1]) {
            ans++;
        }
    }
    cout << ans << endl;
}
