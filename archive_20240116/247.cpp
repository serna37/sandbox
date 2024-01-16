#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    int M = (N - 1) / 2;
    vector<string> B(M + 1);
    B[0] = "b";
    for (int i = 1; i <= M; i++) {
        if (i % 3 == 0) {
            B[i] = "b" + B[i - 1] + "b";
        } else if (i % 3 == 1) {
            B[i] = "a" + B[i - 1] + "c";
        } else {
            B[i] = "c" + B[i - 1] + "a";
        }
    }
    int ans = -1;
    for (int i = 0; i < M + 1; i++) {
        if (B[i] == S) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
