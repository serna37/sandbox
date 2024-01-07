#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> R(n), C(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        if (R[r] + C[c] >= n + 1) {
            cout << "#";
        } else {
            cout << ".";
        }
    }
    cout << endl;
}
