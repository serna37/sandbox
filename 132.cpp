#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 3;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[2] - a[1] == a[1] - a[0]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}