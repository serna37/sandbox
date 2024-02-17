#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    vector<int> A(26);
    int N = S.size();
    for (int i = 0; i < N; i++) {
        A[S[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (A[ans] < A[i]) {
            ans = i;
        }
    }
    char a = ans + 'a';
    cout << a << endl;
}
