#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G"
#include "../data_structures/lazy_segment_tree.cpp"

int main() {
    int n, q;
    cin >> n >> q;

    struct Mon {
        long long val, length;
    };
    using OpMon = long long;
    LazySegmentTree<Mon, OpMon>
        lst(
            n,
            [](const Mon &x, const Mon &y) { return Mon{x.val + y.val, x.length + y.length}; },
            {0, 0},
            [](const OpMon &a, const OpMon &b) { return a + b; },
            0,
            [](const Mon &x, const OpMon &a) { return Mon{x.val + x.length * a, x.length}; });

    vector<Mon> A(n, Mon{0, 1});
    lst.build(A);
    int s, t, x, typ;
    for (int i = 0; i < q; i++) {
        cin >> typ;
        if (typ == 0) {
            cin >> s >> t >> x;
            lst.apply(s - 1, t, x);
        } else {
            cin >> s >> t;
            cout << lst.prod(s - 1, t).val << '\n';
        }
    }

    return 0;
}