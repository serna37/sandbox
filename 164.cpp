#include <bits/stdc++.h>
using namespace std;
int main() {
    string S, T;
    cin >> S >> T;
    cout << (T.starts_with(S) ? "Yes" : "No") << endl;
}
