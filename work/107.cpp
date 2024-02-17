#include <bits/stdc++.h>
using namespace std;
const long long INF = 1001001001001001001ll;
int main() {
    long long N, M;
    cin >> N >> M;
    if (N < M / N) {
        cout << -1 << endl;
        return 0;
    }
    auto divCeil = []<class T>(T a, T b) -> T {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    long long ans = INF;
    for (long long a = 1; a <= N; a++) {
        long long b = divCeil(M, a);
        if (b <= N) {
            ans = min(ans, a * b);
        }
        if (b < a) {
            break;
        }
    }
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << endl;
}
