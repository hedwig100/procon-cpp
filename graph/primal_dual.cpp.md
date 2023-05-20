---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/primal_dual.test.cpp
    title: test/primal_dual.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/primal_dual.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// PrimalDual\n// \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\
    \u7528\u3044\u3066\u6700\u5C0F\u8CBB\u7528\u6D41\u3092\u6C42\u3081\u308B.\n//\
    \ \u6700\u521D\u306E\u30B0\u30E9\u30D5\u306B\u306F\u8CA0\u9589\u8DEF\u304C\u542B\
    \u307E\u308C\u3066\u306F\u3044\u3051\u306A\u3044.\ntemplate <typename Cap, typename\
    \ Cost, const Cost INF>\nstruct PrimalDual {\n    struct edge {\n        int to;\n\
    \        Cap cap;\n        Cost cost;\n        int rev;\n    };\n\n    int n;\n\
    \    vector<vector<edge>> G;\n    vector<Cost> dist, h;\n    vector<int> prevv,\
    \ preve;\n    bool has_negative;\n\n    PrimalDual(int n) : n(n) {\n        G.resize(n);\n\
    \        dist.resize(n);\n        h.resize(n);\n        prevv.resize(n);\n   \
    \     preve.resize(n);\n        has_negative = false;\n    }\n\n    // add_edge\n\
    \    // from\u304B\u3089to\u3078\u5BB9\u91CFcap, \u30B3\u30B9\u30C8cost\u306E\u8FBA\
    \u3092\u5F35\u308B.\n    // \u5236\u7D04: 0 <= from,to < n,cap >= 0,\n    void\
    \ add_edge(int from, int to, Cap cap, Cost cost) {\n        G[from].push_back((edge){to,\
    \ cap, cost, (int)G[to].size()});\n        G[to].push_back((edge){from, 0, -cost,\
    \ (int)G[from].size() - 1});\n        if (cost < 0) has_negative = true;\n   \
    \ }\n\n    // beruman\n    int beruman(int s, int t) {\n        fill(dist.begin(),\
    \ dist.end(), INF);\n        dist[s]     = 0;\n        bool update = true;\n \
    \       while (update) {\n            update = false;\n            for (int v\
    \ = 0; v < n; v++) {\n                if (dist[v] == INF) continue;\n        \
    \        for (int i = 0; i < (int)G[v].size(); i++) {\n                    edge\
    \ &e = G[v][i];\n                    if (e.cap > 0 && dist[e.to] > dist[v] + e.cost)\
    \ {\n                        dist[e.to]  = dist[v] + e.cost;\n               \
    \         prevv[e.to] = v;\n                        preve[e.to] = i;\n       \
    \                 update      = true;\n                    }\n               \
    \ }\n            }\n        }\n        return dist[t] < INF;\n    }\n\n    using\
    \ P = pair<Cost, int>;\n    bool dijkstra(int s, int t) {\n        priority_queue<P,\
    \ vector<P>, greater<P>> q;\n        q.push(P{0, s});\n        fill(dist.begin(),\
    \ dist.end(), INF);\n        dist[s] = 0;\n        while (!q.empty()) {\n    \
    \        auto [d, v] = q.top();\n            q.pop();\n            if (dist[v]\
    \ < d) continue;\n            for (int i = 0; i < (int)G[v].size(); i++) {\n \
    \               edge &e = G[v][i];\n                if (e.cap > 0 && dist[e.to]\
    \ > dist[v] + e.cost + h[v] - h[e.to]) {\n                    dist[e.to]  = dist[v]\
    \ + e.cost + h[v] - h[e.to];\n                    prevv[e.to] = v;\n         \
    \           preve[e.to] = i;\n                    q.push(P{dist[e.to], e.to});\n\
    \                }\n            }\n        }\n        return dist[t] < INF;\n\
    \    }\n\n    // solve\n    // s\u304B\u3089t\u3078f\u3060\u3051\u6D41\u3059\u305F\
    \u3081\u306E\u6700\u5C0F\u8CBB\u7528\u3092\u6C42\u3081\u308B.\n    // \u5236\u7D04\
    : 0 <= s,t < n,f >= 0\n    // \u8A08\u7B97\u91CF: O(|V||E| + f|E|log|V|)\n   \
    \ pair<Cap, Cost> solve(int s, int t, Cap f) {\n        Cost ret_cost    = 0;\n\
    \        Cap ret_flow     = 0;\n        bool use_beruman = has_negative;\n   \
    \     while (ret_flow < f) {\n            if (use_beruman) {\n               \
    \ if (!beruman(s, t)) break;\n                use_beruman = false;\n         \
    \   } else {\n                if (!dijkstra(s, t)) break;\n            }\n\n \
    \           // update h,f,d\n            for (int v = 0; v < n; v++)\n       \
    \         h[v] += dist[v];\n\n            Cap d = f - ret_flow;\n            for\
    \ (int v = t; v != s; v = prevv[v]) {\n                d = min(d, G[prevv[v]][preve[v]].cap);\n\
    \            }\n\n            ret_flow += d;\n            ret_cost += d * h[t];\n\
    \            for (int v = t; v != s; v = prevv[v]) {\n                edge &e\
    \ = G[prevv[v]][preve[v]];\n                e.cap -= d;\n                G[v][e.rev].cap\
    \ += d;\n            }\n        }\n        return {ret_flow, ret_cost};\n    }\n\
    };\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// PrimalDual\n\
    // \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u7528\u3044\u3066\u6700\u5C0F\u8CBB\
    \u7528\u6D41\u3092\u6C42\u3081\u308B.\n// \u6700\u521D\u306E\u30B0\u30E9\u30D5\
    \u306B\u306F\u8CA0\u9589\u8DEF\u304C\u542B\u307E\u308C\u3066\u306F\u3044\u3051\
    \u306A\u3044.\ntemplate <typename Cap, typename Cost, const Cost INF>\nstruct\
    \ PrimalDual {\n    struct edge {\n        int to;\n        Cap cap;\n       \
    \ Cost cost;\n        int rev;\n    };\n\n    int n;\n    vector<vector<edge>>\
    \ G;\n    vector<Cost> dist, h;\n    vector<int> prevv, preve;\n    bool has_negative;\n\
    \n    PrimalDual(int n) : n(n) {\n        G.resize(n);\n        dist.resize(n);\n\
    \        h.resize(n);\n        prevv.resize(n);\n        preve.resize(n);\n  \
    \      has_negative = false;\n    }\n\n    // add_edge\n    // from\u304B\u3089\
    to\u3078\u5BB9\u91CFcap, \u30B3\u30B9\u30C8cost\u306E\u8FBA\u3092\u5F35\u308B\
    .\n    // \u5236\u7D04: 0 <= from,to < n,cap >= 0,\n    void add_edge(int from,\
    \ int to, Cap cap, Cost cost) {\n        G[from].push_back((edge){to, cap, cost,\
    \ (int)G[to].size()});\n        G[to].push_back((edge){from, 0, -cost, (int)G[from].size()\
    \ - 1});\n        if (cost < 0) has_negative = true;\n    }\n\n    // beruman\n\
    \    int beruman(int s, int t) {\n        fill(dist.begin(), dist.end(), INF);\n\
    \        dist[s]     = 0;\n        bool update = true;\n        while (update)\
    \ {\n            update = false;\n            for (int v = 0; v < n; v++) {\n\
    \                if (dist[v] == INF) continue;\n                for (int i = 0;\
    \ i < (int)G[v].size(); i++) {\n                    edge &e = G[v][i];\n     \
    \               if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {\n          \
    \              dist[e.to]  = dist[v] + e.cost;\n                        prevv[e.to]\
    \ = v;\n                        preve[e.to] = i;\n                        update\
    \      = true;\n                    }\n                }\n            }\n    \
    \    }\n        return dist[t] < INF;\n    }\n\n    using P = pair<Cost, int>;\n\
    \    bool dijkstra(int s, int t) {\n        priority_queue<P, vector<P>, greater<P>>\
    \ q;\n        q.push(P{0, s});\n        fill(dist.begin(), dist.end(), INF);\n\
    \        dist[s] = 0;\n        while (!q.empty()) {\n            auto [d, v] =\
    \ q.top();\n            q.pop();\n            if (dist[v] < d) continue;\n   \
    \         for (int i = 0; i < (int)G[v].size(); i++) {\n                edge &e\
    \ = G[v][i];\n                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost +\
    \ h[v] - h[e.to]) {\n                    dist[e.to]  = dist[v] + e.cost + h[v]\
    \ - h[e.to];\n                    prevv[e.to] = v;\n                    preve[e.to]\
    \ = i;\n                    q.push(P{dist[e.to], e.to});\n                }\n\
    \            }\n        }\n        return dist[t] < INF;\n    }\n\n    // solve\n\
    \    // s\u304B\u3089t\u3078f\u3060\u3051\u6D41\u3059\u305F\u3081\u306E\u6700\u5C0F\
    \u8CBB\u7528\u3092\u6C42\u3081\u308B.\n    // \u5236\u7D04: 0 <= s,t < n,f >=\
    \ 0\n    // \u8A08\u7B97\u91CF: O(|V||E| + f|E|log|V|)\n    pair<Cap, Cost> solve(int\
    \ s, int t, Cap f) {\n        Cost ret_cost    = 0;\n        Cap ret_flow    \
    \ = 0;\n        bool use_beruman = has_negative;\n        while (ret_flow < f)\
    \ {\n            if (use_beruman) {\n                if (!beruman(s, t)) break;\n\
    \                use_beruman = false;\n            } else {\n                if\
    \ (!dijkstra(s, t)) break;\n            }\n\n            // update h,f,d\n   \
    \         for (int v = 0; v < n; v++)\n                h[v] += dist[v];\n\n  \
    \          Cap d = f - ret_flow;\n            for (int v = t; v != s; v = prevv[v])\
    \ {\n                d = min(d, G[prevv[v]][preve[v]].cap);\n            }\n\n\
    \            ret_flow += d;\n            ret_cost += d * h[t];\n            for\
    \ (int v = t; v != s; v = prevv[v]) {\n                edge &e = G[prevv[v]][preve[v]];\n\
    \                e.cap -= d;\n                G[v][e.rev].cap += d;\n        \
    \    }\n        }\n        return {ret_flow, ret_cost};\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/primal_dual.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/primal_dual.test.cpp
documentation_of: graph/primal_dual.cpp
layout: document
redirect_from:
- /library/graph/primal_dual.cpp
- /library/graph/primal_dual.cpp.html
title: graph/primal_dual.cpp
---
