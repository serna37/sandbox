#include <bits/stdc++.h>
using namespace std;

template <class Tp> class starry_sky_tree {
    vector<Tp> c;

    int roundup_powtwo(int n) const {
        if (n == 0) return 1;
        if ((n & (n - 1)) == 0) return n + 1;
        return int(1) << (64 - __builtin_clzll(n));
    }

    void init_build() {
        int m = c.size();
        for (int i = m / 2; i-- > 1;) {
            Tp mx = max(c[i << 1], c[i << 1 | 1]);
            c[i << 1] -= mx;
            c[i << 1 | 1] -= mx;
            c[i] = mx;
        }
    }

    void maintain(int i) {
        Tp mx = max(c[i << 1], c[i << 1 | 1]);
        c[i << 1] -= mx;
        c[i << 1 | 1] -= mx;
        c[i] += mx;
    }

  public:
    starry_sky_tree() {
    }

    starry_sky_tree(int n, const Tp &e = Tp()) {
        int m = 2 * roundup_powtwo(n);
        c.assign(m, e - e);
        c[1] = e;
    }

    template <class ForwardIt>
    starry_sky_tree(ForwardIt first, ForwardIt last) {
        int m = 2 * roundup_powtwo(distance(first, last));
        c.assign(m, *first - *first);
        for (int i = m / 2; i < m; ++i) {
            c[i] = *first++;
            if (first == last) break;
        }
        init_build();
    }

    void add(int l, int r, const Tp &x) {
        int m = c.size();
        l += m / 2;
        r += m / 2;
        while (l < r) {
            if (l & 1) {
                c[l] += x;
                ++l;
            }
            if (r & 1) {
                --r;
                c[r] += x;
            }
            if ((l - 1) > 1) maintain((l - 1) >> 1);
            if (r < m) maintain(r >> 1);
            l >>= 1;
            r >>= 1;
        }
        for (int i = l - 1; i > 1; i >>= 1) maintain(i);
        assert(r < m);
        for (int i = r; i >= 1; i >>= 1) maintain(i);
    }

    Tp max(int l, int r) const {
        assert(l < r);
        int m = c.size();
        l += m / 2;
        r += m / 2;
        vector<int> ll, rr;
        int li = l;
        int ri = r;
        while (li < ri) {
            if (li & 1) ll.push_back(li++);
            if (ri & 1) rr.push_back(--ri);
            li >>= 1;
            ri >>= 1;
        }
        cout << "debug_L:";                 // TODO debug
        for (auto v : ll) cout << " " << v; // TODO debug
        cout << endl;                       // TODO debug
        cout << "debug_R:";                 // TODO debug
        for (auto v : rr) cout << " " << v; // TODO debug
        cout << endl;                       // TODO debug
        vector<Tp> cand;
        Tp curl = c[1];
        for (int i = li - 1; i > 1; i >>= 1) curl += c[i];
        for (int i = li - 1; !ll.empty();) {
            int j = ll.back();
            (i <<= 1) |= 1;
            if (i == j) {
                cand.push_back(curl + c[i--]);
                ll.pop_back();
            }
            curl += c[i];
        }
        Tp curr = c[1];
        for (int i = ri; i > 1; i >>= 1) curr += c[i];
        for (int i = ri; !rr.empty();) {
            int j = rr.back();
            i <<= 1;
            if (i == j) {
                cand.push_back(curr + c[i++]);
                rr.pop_back();
            }
            curr += c[i];
        }
        return *max_element(cand.begin(), cand.end());
    }
};
int main() {
    int n, q;
    cin >> n >> q;
    starry_sky_tree<int> sst(n);
    while (q--) {
        int c;
        cin >> c;
        int s, t;
        cin >> s >> t;
        if (c == 0) {
            int x;
            cin >> x;
            sst.add(s, t + 1, -x);
        } else if (c == 1) {
            cout << -sst.max(s, t + 1) << endl;
        }
    }
}
