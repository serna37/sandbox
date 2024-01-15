#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    for (long long i = N; i > 0; i = (i - 1) & N) {
        cout << N - i << endl;
    }
    cout << N << endl;
}
