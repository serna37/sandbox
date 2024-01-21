#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < N - 1; i++) {
        if (H[i] >= H[i + 1]) {
            tmp++;
        } else {
            ans = max(ans, tmp);
            tmp = 0;
        }
    }
    ans = max(ans, tmp);
    cout << ans << endl;
}
