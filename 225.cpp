#include <bits/stdc++.h>
using namespace std;
int main() {
    long long A, V, B, W, T;
    cin >> A >> V >> B >> W >> T;
    if (abs(A - B) <= (V - W) * T) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
