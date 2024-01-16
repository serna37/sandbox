#include <bits/stdc++.h>
using namespace std;
int main() {
    long long S;
    cin >> S;
    if (S == 1e18) {
        cout << "0 0 1000000000 0 1000000000 1000000000" << endl;
        return 0;
    }
    long long M = 1e9;
    int a = M - S % M;
    int b = S / M + 1;
    cout << "0 0 1000000000 1 " << a << " " << b << endl;
}
