#include <bits/stdc++.h>
using namespace std;
const long long INF = 1001001001001001001ll;
int main() {
    long long N, M;
    cin >> N >> M;
    if (N < (M + N - 1) / N) {
        cout << -1 << endl;
    } else if (M <= N) {
        cout << M << endl;
    } else {
        long long ans = INF;
        for (long long a = 1; a <= N; a++) {
            long long b = (M + a - 1) / a;
            if (b <= N) {
                ans = min(ans, a * b);
            }
            if (b < a) break;
        }
        cout << ans << endl;
    }
}
