#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 10;
    for (int i = 0; i < N; i++) {
        cout << i << ":" << endl;
        cout << (i & 1) << endl;
        cout << (i & 0) << endl;
    }
}
