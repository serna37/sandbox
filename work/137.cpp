#include <bits/stdc++.h>
using namespace std;
int main() {
    // n以下の数を数える
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    // インデックスを値とみなし、持つ値は個数
    int maxA;
    int M = maxA + 1; // max(A[i])
    vector<int> S(M << 1, 0);
    auto update = [&](int i) {
        // nに追加しながら、n以下の数を増やす
        S[i += M]++;
        while (i >>= 1) S[i] = max(S[i << 1], S[i << 1 | 1]);
    };
    auto query = [&](int l, int r) {
        int a = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            // n以下のインデックス全部の和
            // l=0, r=nの値そのもの。
            if (l & 1) a = max(a, S[l++]);
            if (r & 1) a = max(a, S[--r]);
        }
        return a;
    };
}
