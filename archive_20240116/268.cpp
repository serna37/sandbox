#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int M = s.size();
    for (int i = 0; i < M; i++) {
        if (s[i] == ',') {
            s[i] = ' ';
        }
    }
    cout << s << endl;
}
