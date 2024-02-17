#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<int> A(6);
    for (int i = 0; i < N; i++) {
        A[S[i] - 'A']++;
    }
    for (int i = 0; i < 6; i++) {
        if (i) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
}
