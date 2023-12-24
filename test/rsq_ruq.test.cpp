#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I"
#include "../data_structures/lazy_segment_tree.cpp"

int main() {
    int n, q;
    cin >> n >> q;

    struct Mon {
        int val, length;
    };
    using OpMon    = int;
    const OpMon id = 1000000;

    auto op = [](const Mon &x, const Mon &y) {
        return Mon{x.val + y.val, x.length + y.length};
    };
    auto composition = [&](const OpMon &a, const OpMon &b) {
        if (b == id) return a;
        return b;
    };
    auto mapping = [&](const Mon &x, const OpMon &a) {
        return Mon{(a == id ? x.val : a * x.length), x.length};
    };
    LazySegmentTree<Mon, OpMon> lst(n, op, {0, 0}, composition, id, mapping);
    vector<Mon> A(n, {0, 1});
    lst.build(A);

    int typ, s, t, x;
    for (int i = 0; i < q; i++) {
        cin >> typ;
        if (typ == 0) {
            cin >> s >> t >> x;
            lst.apply(s, t + 1, x);
        } else {
            cin >> s >> t;
            cout << lst.prod(s, t + 1).val << "\n";
        }
    }
    cout << flush;
}