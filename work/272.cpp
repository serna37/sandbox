#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i];
    }
    for (int i = 0; i <= 100; i++) {
        auto B = A;
        B.push_back(i);
        sort(B.begin(), B.end());
        int sum = reduce(B.begin(), B.end()) - B.back() - B.front();
        if (sum >= X) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
