#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    for (int i = 0; i < 6; i++) {
        char a = i + 'A';
        if (i) {
            cout << " ";
        }
        cout << count(S.begin(), S.end(), a);
    }
    cout << endl;
}
