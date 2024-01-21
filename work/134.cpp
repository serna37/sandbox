#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    double ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ans = max(ans, hypot(x[i] - x[j], y[i] - y[j]));
        }
    }
    cout << ans << endl;
}
