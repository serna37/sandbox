#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        mp[S]++;
    }
    int M = 0;
    string ans;
    for (auto v : mp) {
        if (M < v.second) {
            M = v.second;
            ans = v.first;
        }
    }
    cout << ans << endl;
}
