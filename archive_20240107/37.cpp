#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> s(M), c(M);
    for (int i = 0; i < M; i++) {
        cin >> s[i] >> c[i];
        s[i]--;
    }
    int ans = -1;
    for (int i = 0; i <= 999; i++) {
        string S = to_string(i);
        if (S.size() != N) {
            continue;
        }
        bool allma = true;
        for (int iu = 0; iu < M; iu++) {
            allma &= S[s[iu]] - '0' == c[iu];
        }
        if (allma) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
