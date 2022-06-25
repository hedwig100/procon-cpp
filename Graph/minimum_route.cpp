#include <bits/stdc++.h>
using namespace std;
constexpr long long HINF = 1000000000000000;

//---------------- dijkstra --------------
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

//---------------------- beruman ford -----------------------

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
