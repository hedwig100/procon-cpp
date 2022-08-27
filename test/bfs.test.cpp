#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja"
#include "../graph/bfs.cpp"

int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        --u;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            --v;
            G[u].push_back(v);
        }
    }

    Bfs<int> bfs(n, G);
    bfs.shortest_path(0);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ' ' << bfs.dist[i] << '\n';
    }

    return 0;
}