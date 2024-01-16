#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int M = S.size();
    for (int i = 0; i < M; i++) {
        if (S[i] == '6') {
            S[i] = '9';
        } else if (S[i] == '9') {
            S[i] = '6';
        }
    }
    reverse(S.begin(), S.end());
    cout << S << endl;
}
