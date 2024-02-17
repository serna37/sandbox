#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> T, S;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s.starts_with('!')) {
            S.push_back(s.erase(0, 1));
        } else {
            T.push_back(s);
        }
    }
    sort(S.begin(), S.end());
    for (auto &v : T) {
        if (binary_search(S.begin(), S.end(), v)) {
            cout << v << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
}
