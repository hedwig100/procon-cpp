#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"
#include "../data_structures/lazy_segment_tree.cpp"

int main() {
    int n, q;
    cin >> n >> q;

    using Mon   = long long;
    using OpMon = long long;
    LazySegmentTree<Mon, OpMon>
        lst(
            n,
            [](const Mon &x, const Mon &y) { return min(x, y); },
            (1LL << 31) - 1,
            [](const OpMon &a, const OpMon &b) {
                if (b < 0) return a;
                return b;
            },
            -1,
            [](const Mon &x, const OpMon &a) {
                if (a < 0) return x;
                return a;
            });

    int s, t, x, typ;
    for (int i = 0; i < q; i++) {
        cin >> typ;
        if (typ == 0) {
            cin >> s >> t >> x;
            lst.apply(s, t + 1, x);
        } else {
            cin >> s >> t;
            cout << lst.prod(s, t + 1) << '\n';
        }
    }

    return 0;
}