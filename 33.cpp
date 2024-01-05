#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<int> left(N), right(N);
    for (int i = 1; i < N; i++) {
        left[i] = left[i - 1] + (S[i - 1] == 'W');
    }
    for (int i = N - 2; i >= 0; i--) {
        right[i] = right[i + 1] + (S[i + 1] == 'E');
    }
    int ans = INF;
    for (int i = 0; i < N; i++) {
        ans = min(ans, left[i] + right[i]);
    }
    cout << ans << endl;
}
