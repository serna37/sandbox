#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    cout << fixed << setprecision(20);
    double ans = 0;
    for (int i = 1; i <= N; i++) {
        double tmp = 1;
        int a = i;
        while (a < K) {
            tmp /= 2;
            a *= 2;
        }
        ans += tmp / N;
    }
    cout << ans << endl;
}
