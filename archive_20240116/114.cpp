#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 10;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = i + 5;
    }
    set<int> st;
    for (int i = 0; i < N; i++) {
        st.insert(A[i]);
    }
    cout << "debug_st:";                // TODO debug;
    for (auto v : st) cout << " " << v; // TODO debug
    cout << endl;                       // TODO debug
    auto itr = st.upper_bound(3);
    cout << *itr << endl;
    if (itr == st.begin()) {
        cout << "begin" << endl;
    }
}
