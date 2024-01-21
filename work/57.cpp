#include <bits/stdc++.h>
using namespace std;
int main() {
    int K, T;
    cin >> K >> T;
    vector<int> a(T);
    int M = 0;
    for (int i = 0; i < T; i++) {
        cin >> a[i];
        M = max(M, a[i]);
    }
    auto divCeil = []<class T>(T a, T b) -> T {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    if (divCeil(K, 2) >= M) {
        cout << 0 << endl;
    } else {
        cout << (K - 1) - (K - M) * 2 << endl;
    }
}
