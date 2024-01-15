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
    int ans = 0;
    string a = "";
    for (auto v : mp) {
        if (ans < v.second) {
            ans = v.second;
            a = v.first;
        }
    }
    cout << a << endl;
}
