#include <bits/stdc++.h>
using namespace std;
int main() {
    int X, Y;
    cin >> X >> Y;
    if (X >= Y) {
        cout << 0 << endl;
        return 0;
    }
    int D = Y - X;
    auto divCeil = [](int a, int b) -> int {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    cout << divCeil(D, 10) << endl;
}
