#include <bits/stdc++.h>
using namespace std;

#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/"                                  \
    "description.jsp?id=GRL_4_B&lang=ja"
#include "../graph/topological_sort.cpp"

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    auto ret = topological_sort(G);
    for (auto &a : ret)
        cout << a << '\n';
    return 0;
}