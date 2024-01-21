#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (a == c or a == d or b == c or b == d ? "YES" : "NO") << endl;
}
