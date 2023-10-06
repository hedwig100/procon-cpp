---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/constrained_maxflow.cpp
    title: graph/constrained_maxflow.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dinic.test.cpp
    title: test/dinic.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dinic.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Dinic\n// \u6700\u5927\u6D41\u3092\u6C42\u3081\u308B.\ntemplate <typename\
    \ T, const T INF>\nstruct Dinic {\n    struct edge {\n        int to, rev;\n \
    \       T cap;\n        edge() {}\n        edge(int to, T cap, int rev) : to(to),\
    \ rev(rev), cap(cap) {}\n    };\n\n    int n;\n    vector<vector<edge>> G;\n \
    \   vector<int> level, iter;\n\n    Dinic(int n = 0) : n(n) {\n        G.resize(n);\n\
    \        level.resize(n);\n        iter.resize(n);\n    }\n\n    // resize\n \
    \   // \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\u3092n\u306B\u3059\u308B. \u30B0\
    \u30E9\u30D5\u69CB\u7BC9\u5F8C\u306B\u547C\u3093\u3067\u3082\u591A\u5206\u58CA\
    \u308C\u306A\u3044\u304C, \u30B0\u30E9\u30D5\u306E\u69CB\u7BC9\u524D\u306B\u547C\
    \u3076\u3079\u304D\n    // \u5236\u7D04: n >= 0\n    void resize(int n) {\n  \
    \      G.resize(n);\n        level.resize(n);\n        iter.resize(n);\n    }\n\
    \n    // add_edge\n    // a\u304B\u3089b\u3078\u5BB9\u91CFc\u306E\u8FBA\u3092\u306F\
    \u308B.\n    // \u5236\u7D04: 0 <= a,b < n,c >= 0\n    void add_edge(int a, int\
    \ b, T c) {\n        G[a].push_back(edge{b, c, (int)G[b].size()});\n        G[b].push_back(edge{a,\
    \ T(0), (int)G[a].size() - 1});\n    }\n\n    void bfs(int s) {\n        fill(level.begin(),\
    \ level.end(), -1);\n        level[s] = 0;\n        queue<int> q;\n        q.push(s);\n\
    \        while (!q.empty()) {\n            int v = q.front();\n            q.pop();\n\
    \            for (const auto &e : G[v]) {\n                if (e.cap > 0 && level[e.to]\
    \ < 0) {\n                    level[e.to] = level[v] + 1;\n                  \
    \  q.push(e.to);\n                }\n            }\n        }\n    }\n\n    T\
    \ dfs(int v, int t, T f) {\n        if (v == t) return f;\n        for (int &i\
    \ = iter[v]; i < (int)G[v].size(); i++) {\n            edge &e = G[v][i];\n  \
    \          if (e.cap > 0 && level[v] < level[e.to]) {\n                T d = dfs(e.to,\
    \ t, min(f, e.cap));\n                if (d > 0) {\n                    e.cap\
    \ -= d;\n                    G[e.to][e.rev].cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\n\
    \    // solve\n    // s\u304B\u3089t\u3078\u306E\u6700\u5927\u6D41\u3092\u6C42\
    \u3081\u308B.\n    // \u5236\u7D04: 0 <= s,t < n\n    // \u8A08\u7B97\u91CF: O(|V|^2|E|)\n\
    \    T solve(int s, int t) {\n        T flow = T(0);\n        for (;;) {\n   \
    \         bfs(s);\n            if (level[t] < 0) return flow;\n            fill(iter.begin(),\
    \ iter.end(), 0);\n            T f;\n            while ((f = dfs(s, t, INF)) >\
    \ 0) {\n                flow += f;\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Dinic\n\
    // \u6700\u5927\u6D41\u3092\u6C42\u3081\u308B.\ntemplate <typename T, const T\
    \ INF>\nstruct Dinic {\n    struct edge {\n        int to, rev;\n        T cap;\n\
    \        edge() {}\n        edge(int to, T cap, int rev) : to(to), rev(rev), cap(cap)\
    \ {}\n    };\n\n    int n;\n    vector<vector<edge>> G;\n    vector<int> level,\
    \ iter;\n\n    Dinic(int n = 0) : n(n) {\n        G.resize(n);\n        level.resize(n);\n\
    \        iter.resize(n);\n    }\n\n    // resize\n    // \u30B0\u30E9\u30D5\u306E\
    \u9802\u70B9\u6570\u3092n\u306B\u3059\u308B. \u30B0\u30E9\u30D5\u69CB\u7BC9\u5F8C\
    \u306B\u547C\u3093\u3067\u3082\u591A\u5206\u58CA\u308C\u306A\u3044\u304C, \u30B0\
    \u30E9\u30D5\u306E\u69CB\u7BC9\u524D\u306B\u547C\u3076\u3079\u304D\n    // \u5236\
    \u7D04: n >= 0\n    void resize(int n) {\n        G.resize(n);\n        level.resize(n);\n\
    \        iter.resize(n);\n    }\n\n    // add_edge\n    // a\u304B\u3089b\u3078\
    \u5BB9\u91CFc\u306E\u8FBA\u3092\u306F\u308B.\n    // \u5236\u7D04: 0 <= a,b <\
    \ n,c >= 0\n    void add_edge(int a, int b, T c) {\n        G[a].push_back(edge{b,\
    \ c, (int)G[b].size()});\n        G[b].push_back(edge{a, T(0), (int)G[a].size()\
    \ - 1});\n    }\n\n    void bfs(int s) {\n        fill(level.begin(), level.end(),\
    \ -1);\n        level[s] = 0;\n        queue<int> q;\n        q.push(s);\n   \
    \     while (!q.empty()) {\n            int v = q.front();\n            q.pop();\n\
    \            for (const auto &e : G[v]) {\n                if (e.cap > 0 && level[e.to]\
    \ < 0) {\n                    level[e.to] = level[v] + 1;\n                  \
    \  q.push(e.to);\n                }\n            }\n        }\n    }\n\n    T\
    \ dfs(int v, int t, T f) {\n        if (v == t) return f;\n        for (int &i\
    \ = iter[v]; i < (int)G[v].size(); i++) {\n            edge &e = G[v][i];\n  \
    \          if (e.cap > 0 && level[v] < level[e.to]) {\n                T d = dfs(e.to,\
    \ t, min(f, e.cap));\n                if (d > 0) {\n                    e.cap\
    \ -= d;\n                    G[e.to][e.rev].cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\n\
    \    // solve\n    // s\u304B\u3089t\u3078\u306E\u6700\u5927\u6D41\u3092\u6C42\
    \u3081\u308B.\n    // \u5236\u7D04: 0 <= s,t < n\n    // \u8A08\u7B97\u91CF: O(|V|^2|E|)\n\
    \    T solve(int s, int t) {\n        T flow = T(0);\n        for (;;) {\n   \
    \         bfs(s);\n            if (level[t] < 0) return flow;\n            fill(iter.begin(),\
    \ iter.end(), 0);\n            T f;\n            while ((f = dfs(s, t, INF)) >\
    \ 0) {\n                flow += f;\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/dinic.cpp
  requiredBy:
  - graph/constrained_maxflow.cpp
  timestamp: '2023-01-29 11:16:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dinic.test.cpp
documentation_of: graph/dinic.cpp
layout: document
redirect_from:
- /library/graph/dinic.cpp
- /library/graph/dinic.cpp.html
title: graph/dinic.cpp
---
