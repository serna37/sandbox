#include <bits/stdc++.h>
using namespace std;
int main() {
    int X, Y;
    cin >> X >> Y;
    if (Y - X < 0) {
        cout << 0 << endl;
        return 0;
    }
    auto divCeil = []<class T>(T a, T b) -> T {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    cout << divCeil(Y - X, 10) << endl;
}
