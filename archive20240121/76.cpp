#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, V, B, W, T;
    cin >> A >> V >> B >> W >> T;
    int dv = V - W;
    if (dv <= 0) {
        cout << "NO" << endl;
        return 0;
    }
    int dx = abs(B - A);
    auto divCeil = []<class T>(T a, T b) -> T {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    if (T >= divCeil(dx, dv)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
