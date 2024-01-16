#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 3;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    if (A[2] - A[1] == A[1] - A[0]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
