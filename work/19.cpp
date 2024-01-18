#include <bits/stdc++.h>
using namespace std;
int main() {
    auto divCeil = []<class T>(T a, T b) -> T {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    auto divFloor = []<class T>(T a, T b) -> T {
        return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
    };
    auto test = divCeil(10, 3);
    auto test2 = divFloor(10, 3);
    cout << test << endl;
    cout << test2 << endl;
}
