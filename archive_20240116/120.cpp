#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> st(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        st[i].resize(L);
        for (int ii = 0; ii < L; ii++) {
            cin >> st[i][ii];
        }
    }
    sort(st.begin(), st.end());
    int ans = 1;
    for (int i = 0; i < N - 1; i++) {
        if (st[i] != st[i + 1]) {
            ans++;
        }
    }
    cout << ans << endl;
}
