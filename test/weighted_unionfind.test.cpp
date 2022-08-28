#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330"
#include "../data_structures/weighted_unionfind.cpp"

void solve(int n, int m) {
    WeightedUnionFind<int, 0> wuf(n);
    int a, b, w;
    for (int i = 0; i < m; i++) {
        char q;
        cin >> q;
        if (q == '!') {
            cin >> a >> b >> w;
            wuf.unite(--a, --b, w);
        } else {
            cin >> a >> b;
            if (!wuf.same(--a, --b))
                cout << "UNKNOWN\n";
            else
                cout << wuf.diff(a, b) << '\n';
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        solve(n, m);
    }

    return 0;
}