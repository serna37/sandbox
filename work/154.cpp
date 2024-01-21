#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> R(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }
    vector<int> C(n);
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    int q;
    cin >> q;
    while (q--) {
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
