#include <bits/stdc++.h>
using namespace std;

#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"
#include "../math/euclid.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int a, b;
    cin >> a >> b;
    auto [x, y] = ext_gcd(a, b);
    cout << x << ' ' << y << '\n';
    return 0;
}