#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(20);
    auto factorial = [](int N) -> int {
        int ans = 1;
        while (N > 0) {
            ans *= N;
            N--;
        }
        return ans;
    };
    const int F = factorial(9);
    vector<vector<int>> G(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> G[i][j];
        }
    }
    int cnt = 0;
    vector<int> A(9);
    iota(A.begin(), A.end(), 0);
    do {
        vector<vector<int>> a(3), b(3), X(2);
        for (int i = 0; i < 9; i++) {
            int y = A[i] % 3;
            int x = A[i] / 3;
            a[x].push_back(G[y][x]);
            b[y].push_back(G[y][x]);
            if (x == y) {
                X[0].push_back(G[y][x]);
            }
            if (x + y == 2) {
                X[1].push_back(G[y][x]);
            }
        }
        bool anma = false;
        for (int i = 0; i < 3; i++) {
            anma |= a[i][0] == a[i][1] or b[i][0] == b[i][1];
        }
        for (int i = 0; i < 2; i++) {
            anma |= X[i][0] == X[i][1];
        }
        if (anma) cnt++;
    } while (next_permutation(A.begin(), A.end()));
    double ans = (double)(F - cnt) / F;
    cout << ans << endl;
}
