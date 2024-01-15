#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 4;
    set<string> st;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        st.insert(S);
    }
    cout << (st.size() == 4 ? "Yes" : "No") << endl;
}
