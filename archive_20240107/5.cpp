#include <bits/stdc++.h>
using namespace std;
int main() {
    string S, T;
    cin >> S >> T;
    bool allma = true;
    for (int i = 0; i < (int)S.size(); i++) {
        allma &= S[i] == T[i];
    }
    cout << (allma ? "Yes" : "No") << endl;
}
