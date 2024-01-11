#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S, T;
    cin >> N >> S >> T;
    bool alma = true;
    for (int i = 0; i < N; i++) {
        alma &= S[i] == T[i] or (S[i] == '1' and T[i] == 'l') or
                (S[i] == 'l' and T[i] == '1') or
                (S[i] == '0' and T[i] == 'o') or (S[i] == 'o' and T[i] == '0');
    }
    cout << (alma ? "Yes" : "No") << endl;
}
