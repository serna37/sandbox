#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9;
const long long M2 = 1e18;
int main() {
    long long S;
    cin >> S;
    if (S == M2) {
        cout << "0 0 " << M << " 0 " << M << " " << M << endl;
        return 0;
    }
    int a = M - S % M;
    int b = S / M + 1;
    cout << "0 0 " << M << " 1 " << a << " " << b << endl;
}
