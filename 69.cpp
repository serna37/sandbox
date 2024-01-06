#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (i % K == 0) {
            cnt++;
        }
    }
    long long ans = 1;
    ans *= cnt;
    ans *= cnt;
    ans *= cnt;
    if (K % 2 == 0) {
        int c = 0;
        for (int i = 1; i <= N; i++) {
            if (i % K == K / 2) {
                c++;
            }
        }
        long long a = 1;
        a *= c;
        a *= c;
        a *= c;
        ans += a;
    }
    cout << ans << endl;
}
