#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    vector<char> A(10, 'x');
    for (int i = 0; i < a; i++) {
        int p;
        cin >> p;
        A[p] = '.';
    }
    for (int i = 0; i < b; i++) {
        int q;
        cin >> q;
        A[q] = 'o';
    }
    cout << A[7] << " " << A[8] << " " << A[9] << " " << A[0] << endl;
    cout << " " << A[4] << " " << A[5] << " " << A[6] << endl;
    cout << "  " << A[2] << " " << A[3] << endl;
    cout << "   " << A[1] << endl;
}
