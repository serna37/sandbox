#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    auto compress = []<class T>(vector<T> &a) -> int {
        vector<T> c = a;
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        for (auto &v : a) v = lower_bound(c.begin(), c.end(), v) - c.begin();
        return c.size();
    };
    compress(A);
    compress(B);
    for (int i = 0; i < N; i++) {
        cout << A[i] + 1 << " " << B[i] + 1 << endl;
    }
}
