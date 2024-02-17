#include <bits/stdc++.h>
using namespace std;
int main() {
    auto factorial = []<class T>(T N) -> T {
        T ans = 1;
        while (N > 0) ans *= N--;
        return ans;
    };
    cout << factorial(7) << endl;
}
