#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, V, B, W, T;
    cin >> A >> V >> B >> W >> T;
    if ((long long)abs(A - B) <= (long long)(V - W) * T) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
