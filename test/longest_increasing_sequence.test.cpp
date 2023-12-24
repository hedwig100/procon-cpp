#include <bits/stdc++.h>
using namespace std;

#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/"                                  \
    "description.jsp?id=DPL_1_D&lang=jp"
#include "../dynamic_programming/longest_increasing_sequence.cpp"
#include "../template/const.hpp"

int main() {
    int n;
    cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    LongestIncreasingSequence<long long, HINF> lis(n, A);
    cout << lis.solve() << '\n';

    return 0;
}