#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> T[i];
    }
    map<string, pair<int, int>> mp;
    for (int i = 0; i < N; i++) {
        if (mp.count(S[i]) == 0) {
            mp[S[i]] = {T[i], i + 1};
        }
    }
    vector<int> id;
    int mx = 0;
    for (auto &v : mp) {
        if (mx < v.second.first) {
            mx = v.second.first;
        }
    }
    for (auto &v : mp) {
        if (mx == v.second.first) {
            id.push_back(v.second.second);
        }
    }
    cout << *min_element(id.begin(), id.end()) << endl;
}
