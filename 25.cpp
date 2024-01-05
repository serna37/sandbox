#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, X;
    cin >> N >> X;
    vector<int> S(N);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        if (S[i] <= X) {
            ans += S[i];
        }
    }
    cout << ans << endl;
}
