#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> s(M), c(M);
    for (int i = 0; i < M; i++) {
        cin >> s[i] >> c[i];
    }
    int ans = -1;
    for (int i = 0; i <= 999; i++) {
        string S = to_string(i);
        if (S.size() != N) {
            continue;
        }
        bool alma = true;
        for (int ii = 0; ii < M; ii++) {
            alma &= S[s[ii]] == S[c[ii]];
        }
        if (alma) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
