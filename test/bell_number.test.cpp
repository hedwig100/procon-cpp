#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G"
#include "../math/bell_number.cpp"
#include "../math/mint.cpp"

using mint2 = ModInt<1000000007>;

int main() {
    int n, k;
    cin >> n >> k;
    BellNumber<mint2> bell(n, k);
    cout << bell.solve() << '\n';

    return 0;
}