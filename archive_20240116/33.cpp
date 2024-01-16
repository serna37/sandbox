#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, V, B, W, T;
    cin >> A >> V >> B >> W >> T;
    long long d = abs(A = B);
    long long dv = V - W;
    auto divCeil = [](long long a, long long b) -> long long {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    if (dv <= 0) {
        cout << "NO" << endl;
    } else if (divCeil(d, dv) <= T) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
