#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    set<int> st;
    queue<int> A, B;
    for (int i = 0; i < N + 1; i++) {
        st.insert(i);
        if (S[i] == 'B') {
            A.push(i);
        } else {
            B.push(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (i & 1) {
            if (A.empty()) {
                st.erase(--st.end());
            } else {
                st.erase(A.front());
                A.pop();
            }
        } else {
            if (B.empty()) {
                st.erase(--st.end());
            } else {
                st.erase(B.front());
                B.pop();
            }
        }
        cout << (S[*st.begin()] == 'A' ? "Alice" : "Bob") << endl;
    }
}
