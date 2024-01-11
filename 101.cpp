#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    int k = 0;
    int kn = 0;
    for (int i = 1; i <= N; i++) {
        if (i % K == 0) {
            k++;
        }
        if (K % 2 == 0 and i % K == K / 2) {
            kn++;
        }
    }
    long long ans = (long long)k * k * k;
    if (K % 2 == 0) {
        ans += (long long)kn * kn * kn;
    }
    cout << ans << endl;
}
