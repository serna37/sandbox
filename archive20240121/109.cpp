#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> A;
    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    cout << A[1] - A[0] + A[2] - A[1] << endl;
}
