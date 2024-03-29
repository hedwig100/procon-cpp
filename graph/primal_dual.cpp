#pragma once
#include <bits/stdc++.h>
using namespace std;

// PrimalDual
// ポテンシャルを用いて最小費用流を求める.
// 最初のグラフには負閉路が含まれてはいけない.
template <typename Cap, typename Cost, const Cost INF>
struct PrimalDual {
    struct edge {
        int to;
        Cap cap;
        Cost cost;
        int rev;
    };

    int n;
    vector<vector<edge>> G;
    vector<Cost> dist, h;
    vector<int> prevv, preve;
    bool has_negative;

    PrimalDual(int n) : n(n) {
        G.resize(n);
        dist.resize(n);
        h.resize(n);
        prevv.resize(n);
        preve.resize(n);
        has_negative = false;
    }

    // add_edge
    // fromからtoへ容量cap, コストcostの辺を張る.
    // 制約: 0 <= from,to < n,cap >= 0,
    void add_edge(int from, int to, Cap cap, Cost cost) {
        G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
        if (cost < 0) has_negative = true;
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

    using P = pair<Cost, int>;
    bool dijkstra(int s, int t) {
        priority_queue<P, vector<P>, greater<P>> q;
        q.push(P{0, s});
        fill(dist.begin(), dist.end(), INF);
        dist[s] = 0;
        while (!q.empty()) {
            auto [d, v] = q.top();
            q.pop();
            if (dist[v] < d) continue;
            for (int i = 0; i < (int)G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to]  = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    q.push(P{dist[e.to], e.to});
                }
            }
        }
        return dist[t] < INF;
    }

    // solve
    // sからtへfだけ流すための最小費用を求める.
    // 制約: 0 <= s,t < n,f >= 0
    // 計算量: O(|V||E| + f|E|log|V|)
    pair<Cap, Cost> solve(int s, int t, Cap f) {
        Cost ret_cost    = 0;
        Cap ret_flow     = 0;
        bool use_beruman = has_negative;
        while (ret_flow < f) {
            if (use_beruman) {
                if (!beruman(s, t)) break;
                use_beruman = false;
            } else {
                if (!dijkstra(s, t)) break;
            }

            // update h,f,d
            for (int v = 0; v < n; v++)
                h[v] += dist[v];

            Cap d = f - ret_flow;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d, G[prevv[v]][preve[v]].cap);
            }

            ret_flow += d;
            ret_cost += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return {ret_flow, ret_cost};
    }
};