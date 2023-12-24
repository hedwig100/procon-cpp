#include <bits/stdc++.h>
using namespace std;

#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D"
#include "../data_structures/binary_indexed_tree.cpp"
#include "../other_algorithm/compress.cpp"

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    Compress<int> comp(A);
    BinaryIndexedTree<int> bit(comp.size());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += i - bit.sum(comp(A[i]));
        bit.add(comp(A[i]), 1);
    }
    cout << ans << '\n';

    return 0;
}