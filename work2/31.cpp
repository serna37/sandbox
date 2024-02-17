#include <bits/stdc++.h>
using namespace std;
// template <typename T> vector<T> zip(vector<T> A) {
// auto c = A;
// sort(c.begin(), c.end());
// c.erase(unique(c.begin(), c.end()), c.end());
// for (auto &v : A) v = lower_bound(c.begin(), c.end(), v) - c.begin();
// return A;
//}
int main() {
    auto zip = []<class T>(vector<T> a) -> vector<T> {
        vector<T> c = a;
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        for (auto &v : a) v = lower_bound(c.begin(), c.end(), v) - c.begin();
        return a;
    };
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (auto &v : zip(A)) {
        cout << v << endl;
    }
}
