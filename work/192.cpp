#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> w(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    multiset<int> st;
    for (int i = 0; i < N; i++) {
        auto itr = st.lower_bound(w[i]);
        if (itr == st.end()) {
            st.insert(w[i]);
            continue;
        }
        st.erase(itr);
        st.insert(w[i]);
    }
    cout << st.size() << endl;
}
