#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (i) {
            cout << " ";
        }
        cout << S[i];
    }
    cout << endl;
}
