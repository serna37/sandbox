#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    int m = 0;
    string ans;
    for (auto v : mp) {
        if (m < v.second) {
            m = v.second;
            ans = v.first;
        }
    }
    cout << ans << endl;
}
