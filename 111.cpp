#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    vector<char> c;
    vector<int> cnt;
    int N = s.size();
    c.push_back(s[0]);
    cnt.push_back(1);
    for (int i = 1; i < N; i++) {
        if (c.back() == s[i]) {
            cnt.back()++;
            continue;
        }
        c.push_back(s[i]);
        cnt.push_back(1);
    }
    for (int i = 0; i < (int)c.size(); i++) {
        cout << c[i] << cnt[i];
    }
    cout << endl;
}
