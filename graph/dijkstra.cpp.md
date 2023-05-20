---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dijkstra.test.cpp
    title: test/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Dijkstra\n// dijkstra\u6CD5\u3067\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\
    \u3081\u308B.\ntemplate <typename T, const T INF>\nstruct Dijkstra {\n    using\
    \ edge = pair<T, int>;\n    int n;\n\n    vector<vector<edge>> G;\n    vector<T>\
    \ dist;\n    vector<int> prev;\n    Dijkstra(int n) : n(n) {\n        G.resize(n);\n\
    \        dist.resize(n);\n        prev.resize(n);\n    }\n\n    // add_edge\n\
    \    // a\u304B\u3089b\u3078\u30B3\u30B9\u30C8c\u306E\u8FBA\u3092\u5F35\u308B\n\
    \    // \u5236\u7D04: c >= 0\n    void add_edge(int a, int b, T c) {\n       \
    \ G[a].emplace_back(c, b);\n    }\n\n    // solve\n    // s\u304B\u3089\u306E\u6700\
    \u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B.\n    // \u8A08\u7B97\u91CF: O(|E|log|V|)\n\
    \    vector<T> solve(int s = 0) {\n        fill(dist.begin(), dist.end(), INF);\n\
    \        fill(prev.begin(), prev.end(), -1);\n        dist[s] = 0;\n\n       \
    \ priority_queue<edge, vector<edge>, greater<edge>> q;\n        q.push({0, s});\n\
    \n        while (!q.empty()) {\n            edge p = q.top();\n            q.pop();\n\
    \            auto [d, v] = p;\n            if (dist[v] < d) continue;\n      \
    \      for (const auto &p : G[v]) {\n                auto [cost, u] = p;\n   \
    \             if (dist[u] > dist[v] + cost) {\n                    dist[u] = dist[v]\
    \ + cost;\n                    prev[u] = v;\n                    q.push({dist[u],\
    \ u});\n                }\n            }\n        }\n        return dist;\n  \
    \  }\n\n    // restore_path\n    // \u9802\u70B9s\u304B\u3089t\u307E\u3067\u306E\
    \u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\u3002\n    // \u6700\u77ED\u7D4C\
    \u8DEF\u304C\u5B58\u5728\u3059\u308B\u5834\u5408, \u8FD4\u308A\u5024\u306F\u5148\
    \u982D\u306Bs,t\u3092\u542B\u3080. \u5B58\u5728\u3057\u306A\u3044\u3068\u304D\u7A7A\
    \u3092\u8FD4\u3059.\n    // \u5236\u7D04: s\u306F\u4EE5\u524D\u306Bsolve(s)\u304C\
    \u547C\u3070\u308C\u3066\u3044\u308B. 0 <= t < n\n    vector<int> restore_path(int\
    \ s, int t) {\n        if (dist[t] == INF) return {};\n\n        vector<int> ret;\n\
    \        int now_v = t;\n        ret.push_back(now_v);\n        while (now_v !=\
    \ s) {\n            now_v = prev[now_v];\n            ret.push_back(now_v);\n\
    \        }\n        reverse(ret.begin(), ret.end());\n        return ret;\n  \
    \  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Dijkstra\n\
    // dijkstra\u6CD5\u3067\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B.\ntemplate\
    \ <typename T, const T INF>\nstruct Dijkstra {\n    using edge = pair<T, int>;\n\
    \    int n;\n\n    vector<vector<edge>> G;\n    vector<T> dist;\n    vector<int>\
    \ prev;\n    Dijkstra(int n) : n(n) {\n        G.resize(n);\n        dist.resize(n);\n\
    \        prev.resize(n);\n    }\n\n    // add_edge\n    // a\u304B\u3089b\u3078\
    \u30B3\u30B9\u30C8c\u306E\u8FBA\u3092\u5F35\u308B\n    // \u5236\u7D04: c >= 0\n\
    \    void add_edge(int a, int b, T c) {\n        G[a].emplace_back(c, b);\n  \
    \  }\n\n    // solve\n    // s\u304B\u3089\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\
    \u6C42\u3081\u308B.\n    // \u8A08\u7B97\u91CF: O(|E|log|V|)\n    vector<T> solve(int\
    \ s = 0) {\n        fill(dist.begin(), dist.end(), INF);\n        fill(prev.begin(),\
    \ prev.end(), -1);\n        dist[s] = 0;\n\n        priority_queue<edge, vector<edge>,\
    \ greater<edge>> q;\n        q.push({0, s});\n\n        while (!q.empty()) {\n\
    \            edge p = q.top();\n            q.pop();\n            auto [d, v]\
    \ = p;\n            if (dist[v] < d) continue;\n            for (const auto &p\
    \ : G[v]) {\n                auto [cost, u] = p;\n                if (dist[u]\
    \ > dist[v] + cost) {\n                    dist[u] = dist[v] + cost;\n       \
    \             prev[u] = v;\n                    q.push({dist[u], u});\n      \
    \          }\n            }\n        }\n        return dist;\n    }\n\n    //\
    \ restore_path\n    // \u9802\u70B9s\u304B\u3089t\u307E\u3067\u306E\u6700\u77ED\
    \u7D4C\u8DEF\u3092\u6C42\u3081\u308B\u3002\n    // \u6700\u77ED\u7D4C\u8DEF\u304C\
    \u5B58\u5728\u3059\u308B\u5834\u5408, \u8FD4\u308A\u5024\u306F\u5148\u982D\u306B\
    s,t\u3092\u542B\u3080. \u5B58\u5728\u3057\u306A\u3044\u3068\u304D\u7A7A\u3092\u8FD4\
    \u3059.\n    // \u5236\u7D04: s\u306F\u4EE5\u524D\u306Bsolve(s)\u304C\u547C\u3070\
    \u308C\u3066\u3044\u308B. 0 <= t < n\n    vector<int> restore_path(int s, int\
    \ t) {\n        if (dist[t] == INF) return {};\n\n        vector<int> ret;\n \
    \       int now_v = t;\n        ret.push_back(now_v);\n        while (now_v !=\
    \ s) {\n            now_v = prev[now_v];\n            ret.push_back(now_v);\n\
    \        }\n        reverse(ret.begin(), ret.end());\n        return ret;\n  \
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dijkstra.test.cpp
documentation_of: graph/dijkstra.cpp
layout: document
redirect_from:
- /library/graph/dijkstra.cpp
- /library/graph/dijkstra.cpp.html
title: graph/dijkstra.cpp
---
