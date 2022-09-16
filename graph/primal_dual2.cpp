#pragma once
#include <bits/stdc++.h>
using namespace std;

// PrimalDual2
// berumanford法を用いて最小費用流を求める.
// 最初のグラフには負閉路が含まれてはいけない.
template <typename Cap, typename Cost, const Cost INF>
struct PrimalDual2 {
    struct edge {
        int to;
        Cap cap;
        Cost cost;
        int rev;
    };

    int n;
    vector<vector<edge>> G;
    vector<Cost> dist;
    vector<int> prevv, preve;

    PrimalDual2(int n) : n(n) {
        G.resize(n);
        dist.resize(n);
        prevv.resize(n);
        preve.resize(n);
    }

    // add_edge
    // fromからtoへ容量cap, コストcostの辺を張る.
    // すでに逆辺が貼られている場合, 壊れる.
    // 制約: 0 <= from,to < n,cap >= 0,
    void add_edge(int from, int to, Cap cap, Cost cost) {
        G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
    }

    // beruman
    int beruman(int s, int t) {
        fill(dist.begin(), dist.end(), INF);
        dist[s]     = 0;
        bool update = true;
        while (update) {
            update = false;
            for (int v = 0; v < n; v++) {
                if (dist[v] == INF) continue;
                for (int i = 0; i < (int)G[v].size(); i++) {
                    edge &e = G[v][i];
                    if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                        dist[e.to]  = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update      = true;
                    }
                }
            }
        }
        return dist[t] < INF;
    }

    // solve
    // sからtへfだけ流すための最小費用を求める.
    // 制約: 0 <= s,t < n,f >= 0
    // 計算量: O(f|V||E|)
    pair<Cap, Cost> solve(int s, int t, Cap f) {
        Cost ret_cost = 0;
        Cap ret_flow  = 0;
        while (ret_flow < f) {
            if (!beruman(s, t))
                break;
            Cap d = f - ret_flow;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            ret_flow += d;
            ret_cost += d * dist[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return {ret_flow, ret_cost};
    }
};
