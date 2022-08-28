#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_I"
#include "../math/mint.cpp"
#include "../math/stirling_number2.cpp"

using mint2 = ModInt<1000000007>;

int main() {
    int n, k;
    cin >> n >> k;
    StirlingNumber2<mint2> s2(n, k);
    cout << s2.solve() << '\n';
    return 0;
}
