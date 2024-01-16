#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 5;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = i + 5;
    }
    cout << "debug_A:";                // TODO debug
    for (auto v : A) cout << " " << v; // TODO debug
    cout << endl;                      // TODO debug
    auto itr = upper_bound(A.begin(), A.end(), 300);
    cout << (itr == A.end()) << endl;
    cout << (itr == A.begin()) << endl;
    cout << itr - A.begin() << endl;
    cout << *itr << endl;
}
