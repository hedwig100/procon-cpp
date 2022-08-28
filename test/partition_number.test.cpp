#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_J"
#include "../math/mint.cpp"
#include "../math/partition_number.cpp"

using mint2 = ModInt<1000000007>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, k;
    cin >> n >> k;
    PartitionNumber<mint2> pn(n, k);
    pn.solve();
    cout << pn(n, k) << '\n';

    return 0;
}