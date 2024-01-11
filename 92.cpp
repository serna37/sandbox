#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    auto split = [](string s, char c) -> vector<string> {
        vector<string> S;
        string t;
        for (char v : s) {
            if (v == c) {
                if (!t.empty()) {
                    S.push_back(t);
                }
                t.clear();
            } else {
                t += v;
            }
        }
        if (!t.empty()) {
            S.push_back(t);
        }
        return S;
    };
    vector<string> s = split(S, '+');
    int ans = 0;
    for (auto v : s) {
        if (v.find("0") == string::npos) {
            ans++;
        }
    }
    cout << ans << endl;
}
