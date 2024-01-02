#include <bits/stdc++.h>
using namespace std;
const long long INF = 1001001001001001001ll;
int main() {
    long long D;
    cin >> D;
    long long ans = INF;
    for (long long x = 0; x * x <= D; x++) {
        long long y = sqrt(D - x * x);
        ans = min(ans, abs(x * x + y * y - D));
        y++;
        ans = min(ans, abs(x * x + y * y - D));
    }
    cout << ans << endl;
}
