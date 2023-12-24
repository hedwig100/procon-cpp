#include <bits/stdc++.h>
using namespace std;

#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"
#include "../graph/dijkstra.cpp"
#include "../template/const.hpp"

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    Dijkstra<int, INF> dij(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dij.add_edge(a, b, c);
    }

    auto dist = dij.solve(s);
    for (auto &a : dist) {
        if (a == INF)
            cout << "INF\n";
        else
            cout << a << '\n';
    }
    return 0;
}