#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp"
#include "../data_structures/segment_tree.cpp"

int main() {
    int n, q;
    cin >> n >> q;
    SegmentTree<long long> st(
        n, [](long a, long b) { return min(a, b); }, (1LL << 31) - 1);

    int t;
    long long x, y;
    for (int i = 0; i < q; i++) {
        cin >> t >> x >> y;
        if (t == 0) {
            st.set(x, y);
        } else {
            cout << st.prod(x, y + 1) << '\n';
        }
    }

    return 0;
}