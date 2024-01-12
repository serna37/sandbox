#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    set<string> S, T;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s.starts_with("!")) {
            S.insert(s.erase(0, 1));
        } else {
            T.insert(s);
        }
    }
    for (string t : T) {
        if (S.find(t) != S.end()) {
            cout << t << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
}
