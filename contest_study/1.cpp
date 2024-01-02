#include <bits/stdc++.h>
using namespace std;
int main() {
    int X, Y;
    cin >> X >> Y;
    int diff = Y - X;
    if (-3 <= diff and diff <= 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
