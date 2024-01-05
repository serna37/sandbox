#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    for (int i = 0; i < M; i++) {
        cin >> X[i];
    }
    vector<int> d(M - 1);
    sort(X.begin(), X.end());
    for (int i = 0; i < M - 1; i++) {
        d[i] = X[i + 1] - X[i];
    }
    sort(d.begin(), d.end());
    int ans = 0;
    for (int i = 0; i < M - N; i++) {
        ans += d[i];
    }
    cout << ans << endl;
}
