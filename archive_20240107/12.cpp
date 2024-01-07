#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int ii = 0; ii < M; ii++) {
            cin >> A[i][ii];
        }
    }
    long long ans = 0;
    for (int t1 = 0; t1 < M; t1++) {
        for (int t2 = t1 + 1; t2 < M; t2++) {
            long long tmp = 0;
            for (int i = 0; i < N; i++) {
                tmp += max(A[i][t1], A[i][t2]);
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
}
