#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    long long ans = 1;
    int tmp = 0;
    for (int i = 1; i <= N; i++) {
        if (i % K == 0) {
            tmp++;
        }
    }
    ans *= tmp * tmp * tmp;
    if (K % 2 == 0) {
        int t = 0;
        for (int i = 1; i <= N; i++) {
            if (i % K == K / 2) {
                t++;
            }
        }
        ans += t * t * t;
    }
    cout << ans << endl;
}
