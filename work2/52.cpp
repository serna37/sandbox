#include <bits/stdc++.h>
using namespace std;
auto split = [](string s, char c) -> vector<string> {
    vector<string> S;
    string t;
    for (char v : s) {
        if (v == c) {
            if (!t.empty()) S.push_back(t);
            t.clear();
        } else {
            t += v;
        }
    }
    if (!t.empty()) S.push_back(t);
    return S;
};
int main() {
    auto A = split("testest", 'e');
    cout << "debug_A:";                // TODO debug
    for (auto v : A) cout << " " << v; // TODO debug
    cout << endl;                      // TODO debug
}
