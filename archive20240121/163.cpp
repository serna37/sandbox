#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    vector<char> B(10, 'x');
    vector<int> p(a);
    for (int i = 0; i < a; i++) {
        cin >> p[i];
        B[p[i]] = '.';
    }
    vector<int> q(b);
    for (int i = 0; i < b; i++) {
        cin >> q[i];
        B[q[i]] = 'o';
    }
    cout << B[7] << " " << B[8] << " " << B[9] << " " << B[0] << endl;
    cout << " " << B[4] << " " << B[5] << " " << B[6] << endl;
    cout << "  " << B[2] << " " << B[3] << endl;
    cout << "   " << B[1] << endl;
}
