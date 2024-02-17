#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            bool alma = true;
            bool vis = true;
            for (int k = 0; k < N; k++) {
                alma &= A[i][j] <= A[i][k] + A[k][j];
                if (!alma) {
                    cout << -1 << endl;
                    return 0;
                }
                if (i != k and j != k and A[i][j] == A[i][k] + A[k][j]) {
                    vis = false;
                }
            }
            if (vis) {
                ans += A[i][j];
            }
        }
    }
    cout << ans << endl;
}
