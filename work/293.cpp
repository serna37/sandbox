#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int tmp = A[i];
        for (int j = i; j < N; j++) {
            if (tmp > A[j]) {
                tmp = A[j];
            }
            ans = max(ans, (long long)(j - i + 1) * tmp);
        }
    }
    cout << ans << endl;
}
