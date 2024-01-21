#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> s(M), c(M);
    for (int i = 0; i < M; i++) {
        cin >> s[i] >> c[i];
        s[i]--;
    }
    for (int i = 0; i <= 999; i++) {
        string S = to_string(i);
        if (S.size() != N) {
            continue;
        }
        bool alma = true;
        for (int j = 0; j < M; j++) {
            alma &= S[s[j]] - '0' == c[j];
        }
        if (alma) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
