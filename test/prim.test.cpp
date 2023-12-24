#include <bits/stdc++.h>
using namespace std;

#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"
#include "../graph/prim.cpp"
#include "../template/const.hpp"

int main() {
    int n, m;
    cin >> n >> m;
    Prim<int, INF> prim(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        prim.add_edge(a, b, c);
    }
    cout << prim.solve() << '\n';

    return 0;
}