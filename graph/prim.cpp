#pragma once
#include <bits/stdc++.h>
using namespace std;

// Prim
// Prim法で最小全域木を求める.
template <typename T, const T INF> struct Prim {
    struct edge {
        int to;
        T cost;
        int id;

        edge(int to, T c, int id) : to(to), cost(c), id(id) {}
    };
    function<bool(const edge &, const edge &)> compare =
        [](const edge &a, const edge &b) { return a.cost > b.cost; };

    int n;
    int m = 0;
    vector<int> used_id;
    vector<vector<edge>> G;

    Prim(int n) : n(n) { G.resize(n); }

    // add_edge
    // aとbの間にコストcの無向辺をはる
    void add_edge(int a, int b, T c) {
        G[a].emplace_back(b, c, m);
        G[b].emplace_back(a, c, m++);
    }

    // solve
    // 最小全域木を求める.
    // 計算量: O(|E|log|V|)
    T solve() {
        used_id.assign(m, 0);
        T ans = T(0);
        vector<int> visited(n, 0);
        priority_queue<edge, vector<edge>, decltype(compare)> q{compare};
        q.emplace(0, 0, -1);

        while (!q.empty()) {
            edge e = q.top();
            q.pop();
            if (visited[e.to]) continue;
            if (e.id >= 0) used_id[e.id] = 1;
            ans += e.cost;
            visited[e.to] = 1;
            for (const edge &e2 : G[e.to]) {
                if (visited[e2.to]) continue;
                q.push(e2);
            }
        }
        return ans;
    }
};