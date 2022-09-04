#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"
#include "../data_structures/lazy_segment_tree.cpp"

int main() {
    int n, q;
    cin >> n >> q;

    using Mon   = int;
    using OpMon = int;

    auto op          = [](const Mon &x, const Mon &y) { return min(x, y); };
    auto composition = [](const OpMon &a, const OpMon &b) { return a + b; };
    auto mapping     = [](const Mon &x, const OpMon &a) { return x + a; };
    LazySegmentTree<Mon, OpMon> lst(n, op, INT_MAX, composition, 0, mapping);
    vector<Mon> A(n, 0);
    lst.build(A);

    int typ, s, t, x;
    for (int i = 0; i < q; i++) {
        cin >> typ;
        if (typ == 0) {
            cin >> s >> t >> x;
            lst.apply(s, t + 1, x);
        } else {
            cin >> s >> t;
            cout << lst.prod(s, t + 1) << "\n";
        }
    }

    return 0;
}