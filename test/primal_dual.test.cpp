#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=ja"
#include "../graph/primal_dual.cpp"
#include "../template/const.hpp"

int main() {
    int n, m, f;
    cin >> n >> m >> f;
    PrimalDual<int, int, INF> pd(n);
    int u, v, c, d;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c >> d;
        pd.add_edge(u, v, c, d);
    }

    auto [actual_f, cost] = pd.solve(0, n - 1, f);
    if (actual_f < f)
        cout << -1 << '\n';
    else
        cout << cost << '\n';
    return 0;
}