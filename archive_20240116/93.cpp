#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    int a = 0, b = 0;
    for (int i = 1; i <= N; i++) {
        if (i % K == 0) {
            a++;
        }
        if (K % 2 == 0 and i % K == K / 2) {
            b++;
        }
    }
    long long ans = (long long)a * a * a;
    long long ans2 = 1;
    if (K % 2 == 0) {
        ans2 = (long long)b * b * b;
        cout << ans + ans2 << endl;
        return 0;
    }
    cout << ans << endl;
}
