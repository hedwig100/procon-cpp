#pragma once
#include <bits/stdc++.h>
using namespace std;

// Dijkstra
// dijkstra法で最短経路を求める.
template <typename T, const T INF>
struct Dijkstra {
    using edge = pair<T, int>;
    int n;

    vector<vector<edge>> G;
    vector<T> dist;
    vector<int> prev;
    Dijkstra(int n) : n(n) {
        G.resize(n);
        dist.resize(n);
        prev.resize(n);
    }

    // add_edge
    // aからbへコストcの辺を張る
    // 制約: c >= 0
    void add_edge(int a, int b, T c) {
        G[a].emplace_back(c, b);
    }

    // solve
    // sからの最短経路を求める.
    // 計算量: O(|E|log|V|)
    vector<T> solve(int s = 0) {
        fill(dist.begin(), dist.end(), INF);
        fill(prev.begin(), prev.end(), -1);
        dist[s] = 0;

        priority_queue<edge, vector<edge>, greater<edge>> q;
        q.push({0, s});

        while (!q.empty()) {
            edge p = q.top();
            q.pop();
            auto [d, v] = p;
            if (dist[v] < d) continue;
            for (const auto &p : G[v]) {
                auto [cost, u] = p;
                if (dist[u] > dist[v] + cost) {
                    dist[u] = dist[v] + cost;
                    prev[u] = v;
                    q.push({dist[u], u});
                }
            }
        }
        return dist;
    }

    // restore_path
    // 頂点sからtまでの最短経路を求める。
    // 最短経路が存在する場合, 返り値は先頭にs,tを含む. 存在しないとき空を返す.
    // 制約: sは以前にsolve(s)が呼ばれている. 0 <= t < n
    vector<int> restore_path(int s, int t) {
        if (dist[t] == INF) return {};

        vector<int> ret;
        int now_v = t;
        ret.push_back(now_v);
        while (now_v != s) {
            now_v = prev[now_v];
            ret.push_back(now_v);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
