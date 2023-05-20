---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bfs.test.cpp
    title: test/bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/bfs.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Bfs\n// n\u306F\u9802\u70B9\u6570, G\u306F\u30B0\u30E9\u30D5\u3092\
    \u96A3\u63A5\u30EA\u30B9\u30C8\u5F62\u5F0F\u3067\u6301\u3063\u305F\u3082\u306E\
    \ntemplate <typename T>\nstruct Bfs {\n    int n;\n    vector<vector<int>> G;\n\
    \    vector<int> dist, prev_v;\n\n    Bfs(int n, vector<vector<int>> G) : n(n),\
    \ G(G) {\n        dist.assign(n, -1);\n        prev_v.assign(n, -1);\n    }\n\n\
    \    // shortest_path\n    // \u9802\u70B9s\u304B\u3089\u4ED6\u306E\u4EFB\u610F\
    \u306E\u9802\u70B9\u307E\u3067\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\
    \u308B.\n    // \u5236\u7D04: 0 <= s < n\n    void shortest_path(int s) {\n  \
    \      fill(dist.begin(), dist.end(), -1);\n        dist[s] = 0;\n        queue<int>\
    \ q;\n        q.push(s);\n        while (!q.empty()) {\n            int v = q.front();\n\
    \            q.pop();\n            for (auto &u : G[v]) {\n                if\
    \ (dist[u] >= 0) continue;\n                dist[u]   = dist[v] + 1;\n       \
    \         prev_v[u] = v;\n                q.push(u);\n            }\n        }\n\
    \    }\n\n    // restore_path\n    // \u9802\u70B9s\u304B\u3089t\u307E\u3067\u306E\
    \u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\u3002\n    // \u6700\u77ED\u7D4C\
    \u8DEF\u304C\u5B58\u5728\u3059\u308B\u5834\u5408, \u8FD4\u308A\u5024\u306F\u5148\
    \u982D\u306Bs,t\u3092\u542B\u3080. \u5B58\u5728\u3057\u306A\u3044\u3068\u304D\u7A7A\
    \u3092\u8FD4\u3059.\n    // \u5236\u7D04: s\u306F\u4EE5\u524D\u306Bshortest_path(s)\u304C\
    \u547C\u3070\u308C\u3066\u3044\u308B. 0 <= t < n\n    // \u672AVerify\n    vector<int>\
    \ restore_path(int s, int t) {\n        if (dist[s] != 0) {\n            cerr\
    \ << \"error when restore_path() is called.\";\n            exit(1);\n       \
    \ }\n        if (dist[t] < 0) return {};\n\n        vector<int> ret;\n       \
    \ int now_v = t;\n        ret.push_back(now_v);\n        while (now_v != s) {\n\
    \            now_v = prev_v[now_v];\n            ret.push_back(now_v);\n     \
    \   }\n        reverse(ret.begin(), ret.end());\n        return ret;\n    }\n\
    };\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Bfs\n\
    // n\u306F\u9802\u70B9\u6570, G\u306F\u30B0\u30E9\u30D5\u3092\u96A3\u63A5\u30EA\
    \u30B9\u30C8\u5F62\u5F0F\u3067\u6301\u3063\u305F\u3082\u306E\ntemplate <typename\
    \ T>\nstruct Bfs {\n    int n;\n    vector<vector<int>> G;\n    vector<int> dist,\
    \ prev_v;\n\n    Bfs(int n, vector<vector<int>> G) : n(n), G(G) {\n        dist.assign(n,\
    \ -1);\n        prev_v.assign(n, -1);\n    }\n\n    // shortest_path\n    // \u9802\
    \u70B9s\u304B\u3089\u4ED6\u306E\u4EFB\u610F\u306E\u9802\u70B9\u307E\u3067\u306E\
    \u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B.\n    // \u5236\u7D04: 0 <= s\
    \ < n\n    void shortest_path(int s) {\n        fill(dist.begin(), dist.end(),\
    \ -1);\n        dist[s] = 0;\n        queue<int> q;\n        q.push(s);\n    \
    \    while (!q.empty()) {\n            int v = q.front();\n            q.pop();\n\
    \            for (auto &u : G[v]) {\n                if (dist[u] >= 0) continue;\n\
    \                dist[u]   = dist[v] + 1;\n                prev_v[u] = v;\n  \
    \              q.push(u);\n            }\n        }\n    }\n\n    // restore_path\n\
    \    // \u9802\u70B9s\u304B\u3089t\u307E\u3067\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\
    \u6C42\u3081\u308B\u3002\n    // \u6700\u77ED\u7D4C\u8DEF\u304C\u5B58\u5728\u3059\
    \u308B\u5834\u5408, \u8FD4\u308A\u5024\u306F\u5148\u982D\u306Bs,t\u3092\u542B\u3080\
    . \u5B58\u5728\u3057\u306A\u3044\u3068\u304D\u7A7A\u3092\u8FD4\u3059.\n    //\
    \ \u5236\u7D04: s\u306F\u4EE5\u524D\u306Bshortest_path(s)\u304C\u547C\u3070\u308C\
    \u3066\u3044\u308B. 0 <= t < n\n    // \u672AVerify\n    vector<int> restore_path(int\
    \ s, int t) {\n        if (dist[s] != 0) {\n            cerr << \"error when restore_path()\
    \ is called.\";\n            exit(1);\n        }\n        if (dist[t] < 0) return\
    \ {};\n\n        vector<int> ret;\n        int now_v = t;\n        ret.push_back(now_v);\n\
    \        while (now_v != s) {\n            now_v = prev_v[now_v];\n          \
    \  ret.push_back(now_v);\n        }\n        reverse(ret.begin(), ret.end());\n\
    \        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/bfs.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/bfs.test.cpp
documentation_of: graph/bfs.cpp
layout: document
redirect_from:
- /library/graph/bfs.cpp
- /library/graph/bfs.cpp.html
title: graph/bfs.cpp
---
