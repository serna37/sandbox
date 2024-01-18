#include <bits/stdc++.h>
using namespace std;
int main() {
    int K, T;
    cin >> K >> T;
    int M = 0;
    vector<int> a(T);
    for (int i = 0; i < T; i++) {
        cin >> a[i];
        M = max(M, a[i]);
    }
    auto divCeil = []<class T>(T a, T b) -> T {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    int D = divCeil(K, 2);
    if (M <= D) {
        cout << 0 << endl;
    } else {
        int d = M - D;
        int ans = 0;
        for (int i = 0; i < d; i++) {
            if (K % 2 == 0 and i == 0) {
                ans += 1;
            } else {
                ans += 2;
            }
        }
        cout << ans << endl;
    }
}
