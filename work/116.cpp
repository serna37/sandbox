#include <bits/stdc++.h>
using namespace std;
int main() {
    int K, T;
    cin >> K >> T;
    vector<int> a(T);
    for (int i = 0; i < T; i++) {
        cin >> a[i];
    }
    int M = *max_element(a.begin(), a.end());
    int D = (K + 1) / 2;
    if (M <= D) {
        cout << 0 << endl;
        return 0;
    }
    cout << (K - 1) - (K - M) * 2 << endl;
}
