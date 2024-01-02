#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, L, R;
    cin >> N >> L >> R;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        if (i) {
            cout << " ";
        }
        cout << clamp(A[i], L, R);
    }
    cout << endl;
}
