#include <bits/stdc++.h>
using namespace std;
int main() {
    string S, T;
    cin >> S >> T;
    bool alma = true;
    for (int i = 0; i < (int)S.size(); i++) {
        alma &= T[i] == S[i];
    }
    cout << (alma ? "Yes" : "No") << endl;
}
