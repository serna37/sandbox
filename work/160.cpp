#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<pair<int, int>> AB;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
        if (A[i] > B[i]) {
            swap(A[i], B[i]);
        }
        AB.push_back({A[i], B[i]});
    }
    sort(AB.begin(), AB.end());
    set<int> st;
    for (int i = 0; i < N; i++) {
        st.insert(AB[i].first);
        st.insert(AB[i].second);
        if (*st.upper_bound(AB[i].first) != AB[i].second) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
