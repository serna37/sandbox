#include <bits/stdc++.h>
using namespace std;
int main() {
    long long A, M, L, R;
    cin >> A >> M >> L >> R;
    L -= A;
    R -= A;
    auto divCeil = [](long long a, long long b) -> long long {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    auto divFloor = [](long long a, long long b) -> long long {
        return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
    };
    long long ans = divFloor(R, M) - divCeil(L, M) + 1;
    cout << ans << endl;
}
