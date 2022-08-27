#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Bfs {
    int n;
    vector<vector<int>> G;
    vector<int> dist, prev_v;

    // Bfs
    // nは頂点数, Gはグラフを隣接リスト形式で持ったもの
    Bfs(int n, vector<vector<int>> G) : n(n), G(G) {
        dist.assign(n, -1);
        prev_v.assign(n, -1);
    }

    // shortest_path
    // 頂点sから他の任意の頂点までの最短距離を求める.
    // 制約: 0 <= s < n
    void shortest_path(int s) {
        fill(dist.begin(), dist.end(), -1);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto &u : G[v]) {
                if (dist[u] >= 0) continue;
                dist[u]   = dist[v] + 1;
                prev_v[u] = v;
                q.push(u);
            }
        }
    }

    // restore_path
    // 頂点sからtまでの最短経路を求める。
    // 最短経路が存在する場合, 返り値は先頭にs,tを含む. 存在しないとき空を返す.
    // 制約: sは以前にshortest_path(s)が呼ばれている. 0 <= t < n
    // 未Verify
    vector<int> restore_path(int s, int t) {
        if (dist[s] != 0) {
            cerr << "error when restore_path() is called.";
            exit(1);
        }
        if (dist[t] < 0) return {};

        vector<int> ret;
        int now_v = t;
        ret.push_back(now_v);
        while (now_v != s) {
            now_v = prev_v[now_v];
            ret.push_back(now_v);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};