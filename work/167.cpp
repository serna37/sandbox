#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    map<pair<string, int>, int> mp;
    for (int i = 0; i < N; i++) {
        string S;
        int P;
        cin >> S >> P;
        mp[{S, -P}] = i + 1;
    }
    for (auto &v : mp) {
        cout << v.second << endl;
    }
}
