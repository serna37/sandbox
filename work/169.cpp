#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    deque<char> q;
    q.push_back('b');
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 1) {
            q.push_front('a');
            q.push_back('c');
        } else if (i % 3 == 2) {
            q.push_back('a');
            q.push_front('c');
        } else {
            q.push_back('b');
            q.push_front('b');
        }
        if (q.size() == S.size()) {
            bool alma = true;
            for (auto &v : S) {
                alma &= q.front() == v;
                q.pop_front();
            }
            if (alma) {
                cout << i << endl;
            } else {
                cout << -1 << endl;
            }
            return 0;
        }
    }
    cout << -1 << endl;
}
