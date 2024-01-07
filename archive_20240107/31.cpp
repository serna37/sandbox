#include <bits/stdc++.h>
using namespace std;
int main() {
    string A;
    long long B;
    cin >> A >> B;
    long long a = B % (long long)A.size();
    if (a == 0) {
        a += (long long)A.size();
    }
    a--;
    cout << A[a] << endl;
}
