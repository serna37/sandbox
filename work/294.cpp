#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    auto zip = []<class T>(vector<T> a) -> pair<vector<T>, vector<T>> {
        vector<T> c = a;
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        for (auto &v : a) v = lower_bound(c.begin(), c.end(), v) - c.begin();
        return {a, c};
    };
    auto [comp, cvt] = zip(A);
}
