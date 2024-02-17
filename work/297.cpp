#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == '-') continue;
        int cur = i;
        while (i < N and A[cur] == A[i]) i++;
        ans = max(ans, i - cur);
    }
    cout << ans << endl;
    int right = 0;
    for (int left = 0; left < N; left++) {
        while (right < N and A[right] == A[left]) {
            ans += A[right];
            right++;
        }
        ans += right - left;
        if (right == left) {
            right++;
        }
    }

    int K = 10;
    ans = 0;
    N = 5;
    A = {1, 2, 3, 4, 5};
    for (int l = 0, r = 0, sum = 0; l < N; sum -= A[l++]) {
        while (r < N and sum + A[r] <= K) sum += A[r++];
        ans += r - l;
    }
}
