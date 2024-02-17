#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int N = s.size();
    string ans = "";
    for (int l = 0, r = 0; l < N; l++) {
        l = r;
        while (r < N and s[l] == s[r]) {
            ++r;
        }
        ans += s[l] + to_string(r - l);
    }
    cout << ans << endl;
}
