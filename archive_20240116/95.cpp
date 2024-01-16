#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    vector<char> P(10, 'x');
    for (int i = 0; i < a; i++) {
        int p;
        cin >> p;
        P[p] = '.';
    }
    for (int i = 0; i < b; i++) {
        int q;
        cin >> q;
        P[q] = 'o';
    }
    cout << P[7] << " " << P[8] << " " << P[9] << " " << P[0] << endl;
    cout << " " << P[4] << " " << P[5] << " " << P[6] << endl;
    cout << "  " << P[2] << " " << P[3] << endl;
    cout << "   " << P[1] << endl;
}
