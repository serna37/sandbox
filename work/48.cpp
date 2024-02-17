#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    bool a = !(S.find('N') != string::npos ^ S.find('S') != string::npos);
    bool b = !(S.find('W') != string::npos ^ S.find('E') != string ::npos);
    cout << (a and b ? "Yes" : "No") << endl;
}
