#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int N = S.size();
    bool ok = false;
    if (S.find('N') != string::npos and S.find('S') != string::npos and
        (S.find('E') == string::npos and S.find('W') == string::npos)) {
        ok = true;
    }
    if (S.find('E') != string::npos and S.find('W') != string::npos and
        (S.find('N') == string::npos and S.find('S') == string::npos)) {
        ok = true;
    }
    if (S.find('E') != string::npos and S.find('W') != string::npos and
        (S.find('N') != string::npos and S.find('S') != string::npos)) {
        ok = true;
    }
    cout << (ok ? "Yes" : "No") << endl;
}
