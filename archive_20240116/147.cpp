#include <bits/stdc++.h>
using namespace std;
int main() {
    int X, Y;
    cin >> X >> Y;
    int diff = Y - X;
    if (diff <= 0) {
        cout << 0 << endl;
        return 0;
    }
    auto divCeil = [](int a, int b) -> int {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    cout << (divCeil(diff, 10)) << endl;
}
