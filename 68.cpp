#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    auto split = [](string str, char c) -> vector<string> {
        vector<string> arr;
        string tmp;
        for (int i = 0; i < (int)str.size(); i++) {
            if (str[i] == c) {
                arr.push_back(tmp);
                tmp = "";
            } else {
                tmp += str[i];
            }
        }
        if (tmp != "") {
            arr.push_back(tmp);
        }
        return arr;
    };
    vector<string> spl = split(S, '+');
    int M = spl.size();
    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (spl[i].find('0') == string::npos) {
            ans++;
        }
    }
    cout << ans << endl;
}
