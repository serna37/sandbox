#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mp[A[i]]++;
    }
    vector<int> a;
    for (auto v : mp) {
        a.push_back(v.second);
    }
    reverse(a.begin(), a.end());
    while (a.size() < N) {
        a.push_back(0);
    }
    for (int v : a) {
        cout << v << endl;
    }
}
