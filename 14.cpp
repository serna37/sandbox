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
    for (pair<int, int> P : mp) {
        ans.push_back(P.second);
    }
    reverse(ans.begin(), ans.end());
    int M = ans.size();
    for (int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }
    for (int i = M; i < N; i++) {
        cout << 0 << endl;
    }
}
