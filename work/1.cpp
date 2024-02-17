#include <bits/stdc++.h>
using namespace std;
int main() {
    // たしざんの木だとする
    int N = 8;
    vector<int> A = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<int> seg(N << 1, 0);
    for (int i = 0; i < N; i++) {
        seg[i + N] = A[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        seg[i] = seg[i << 1 | 0] + seg[i << 1 | 1];
    }
    cout << "debug_seg:";                // TODO debug
    for (auto v : seg) cout << " " << v; // TODO debug
    cout << endl;                        // TODO debug
    // 区間の和が15以上な一番ひだりがわを知りたくなってみる
    // l~rの和のlower_bound(15)ということ
    auto func = [&](int value) -> bool { return value >= 15; };
    // lが1からみた、一番左側どこ？ ->
    // 今回だと1+2+3++5時点で初めて15になるので、答え5
    int l = 1;
    int total = 0; // 足し算の木なので0
    int r = -1;
    // 1. ダメになるタイミングを見つける
    // 根まで、区間クエリの要領で上がっていく
    l += N;
    for (; l > 0; l >>= 1) {
        if (l & 1) {
            total += seg[l]; // 足し算の木なので
            if (func(total)) {
                // 条件を満たしたら、それまでの間に境界があるはず！
                r = l; // ここよりは下だって位置をメモ
                break;
            }
            l++;
        }
    }
    // 一生条件満たさない場合はreturn end()ということだ
    if (r == -1) {
        return 0;
    }
    // 2. rを根と見てみる。
    // このノードの値を足すことでtrueになったので、このノード配下のどこかに境界があるはず
    // -> rを根として掘っていく
    total -= seg[r]; // まず最後の1回を無かったことにして
    while (r << 1 < N << 1) { // 子が木からはみ出ない間
        int left = seg[r << 1 | 0];
        if (func(total + left)) { // 左までを選んでいたとすると
            // 左の子がokなら、その中でさらに細かくみる
            r = r << 1 | 0; // 左にいけ
        } else {
            // 左の子がNGなら、そこに切り替わった瞬間がある
            r = r << 1 | 1; // 左にいけ
        }
    }
    cout << "seg-index:" << r << endl; // 13
    cout << "index:" << r - N << endl; // 5
}
