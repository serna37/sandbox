#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    auto itr = lower_bound(A.begin(), A.end(), 5);
    cout << (itr == A.end() ? "no" : "aru") << endl;
    int idx = itr - A.begin();
    cout << idx << endl;
    cout << A[idx] << endl;
}
