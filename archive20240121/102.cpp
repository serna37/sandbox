#include <bits/stdc++.h>
using namespace std;
int main() {
    int Q;
    cin >> Q;
    multiset<int> st;
    queue<int> q;
    while (Q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int x;
            cin >> x;
            q.push(x);
        }
        if (c == 2) {
            if (st.empty()) {
                cout << q.front() << endl;
                q.pop();
            } else {
                cout << *st.begin() << endl;
                st.erase(st.begin());
            }
        }
        if (c == 3) {
            while (!q.empty()) {
                int tmp = q.front();
                q.pop();
                st.insert(tmp);
            }
        }
    }
}
