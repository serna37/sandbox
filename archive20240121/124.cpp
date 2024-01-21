#include <bits/stdc++.h>
using namespace std;
int main() {
    string A;
    int B;
    cin >> A >> B;
    B--;
    int N = A.size();
    cout << A[B % N] << endl;
}
