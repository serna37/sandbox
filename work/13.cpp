#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int N = s.size();
    string ans = "";
    int r = 0;
    for (int l = 0; l < N; l++) {
        l = r;
        if (l >= N) {
            break;
        }
        while (r < N and s[l] == s[r]) {
            ++r;
        }
        ans += s[l] + to_string(r - l);
    }
    cout << ans << endl;
}
