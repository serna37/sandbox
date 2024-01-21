#include <bits/stdc++.h>
using namespace std;
int main() {
    map<int, int> mp;
    for (int i = 0; i < 3; i++) {
        int l;
        cin >> l;
        mp[l]++;
    }
    for (auto v : mp) {
        if (v.second == 1 or v.second == 3) {
            cout << v.first << endl;
            return 0;
        }
    }
}
