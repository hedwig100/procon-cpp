#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../data_structures/unionfind.cpp"

// Kruscal
// Kruscal法で最小全域森を求める.
template <typename T, const T INF>
struct Kruscal {
    struct edge {
        int a, b;
        T cost;
        int id;
        edge(int a, int b, T c, int id) : a(a), b(b), cost(c), id(id) {}
    };

    int n;
    int m = 0;
    vector<edge> edges;
    vector<int> used_id;

    Kruscal(int n) : n(n) {}

    // add_edge
    // aからbへコストcの辺を張る
    void add_edge(int a, int b, T c) {
        edges.emplace_back(a, b, c, m++);
    }

    // solve
    // 最小全域森を求めて, そのコストを返す.
    // 計算量: O(|E|log|E|)
    T solve() {
        used_id.assign(m, 0);
        sort(edges.begin(), edges.end(),
             [](const edge &a, const edge &b) { return a.cost < b.cost; });

        T ans = T(0);
        UnionFind uf(n);
        for (const edge &e : edges) {
            if (uf.same(e.a, e.b)) continue;
            ans += e.cost;
            used_id[e.id] = 1;
            uf.unite(e.a, e.b);
        }
        return ans;
    }
};
