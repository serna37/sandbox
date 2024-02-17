#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    vector<int> cnt(N);
    for (int i = 0; i < N; i++) {
        cnt[(p[i] - i + N) % N]++;
        cnt[(p[i] - i + N + 1) % N]++;
        cnt[(p[i] - i + N - 1) % N]++;
    }
    cout << *max_element(cnt.begin(), cnt.end()) << endl;
}
