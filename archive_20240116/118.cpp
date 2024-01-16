#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    if (N >= M) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> X(M);
    for (int i = 0; i < M; i++) {
        cin >> X[i];
    }
    sort(X.begin(), X.end());
    vector<int> D(M - 1);
    for (int i = 0; i < M - 1; i++) {
        D[i] = X[i + 1] - X[i];
    }
    sort(D.rbegin(), D.rend());
    long long ans = 0;
    for (int i = N - 1; i < M - 1; i++) {
        ans += D[i];
    }
    cout << ans << endl;
}
