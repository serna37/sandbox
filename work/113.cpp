#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B;
    cin >> A >> B;
    cout << (A % 3 == 0 or B % 3 == 0 or (A + B) % 3 == 0 ? "Yes" : "No")
         << endl;
}
