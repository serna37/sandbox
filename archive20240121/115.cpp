#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    bool n = S.find('N') != string::npos;
    bool s = S.find('S') != string::npos;
    bool e = S.find('E') != string::npos;
    bool w = S.find('W') != string::npos;
    bool ok = false;
    if (n and s and e and w) {
        ok = true;
    } else if (n and s and !e and !w) {
        ok = true;
    } else if (!n and !s and e and w) {
        ok = true;
    }
    cout << (ok ? "Yes" : "No") << endl;
}
