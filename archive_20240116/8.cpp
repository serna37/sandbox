#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int q;
    cin >> q;
    vector<int> m(q);
    for (int i = 0; i < q; i++) {
        cin >> m[i];
    }
    for (int i = 0; i < q; i++) {
        bool anyma = false;
        for (int bit = 0; bit < 1 << n; bit++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                if (bit & (1 << k)) {
                    sum += A[k];
                }
            }
            anyma |= sum == m[i];
        }
        cout << (anyma ? "yes" : "no") << endl;
    }
}
