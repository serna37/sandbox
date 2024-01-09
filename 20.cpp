#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = i;
    }
    int cnt = 0;
    double ans = 0;
    do {
        cnt++;
        for (int i = 1; i < N; i++) {
            ans += hypot(x[A[i]] - x[A[i - 1]], y[A[i]] - y[A[i - 1]]);
        }
    } while (next_permutation(A.begin(), A.end()));
    ans /= cnt;
    cout << fixed << setprecision(10);
    cout << ans << endl;
}
