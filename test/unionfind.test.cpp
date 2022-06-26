#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../data_structures/unionfind.cpp"
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0)
            uf.unite(u, v);
        else if (uf.same(u, v)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}