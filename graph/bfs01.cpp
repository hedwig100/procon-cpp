#pragma once
#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/arc005/submissions/34363432

struct Bfs01 {
    int n;
    vector<vector<pair<int, int>>> G;
    vector<int> dist;

    // Bfs01
    // nは頂点数, Gは隣接リストで隣接頂点とその頂点との距離(0 or 1)をもつ
    Bfs01(int n, vector<vector<pair<int, int>>> &G) : n(n), G(G) {
        dist.assign(n, -1);
    }

    // shortest_path
    // 頂点sからの最短経路を求める.
    // 制約: 0 <= s < n
    void shortest_path(int s) {
        fill(dist.begin(), dist.end(), -1);
        dist[s] = 0;

        deque<int> q;
        q.push_back(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop_front();
            for (auto &p : G[v]) {
                auto [u, c] = p;
                if (dist[u] >= 0) continue;
                dist[u] = dist[v] + c;
                if (c == 0)
                    q.push_front(u);
                else
                    q.push_back(u);
            }
        }
    }
};