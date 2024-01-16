#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[A[i]]++;
    }
    vector<int> ans;
    for (auto v : mp) {
        ans.push_back(v.second);
    }
    reverse(ans.begin(), ans.end());
    int s = ans.size();
    for (int i = 0; i < s; i++) {
        cout << ans[i] << endl;
    }
    for (int i = s; i < N; i++) {
        cout << 0 << endl;
    }
}
