#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        mp[S[i]]++;
    }
    int m = 0;
    string ans = "";
    for (auto v : mp) {
        if (m < v.second) {
            ans = v.first;
            m = v.second;
        }
    }
    cout << ans << endl;
}
