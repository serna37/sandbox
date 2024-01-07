#include <bits/stdc++.h>
using namespace std;
int main() {
    string A;
    long long B;
    cin >> A >> B;
    int ans = (B - 1) % A.size();
    cout << ans << endl;
}
