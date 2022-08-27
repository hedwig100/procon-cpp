#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "../template/const.hpp"

// NOT VERIFIED

struct MinCostFlow {
    struct edge {
        int to, cap, cost, rev;
    };
    int N;
    vector<vector<edge>> G;
    vector<long long> dist;
    vector<int> prevv, preve;
    MinCostFlow(int N) : N(N) {
        G.resize(N);
        dist.resize(N);
        prevv.resize(N);
        preve.resize(N);
    }
    void add_edge(int from, int to, int cap, int cost) {
        G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
    }
    long long flow(int s, int t, int f) {
        long long res = 0;
        while (f > 0) {
            fill(dist.begin(), dist.end(), INF);
            dist[s]     = 0;
            bool update = true;
            while (update) {
                update = false;
                for (int v = 0; v < N; ++v) {
                    if (dist[v] == INF) continue;
                    for (int i = 0; i < (int)G[v].size(); ++i) {
                        edge &e = G[v][i];
                        if (e.cap > 0 && dist[v] + e.cost < dist[e.to]) {
                            dist[e.to]  = dist[v] + e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            update      = true;
                        }
                    }
                }
            }
            // f の　flow　はそもそも存在しない
            if (dist[t] == INF) return -1;
            int d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += (long long)d * dist[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }
};