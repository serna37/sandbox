#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 10;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = i + 3;
    }
    for (int v : A) {
        cout << v << " ";
    }
    cout << endl;
    int idx = lower_bound(A.begin(), A.end(), 5) - A.begin();
    cout << idx << endl;
}
