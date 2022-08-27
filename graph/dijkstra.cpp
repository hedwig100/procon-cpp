#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "../template/const.hpp"

vector<long long> dijkstra(int n, vector<vector<pair<int, long long>>> &G, int s) {
    vector<long long> dist(n, HINF);
    dist[s] = 0;

    priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> q;
    q.push({0, s});

    while (!q.empty()) {
        pair<int, long long> p = q.top();
        q.pop();
        long long d = p.first;
        int v       = p.second;
        if (dist[v] < d) continue;
        for (auto p : G[v]) {
            int e          = p.first;
            long long cost = p.second;
            if (dist[e] > dist[v] + cost) {
                dist[e] = dist[v] + cost;
                q.push({dist[e], e});
            }
        }
    }
    return dist;
}