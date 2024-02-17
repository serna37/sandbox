#include <bits/stdc++.h>
using namespace std;
int main() {
    const long long MOD = 998244353;
    vector<long long> mf;
    auto modfact = [&](int x) -> long long {
        if ((int)mf.size() > x) return mf[x];
        if (mf.empty()) mf.push_back(1);
        for (int i = mf.size(); i <= x; i++) mf.push_back(mf.back() * i % MOD);
        return mf[x];
    };
    vector<long long> S;
    vector<long long> cvt = S;
    sort(cvt.begin(), cvt.end());
    cvt.erase(unique(cvt.begin(), cvt.end()), cvt.end());
    for (auto &v : S) v = lower_bound(cvt.begin(), cvt.end(), v) - cvt.begin();
    int cnt = cvt.size();
}
