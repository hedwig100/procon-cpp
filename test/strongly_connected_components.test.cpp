#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include <bits/stdc++.h>
using namespace std;
#include "../graph/strongly_connected_components.cpp"

int main() {
    int n, m;
    cin >> n >> m;
    StronglyConnectedComponents scc(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        scc.add_edge(a, b);
    }
    scc.build(false);

    cout << scc.N_scc << '\n';
    for (int i = 0; i < scc.N_scc; i++) {
        cout << (int)(scc.scc_group[i].size()) << ' ';
        for (int &u : scc.scc_group[i]) {
            cout << u << " ";
        }
        cout << '\n';
    }
    return 0;
}