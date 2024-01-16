#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    auto digitsum = [](int a, int N = 10) -> int {
        int ans = 0;
        while (a != 0) {
            ans += a % N;
            a /= N;
        }
        return ans;
    };
    const int INF = 1001001001;
    int ans = INF;
    for (int a = 1; a < N; a++) {
        int b = N - a;
        ans = min(ans, digitsum(a) + digitsum(b));
    }
    cout << ans << endl;
}
