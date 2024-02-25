#include <bits/stdc++.h>
using namespace std;
/**
 * ok ~ ngの整数の範囲で、初めて条件を満たす整数を返す
 *
 * @param ok 条件満たす整数
 * @param ng 条件満たさない整数
 * @param test 条件式
 */
template <class T, class F> T int_bisearch(T ok, T ng, const F &test) {
    while (abs(ok - ng) > 1) {
        T mid = (ok + ng) >> 1;
        (test(mid) ? ok : ng) = mid;
    }
    return ok;
}
// TODO これ関数でなくスニペットのが良さそうじゃね
int main() {
    auto cal = [&](int a) -> bool { return a <= 10; };
    long long a = int_bisearch(3, 9, cal);
    cout << a << endl;
}
