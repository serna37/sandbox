#include <bits/stdc++.h>
using namespace std;
int main() {
    set<int> testwww;
    testwww.insert(3);
    int cnt = testwww.count(3);
    cout << cnt << endl;
    auto itr = testwww.find(3);
    cout << *itr << endl;
    int idx = itr - testwww.begin();
    cout << () << endl;
}
