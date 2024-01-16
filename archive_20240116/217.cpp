#include <bits/stdc++.h>
using namespace std;
int main() {
    string A;
    int B;
    cin >> A >> B;
    B--;
    B %= (int)A.size();
    cout << A[B] << endl;
}
