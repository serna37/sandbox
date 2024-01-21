#include <bits/stdc++.h>
using namespace std;
int main() {
    auto test = []<class T>(T test) -> void {
        int a = 1;
        T ee = test;
        cout << ee << endl;
        return;
    };
    test(30);
    test("asdads");
    auto digitsum = []<class T>(T a, int N = 10) -> T {
        T ans = 0;
        while (a != 0) {
            ans += a % N;
            a /= N;
        }
        return ans;
    };
    cout << digitsum(345) << endl;
}
