#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    int ans = -1;
    if (S.find('-') == string::npos) {
        cout << ans << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (S[i] == '-') continue;
        int c = i;
        while (i < N and S[i] == S[c]) i++;
        ans = max(ans, i - c);
    }
    cout << ans << endl;
}
