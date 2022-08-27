#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "../template/const.hpp"

struct edge {
    int a, b;
    long long c;
    edge() {}
    edge(int a, int b, long long c) : a(a), b(b), c(c) {}
};

bool find_negative = false;
vector<long long> beruman(int N, vector<edge> &edges, int s = 0) {
    vector<long long> dist(N, HINF);
    dist[s] = 0;

    for (int i = 0; i < N; ++i) {
        bool update = false;
        for (edge &e : edges) {
            if (dist[e.a] != HINF && dist[e.b] > dist[e.a] + e.c) {
                dist[e.b] = dist[e.a] + e.c;
                update    = true;
            }
        }
        if (!update) break;
        if (i == N - 1) find_negative = true;
    }
    return dist;
}
