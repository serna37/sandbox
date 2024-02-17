#include <bits/stdc++.h>
using namespace std;
int main() {
    int Q;
    cin >> Q;
    vector<long long> A;
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
