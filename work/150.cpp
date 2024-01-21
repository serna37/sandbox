#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    set<int> st;
    for (int i = 0; i <= 2e5; i++) {
        st.insert(i);
    }
    for (int i = 0; i < N; i++) {
        if (st.count(p[i])) {
            st.erase(p[i]);
        }
        cout << *st.begin() << endl;
    }
}
