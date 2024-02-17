#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1);
    for (int i = 2; i < N + 1; i++) {
        cin >> P[i];
    }
    int ans = 0;
    while (N != 1) {
        N = P[N];
        ans++;
    }
    cout << ans << endl;
}
