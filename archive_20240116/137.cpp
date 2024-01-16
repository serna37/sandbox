#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        A[i].resize(L);
        for (int ii = 0; ii < L; ii++) {
            cin >> A[i][ii];
        }
    }
    sort(A.begin(), A.end());
    int ans = 1;
    for (int i = 1; i < N; i++) {
        if (A[i] != A[i - 1]) {
            ans++;
        }
    }
    cout << ans << endl;
}
