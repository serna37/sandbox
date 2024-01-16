#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] == '6') {
            S[i] = '9';
        } else if (S[i] == '9') {
            S[i] = '6';
        }
    }
    cout << S << endl;
}
