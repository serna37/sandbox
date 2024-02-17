#include <bits/stdc++.h>
using namespace std;
int main() {
    int M;
    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    int ans = 0;
    for (int l = 0, r = 0, sum = 0; l < M; sum -= B[l++]) {
        while (r < M and sum + B[r] <= 100) sum += B[r++];
        ans = max(ans, M - r);
    }
    cout << ans << endl;
}
