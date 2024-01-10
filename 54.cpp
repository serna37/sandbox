#include <bits/stdc++.h>
using namespace std;
int main() {
    string A;
    int B;
    cin >> A >> B;
    int M = A.size();
    B--;
    cout << A[B % M] << endl;
}
