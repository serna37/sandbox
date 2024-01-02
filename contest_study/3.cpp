#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        while (cur < N and A[cur] < A[i] + M) {
            cur++;
        }
        ans = max(ans, cur - i);
    }
    cout << ans << endl;
}
