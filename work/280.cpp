#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<long long> A;
    int Q;
    cin >> Q;
    while (Q--) {
        int q, x;
        cin >> q >> x;
        if (q == 1) {
            A.push_back(x);
        } else {
            int N = A.size();
            cout << A[N - x] << endl;
        }
    }
}
