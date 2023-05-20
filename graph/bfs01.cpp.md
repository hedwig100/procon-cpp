---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc005/submissions/34363432
  bundledCode: "#line 2 \"graph/bfs01.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// https://atcoder.jp/contests/arc005/submissions/34363432\n\n// Bfs01\n\
    // n\u306F\u9802\u70B9\u6570, G\u306F\u96A3\u63A5\u30EA\u30B9\u30C8\u3067\u96A3\
    \u63A5\u9802\u70B9\u3068\u305D\u306E\u9802\u70B9\u3068\u306E\u8DDD\u96E2(0 or\
    \ 1)\u3092\u3082\u3064\nstruct Bfs01 {\n    int n;\n    vector<vector<pair<int,\
    \ int>>> G;\n    vector<int> dist;\n\n    Bfs01(int n, vector<vector<pair<int,\
    \ int>>> &G) : n(n), G(G) {\n        dist.assign(n, -1);\n    }\n\n    // shortest_path\n\
    \    // \u9802\u70B9s\u304B\u3089\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\
    \u308B.\n    // \u5236\u7D04: 0 <= s < n\n    void shortest_path(int s) {\n  \
    \      fill(dist.begin(), dist.end(), -1);\n        dist[s] = 0;\n\n        deque<int>\
    \ q;\n        q.push_back(s);\n        while (!q.empty()) {\n            int v\
    \ = q.front();\n            q.pop_front();\n            for (auto &p : G[v]) {\n\
    \                auto [u, c] = p;\n                if (dist[u] >= 0) continue;\n\
    \                dist[u] = dist[v] + c;\n                if (c == 0)\n       \
    \             q.push_front(u);\n                else\n                    q.push_back(u);\n\
    \            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// https://atcoder.jp/contests/arc005/submissions/34363432\n\
    \n// Bfs01\n// n\u306F\u9802\u70B9\u6570, G\u306F\u96A3\u63A5\u30EA\u30B9\u30C8\
    \u3067\u96A3\u63A5\u9802\u70B9\u3068\u305D\u306E\u9802\u70B9\u3068\u306E\u8DDD\
    \u96E2(0 or 1)\u3092\u3082\u3064\nstruct Bfs01 {\n    int n;\n    vector<vector<pair<int,\
    \ int>>> G;\n    vector<int> dist;\n\n    Bfs01(int n, vector<vector<pair<int,\
    \ int>>> &G) : n(n), G(G) {\n        dist.assign(n, -1);\n    }\n\n    // shortest_path\n\
    \    // \u9802\u70B9s\u304B\u3089\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\
    \u308B.\n    // \u5236\u7D04: 0 <= s < n\n    void shortest_path(int s) {\n  \
    \      fill(dist.begin(), dist.end(), -1);\n        dist[s] = 0;\n\n        deque<int>\
    \ q;\n        q.push_back(s);\n        while (!q.empty()) {\n            int v\
    \ = q.front();\n            q.pop_front();\n            for (auto &p : G[v]) {\n\
    \                auto [u, c] = p;\n                if (dist[u] >= 0) continue;\n\
    \                dist[u] = dist[v] + c;\n                if (c == 0)\n       \
    \             q.push_front(u);\n                else\n                    q.push_back(u);\n\
    \            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/bfs01.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bfs01.cpp
layout: document
redirect_from:
- /library/graph/bfs01.cpp
- /library/graph/bfs01.cpp.html
title: graph/bfs01.cpp
---
