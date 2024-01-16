#include <bits/stdc++.h>
using namespace std;
int main() {
    string A;
    int B;
    cin >> A >> B;
    B--;
    int M = A.size();
    cout << A[B % M] << endl;
}
