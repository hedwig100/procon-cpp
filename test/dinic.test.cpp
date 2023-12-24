#include <bits/stdc++.h>
using namespace std;

#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"
#include "../graph/dinic.cpp"

int main() {
    int n, m;
    cin >> n >> m;
    Dinic<int, 100000000> din(n);
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        din.add_edge(a, b, c);
    }
    cout << din.solve(0, n - 1) << '\n';
    return 0;
}