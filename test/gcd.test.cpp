#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0583"
#include "../math/euclid.cpp"
#include "../math/prime.cpp"

int main() {
    int n;
    cin >> n;
    int g = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        g = gcd(g, a);
    }
    auto factors = divisor(g);
    for (const auto &p : factors)
        cout << p << '\n';
    return 0;
}