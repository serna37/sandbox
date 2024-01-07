#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    auto chk = [&](char c) -> bool {
        if (c == 'A' or c == 'C' or c == 'G' or c == 'T') {
            return true;
        }
        return false;
    };
    int ans = 0;
    int cur = 0;
    int N = (int)S.size();
    for (int i = 0; i < N; i++) {
        cur = max(cur, i);
        while (cur < N and chk(S[cur])) {
            cur++;
        }
        ans = max(ans, cur - i);
    }
    cout << ans << endl;
}
