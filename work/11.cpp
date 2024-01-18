#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> S1, S2;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if (S.starts_with("!")) {
            S1.push_back(S.erase(0, 1));
        } else {
            S2.push_back(S);
        }
    }
    sort(S2.begin(), S2.end());
    for (string s : S1) {
        if (binary_search(S2.begin(), S2.end(), s)) {
            cout << s << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
}
