#include <bits/stdc++.h>
using namespace std;
template <typename ActedMonoid> struct Lazy_SegTree {
    using AM = ActedMonoid;
    using MX = typename AM::Monoid_X;
    using MA = typename AM::Monoid_A;
    using X = typename MX::value_type;
    using A = typename MA::value_type;
    int n, log, size;
    vector<X> dat;
    vector<A> laz;

    void apply(int l, int r, A a) {
        if (l == r) return;
        l += size, r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        int l2 = l, r2 = r;
        while (l < r) {
            if (l & 1) apply_at(l++, a);
            if (r & 1) apply_at(--r, a);
            l >>= 1, r >>= 1;
        }
        l = l2, r = r2;
        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

  private:
    void apply_at(int k, A a) {
        int topbit = k == 0 ? -1 : 31 - __builtin_clz(k);
        long long sz = 1 << (log - topbit);
        dat[k] = AM::act(dat[k], a, sz);
        if (k < size) laz[k] = MA::op(laz[k], a);
    }
    void push(int k) {
        if (laz[k] == MA::unit()) return;
        apply_at(2 * k, laz[k]), apply_at(2 * k + 1, laz[k]);
        laz[k] = MA::unit();
    }
};
