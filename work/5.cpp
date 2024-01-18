#include <bits/stdc++.h>
using namespace std;
int main() {
    // int N = 10;
    // vector<int> A(N);
    // for (int i = 0; i < N; i++) {
    // A[i] = 1;
    //}
    // vector<int> S(N + 1);
    // for (int i = 0; i < N; i++) {
    // S[i + 1] = S[i] + A[i];
    //}
    // vector<int> R(N + 1);
    // for (int i = N - 1; i >= 0; i--) {
    // R[i] = R[i + 1] + A[i];
    //}
    // cout << "debug_S:";                // TODO debug
    // for (auto v : S) cout << " " << v; // TODO debug
    // cout << endl;                      // TODO debug
    // cout << "debug_R:";                // TODO debug
    // for (auto v : R) cout << " " << v; // TODO debug
    // cout << endl;                      // TODO debug
    // vector<int> D(N - 1);
    // for (int i = 0; i < N - 1; i++) {
    //// D[i] = A[i + 1] - A[i];
    // D[i] = S[i + 1] - S[i];
    //}
    // cout << "debug_D:";                // TODO debug
    // for (auto v : D) cout << " " << v; // TODO debug
    // cout << endl;                      // TODO debug
    // vector<vector<int>> SS(N + 1, vector<int>(N + 1));
    // for (int i = 0; i < N; i++) {
    // for (int j = 0; j < N; j++) {
    // SS[i + 1][j + 1] = SS[i][j + 1] + SS[i + 1][j] - SS[i][j] + A[i][j];
    //}
    //}
    // vector<vector<long long>> SSS(H + 1, vector<int>(W + 1));
    // for (int i = 0; i < H; i++) {
    // for (int j = 0; j < W; j++) {
    // SSS[i + 1][j + 1] =
    // SSS[i][j + 1] + SSS[i + 1][j] - SSS[i][j] + A[i][j];
    //}
    //}
    int H = 3, W = 3;
    vector<vector<int>> T(H, vector<int>(W, 1));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
    cout << "=============" << endl;
    vector<vector<long long>> Z(H + 1, vector<long long>(W + 1));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            Z[i + 1][j + 1] = Z[i + 1][j] + T[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            Z[i + 1][j + 1] += Z[i][j + 1];
        }
    }
    for (int i = 0; i < H + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            cout << Z[i][j] << " ";
        }
        cout << endl;
    }
}
