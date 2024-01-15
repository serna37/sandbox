#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int> mst = a;
    sort(mst.begin(), mst.end());
    map<int, vector<int>> mp;
    for (int i = 0; i < N; i++) {
        mp[i % K].push_back(a[i]);
    }
    for (auto &v : mp) {
        sort(v.second.begin(), v.second.end());
    }
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        ans.push_back(mp[i % K][i / K]);
    }
    if (ans == mst) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
