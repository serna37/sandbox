#include <bits/stdc++.h>
using namespace std;
int main() {
    auto comp = []<class T>(vector<T> vec) -> vector<T> {
        auto v = vec;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < (int)vec.size(); i++) {
            vec[i] = lower_bound(v.begin(), v.end(), vec[i]) - v.begin();
        }
        return vec;
    };
    long long;
    pair<int, int>
        set<int>
        map<int, int>
        queue<>
        priority_queue<>
        stack<>
        double 
        vector<vector<int>>
        ;
    vector<int> R(N + 1);
    for (int i = N - 1; i >= 0; i--) {
        R[i] = R[i + 1] + A[i];
    }
    vector<int> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    for (int i = 0; i <N; i++) {
        lower_bound(A.begin(), A.end(),A[i]);
    }
    long long ans=0;
    cout << ans << endl;
}
