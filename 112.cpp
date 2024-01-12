#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int N = S.size();
    string ans = "";
    int r = 0;
    for (int l = 0; l < N; l++) {
        l = r;
        if (l >= N) {
            break;
        }
        while (r < N and S[l] == S[r]) {
            ++r;
        }
        ans += S[l] + to_string(r - l);
    }
    cout << ans << endl;
}
