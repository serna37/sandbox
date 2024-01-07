#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    set<int> st;
    for (int i = 0; i < N; i++) {
        int w;
        cin >> w;
        auto itr = st.lower_bound(w);
        if (itr == st.end()) {
            st.insert(w);
        } else {
            st.erase(itr);
            st.insert(w);
        }
    }
    cout << st.size() << endl;
}
