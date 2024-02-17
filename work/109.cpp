#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N;
    cin >> N;
    auto digitsum = []<class T>(T a, int N = 10) -> T {
        T ans = 0;
        while (a != 0) {
            ans += a % N;
            a /= N;
        }
        return ans;
    };
    int ans = INF;
    for (int A = 1; A < N; A++) {
        int B = N - A;
        ans = min(ans, digitsum(A) + digitsum(B));
    }
    cout << ans << endl;
}
