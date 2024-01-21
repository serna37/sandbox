#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    for (auto &v : s) {
        if (v == ',') {
            v = ' ';
        }
    }
    cout << s << endl;
}
