#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    for (long long i = n; i > 0; i = (i - 1) & n) {
        cout << n - i << endl;
    }
    cout << n << endl;
}
