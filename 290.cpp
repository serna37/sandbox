#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    int M = (N - 1) / 2;
    vector<string> A(M + 1);
    A[0] = "b";
    for (int i = 1; i <= M; i++) {
        if (i % 3 == 0) {
            A[i] = "b" + A[i - 1] + "b";
        } else if (i % 3 == 1) {
            A[i] = "a" + A[i - 1] + "c";
        } else {
            A[i] = "c" + A[i - 1] + "a";
        }
    }
    int ans = -1;
    for (int i = 0; i < M + 1; i++) {
        if (S == A[i]) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
