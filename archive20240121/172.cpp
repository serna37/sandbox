#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int e = 0;
    vector<int> seg(N << 1, e);
    for (int i = 0; i < N; i++) {
        seg[i + N] = A[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        seg[i] = max(seg[i << 1 | 0], seg[i << 1 | 1]);
    }
    cout << "debug_seg:";                // TODO debug
    for (auto v : seg) cout << " " << v; // TODO debug
    cout << endl;                        // TODO debug
    auto segment_tree_lower_bound = [&]() -> void {
        // Range Max Query Segment Treeで考えてみる
        // query = N以上？
        int q;
        cin >> q;
        // 1. そもそも根がN以上か調べる
        // 2. 子を調べる→左を見る
        // 気持ち「なるべく小さいN以上」に行きたいので、左に行きたい。

        // 1-indexed
        int i = 1;
        if (seg[i] >= q) {
            cout << "seg root OK" << endl;
        } else {
            cout << "seg root NG" << endl;
            cout << "return seg.end()" << endl;
            return;
        }
        // 根から葉に最大まで行く
        // iの子が木からはみ出るなら終了
        while (i << 1 < N << 1) {
            cout << "current index: " << i << endl;
            int left = seg[i << 1 | 0];
            // ソート済み(単調増加)なら、leftがokならrightもokに決まってる
            if (left >= q) {
                cout << "left ok" << endl;
                i = i << 1 | 0; // 左の子に移動
            } else {
                cout << "left ng" << endl;
                i = i << 1 | 1; // 右の子に移動
            }
        }
        // 辿り着いたiが答え
        cout << "last index: " << i << endl;
        cout << "value: " << seg[i] << endl;
    };
    segment_tree_lower_bound();
    // 以下、入力と出力
    // 入力// 8
    // 入力// 0 1 2 3 4 5 6 7
    // // debug_seg: 7 7 3 7 1 3 5 7 0 1 2 3 4 5 6 7
    // 入力// 4
    // // seg root OK
    // // current index: 1
    // // left ng
    // // current index: 3
    // // left ok
    // // current index: 6
    // // left ok
    // // last index: 12
    // // value: 4
}
