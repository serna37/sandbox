#include <bits/stdc++.h>
using namespace std;
const vector<int> dx = {0, 1, 0, -1, 1, -1, 1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, 1, -1, -1};
int main() {
    int N;
    cin >> N;
    vector<vector<char>> A(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 8; k++) {
                string tmp = "";
                for (int l = 0; l < N; l++) {
                    int y = i + dy[k] * l;
                    int x = j + dx[k] * l;
                    y = (y + N) % N;
                    x = (x + N) % N;
                    tmp += A[y][x];
                }
                ans = max(ans, stoll(tmp));
            }
        }
    }
    cout << ans << endl;
}
