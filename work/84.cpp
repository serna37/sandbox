#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    if (N % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    int K = N / 2;
    deque<char> deq;
    deq.push_back('b');
    for (int i = 1; i <= K; i++) {
        if (i % 3 == 1) {
            deq.push_front('a');
            deq.push_back('c');
        }
        if (i % 3 == 2) {
            deq.push_front('c');
            deq.push_back('a');
        }
        if (i % 3 == 0) {
            deq.push_front('b');
            deq.push_back('b');
        }
    }
    string T;
    while (!deq.empty()) {
        T += deq.front();
        deq.pop_front();
    }
    if (S == T) {
        cout << K << endl;
    } else {
        cout << -1 << endl;
    }
}
