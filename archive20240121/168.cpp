#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    string s = "b";
    map<string, int> mp;
    mp[s] = 0;
    for (int i = 1; i <= 50; i++) {
        if (i % 3 == 1) {
            s = "a" + s + "c";
        } else if (i % 3 == 2) {
            s = "c" + s + "a";
        } else {
            s = "b" + s + "b";
        }
        mp[s] = i;
    }
    if (mp.count(S)) {
        cout << mp[S] << endl;
    } else {
        cout << -1 << endl;
    }
}
