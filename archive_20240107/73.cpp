#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> d(N, vector<int>(N, -1));
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    int x = 0, y = 0, c = 1;
    d[x][y] = c;
    for (int i = 0; i < (N - 1) * 2; i++) {
        for (int ii = 0; ii < (N - 1) - (i - 1) / 2; ii++) {
            c++;
            x += dx[i % 4];
            y += dy[i % 4];
            d[x][y] = c;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int ii = 0; ii < N; ii++) {
            if (ii) {
                cout << " ";
            }
            if (d[i][ii] == -1) {
                cout << "T";
            } else {
                cout << d[i][ii];
            }
        }
        cout << endl;
    }
}
