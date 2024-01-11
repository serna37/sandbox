#include <bits/stdc++.h>
using namespace std;
int main() {
    int a = 5, b = 9;
    auto func = [&](int a) -> void {
        a += 5;
        cout << a << endl;
        b += 3;
    };
    func(b);
    cout << a << endl;
    cout << b << endl;
}
