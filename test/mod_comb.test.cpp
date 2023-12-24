#include <bits/stdc++.h>
using namespace std;

#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/"                                  \
    "description.jsp?id=DPL_5_D&lang=ja"
#include "../math/mod_comb.cpp"

int main() {
    int n, k;
    cin >> n >> k;
    Combination<1000000007> comb(n + k);
    cout << comb(n + k - 1, n) << '\n';
    return 0;
}