#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 4;
    set<string> SS;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        SS.insert(S);
    }
    if (SS.size() == 4) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
