#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    map<char, int> mp;
    for (auto &v : S) {
        mp[v]++;
    }
    int cnt;
    char ans;
    for (auto &v : mp) {
        if (cnt < v.second) {
            cnt = v.second;
            ans = v.first;
        }
    }
    cout << ans << endl;
}
