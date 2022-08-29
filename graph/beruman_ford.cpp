#pragma once
#include <bits/stdc++.h>
using namespace std;

// beruman_ford
// 負辺を含むグラフを受け取り, sからの最短経路を計算する.
template <typename T, const T INF>
struct BerumanFord {
    struct edge {
        int a, b;
        T c;
        edge() {}
        edge(int a, int b, T c) : a(a), b(b), c(c) {}
    };

  private:
    int n;
    vector<edge> edges;
    vector<T> dist;
    bool find_negative_from_s = false;
    vector<int> negative_loop_from_s, prev;

  public:
    BerumanFord(int n) : n(n) {
        dist.assign(n, INF);
        negative_loop_from_s.assign(n, 0);
        prev.assign(n, -1);
    }

    // add_edge
    // aからbへ辺重みcの辺をはる
    void add_edge(int a, int b, T c) {
        edges.push_back(edge{a, b, c});
    }

    // solve
    // sからの最短経路を求める. もしsから到達可能な負閉路が存在すれば
    // find_negative = trueとなる. sからの最短経路長を返す.
    // 計算量: O(|V||E|)
    vector<T> solve(int s = 0) {
        fill(dist.begin(), dist.end(), INF);
        fill(negative_loop_from_s.begin(), negative_loop_from_s.end(), 0);
        dist[s] = 0;

        for (int i = 0; i < n; ++i) {
            bool update = false;
            for (const edge &e : edges) {
                if (dist[e.a] != INF && dist[e.b] > dist[e.a] + e.c) {
                    dist[e.b] = dist[e.a] + e.c;
                    prev[e.b] = e.a;
                    update    = true;
                    if (i == n - 1) negative_loop_from_s[e.b] = 1;
                }
            }
            if (!update) break;
            if (i == n - 1) find_negative_from_s = true;
        }
        return dist;
    }

    // find_negloop_from_s
    // sから到達可能な負閉路が存在すればtrue, そうでなければfalseを返すkaesu.
    // 制約: solve()を呼んでいること
    bool find_negloop_from_s() {
        return find_negative_from_s;
    }

    // negloop_from_s
    // sからvまでの経路に負閉路が存在するならa[v]=1,そうでないときA[v]=0であるような
    // 配列Aを返す.
    // 制約: 以前にsolve()を呼んでいること
    // 計算量: O(|V||E|) (dfsとかでもっと早くできるけどあんま意味ないのでok)
    vector<int> negloop_from_s() {
        for (int i = 0; i < n; ++i) {
            for (const edge &e : edges) {
                if (negative_loop_from_s[e.a]) negative_loop_from_s[e.b] = 1;
            }
        }
        return negative_loop_from_s;
    }

    // find_neg_loop
    // (sからは到達できないものも含めて)グラフの負閉路があるかを検出する
    // 計算量: O(|V||E|)
    bool find_neg_loop() {
        bool neg_loop = false;
        vector<T> dist(n, 0);
        for (int i = 0; i < n; ++i) {
            for (const edge &e : edges) {
                if (dist[e.a] != INF && dist[e.b] > dist[e.a] + e.c) {
                    dist[e.b] = dist[e.a] + e.c;
                    if (i == n - 1) neg_loop = true;
                }
            }
        }
        return neg_loop;
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