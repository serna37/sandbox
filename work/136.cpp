#include <bits/stdc++.h>
using namespace std;
int main() {
    long long S;
    cin >> S;
    long long M = 1e9;
    if (S == 1e18) {
        cout << "0 0 " << M << " 0 " << M << " " << M << endl;
        return 0;
    }
    int a = M - S % M;
    int b = S / M + 1;
    cout << "0 0 " << M << " 1 " << a << " " << b << endl;
}
