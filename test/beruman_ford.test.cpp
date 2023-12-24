#include <bits/stdc++.h>
using namespace std;

#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/"                                  \
    "description.jsp?id=GRL_1_B&lang=jp"
#include "../graph/beruman_ford.cpp"
#include "../template/const.hpp"

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    BerumanFord<int, INF> bf(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bf.add_edge(a, b, c);
    }

    auto dist = bf.solve(s);
    if (bf.find_negloop_from_s())
        cout << "NEGATIVE CYCLE\n";
    else {
        for (auto &a : dist) {
            if (a == INF)
                cout << "INF\n";
            else
                cout << a << '\n';
        }
    }
    return 0;
}