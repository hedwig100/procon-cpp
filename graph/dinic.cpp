#pragma once
#include <bits/stdc++.h>
using namespace std;

// Dinic
// 最大流を求める.
template <typename T, const T INF>
struct Dinic {
    struct edge {
        int to, rev;
        T cap;
        edge() {}
        edge(int to, T cap, int rev) : to(to), rev(rev), cap(cap) {}
    };

    int n;
    vector<vector<edge>> G;
    vector<int> level, iter;

    Dinic(int n = 0) : n(n) {
        G.resize(n);
        level.resize(n);
        iter.resize(n);
    }

    // resize
    // グラフの頂点数をnにする. グラフ構築後に呼んでも多分壊れないが, グラフの構築前に呼ぶべき
    // 制約: n >= 0
    void resize(int n) {
        G.resize(n);
        level.resize(n);
        iter.resize(n);
    }

    // add_edge
    // aからbへ容量cの辺をはる.
    // 制約: 0 <= a,b < n,c >= 0
    void add_edge(int a, int b, T c) {
        G[a].push_back(edge{b, c, (int)G[b].size()});
        G[b].push_back(edge{a, T(0), (int)G[a].size() - 1});
    }

    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (const auto &e : G[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    T dfs(int v, int t, T f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < (int)G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    // solve
    // sからtへの最大流を求める.
    // 制約: 0 <= s,t < n
    // 計算量: O(|V|^2|E|)
    T solve(int s, int t) {
        T flow = T(0);
        for (;;) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(iter.begin(), iter.end(), 0);
            T f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
    }
};