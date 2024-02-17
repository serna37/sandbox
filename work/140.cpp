#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    auto islow = [](char c) -> bool { return islower(c) != 0; };
    if (islow(S[0])) {
        cout << "No" << endl;
        return 0;
    }
    bool alma = true;
    for (int i = 1; i < (int)S.size(); i++) {
        alma &= islow(S[i]);
    }
    cout << (alma ? "Yes" : "No") << endl;
}
