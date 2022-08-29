#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"
#include "../graph/kruscal.cpp"
#include "../template/const.hpp"

int main() {
    int n, m;
    cin >> n >> m;
    Kruscal<int, INF> kru(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        kru.add_edge(a, b, c);
    }
    cout << kru.solve() << '\n';
    return 0;
}