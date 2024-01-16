#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    double ans = 0;
    for (int i = 1; i <= N; i++) {
        int dice = i;
        double tmp = 1;
        while (dice < K) {
            dice *= 2;
            tmp /= 2;
        }
        ans += tmp;
    }
    cout << ans / N << endl;
}
