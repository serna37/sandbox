#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    long long cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (i % K == 0) {
            cnt++;
        }
    }
    long long ans = powl(cnt, 3);
    if (K % 2 == 0) {
        long long c = 0;
        for (int i = 1; i <= N; i++) {
            if (i % K == K / 2) {
                c++;
            }
        }
        ans += powl(c, 3);
    }
    cout << ans << endl;
}
