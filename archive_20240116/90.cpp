#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = i + 1;
    }
    bool anma = p == A;
    for (int i = 0; i < N; i++) {
        for (int ii = i + 1; ii < N; ii++) {
            swap(p[i], p[ii]);
            anma |= p == A;
            swap(p[i], p[ii]);
        }
    }
    cout << (anma ? "YES" : "NO") << endl;
}
