#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A"
#include "../math/prime.cpp"

const int MAXN = 100000;

int main() {
    int n;
    cin >> n;
    cout << n << ':';
    Eratosthenes era(MAXN);
    era.build();
    for (const auto &p : era.factorize(n)) {
        for (int i = 0; i < p.second; i++)
            cout << ' ' << p.first;
    }
    cout << '\n';
}