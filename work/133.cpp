#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    for (auto &v : S) {
        if (v == '6') {
            v = '9';
        } else if (v == '9') {
            v = '6';
        }
    }
    cout << S << endl;
}
