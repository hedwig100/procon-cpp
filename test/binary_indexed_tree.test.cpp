#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../data_structures/binary_indexed_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    BinaryIndexedTree<long long> bit(N);
    bit.build(A);

    int t, p, x, l, r;
    for (int i = 0; i < Q; i++) {
        cin >> t;
        if (t == 0) {
            cin >> p >> x;
            bit.add(p, x);
        } else {
            cin >> l >> r;
            cout << bit.sum(l, r) << '\n';
        }
    }

    return 0;
}
