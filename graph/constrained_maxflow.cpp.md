---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dinic.cpp
    title: graph/dinic.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/constrained_maxflow.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"graph/dinic.cpp\"\nusing namespace std;\n\n\
    // Dinic\n// \u6700\u5927\u6D41\u3092\u6C42\u3081\u308B.\ntemplate <typename T,\
    \ const T INF>\nstruct Dinic {\n    struct edge {\n        int to, rev;\n    \
    \    T cap;\n        edge() {}\n        edge(int to, T cap, int rev) : to(to),\
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
    \ 0) {\n                flow += f;\n            }\n        }\n    }\n};\n#line\
    \ 6 \"graph/constrained_maxflow.cpp\"\n\n// ConstrainedMaxFlow\n// \u6700\u5C0F\
    \u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41\u554F\u984C\u3092\u3068\
    \u304F.\ntemplate <typename T, const T INF>\nstruct ConstrainedMaxFlow {\n   \
    \ int n, super_s, super_t;\n    T max_flow_from_super_s;\n    Dinic<T, INF> flow_solver;\n\
    \n    ConstrainedMaxFlow(int n) : n(n), super_s(n), super_t(n + 1), max_flow_from_super_s(0)\
    \ {\n        flow_solver.resize(n + 2);\n    }\n\n    // add_edge\n    // \u9802\
    \u70B9a\u304B\u3089\u9802\u70B9b\u3078\u3068\u5BB9\u91CFcap\u3067\u6700\u5C0F\u6D41\
    \u91CF\u304Cmin_flow\u306E\u8FBA\u3092\u5F35\u308B\n    // \u5236\u7D04: 0 <=\
    \ a,b < n,0 <= min_flow <= cap\n    void add_edge(int a, int b, T cap, T min_flow\
    \ = 0) {\n        if (min_flow == 0) {\n            flow_solver.add_edge(a, b,\
    \ cap);\n            return;\n        }\n        flow_solver.add_edge(a, b, cap\
    \ - min_flow);\n        flow_solver.add_edge(a, super_t, min_flow);\n        flow_solver.add_edge(super_s,\
    \ b, min_flow);\n        max_flow_from_super_s += min_flow;\n    }\n\n    // solve\n\
    \    // \u9802\u70B9s\u304B\u3089\u9802\u70B9t\u3078\u306E\u6700\u5C0F\u6D41\u91CF\
    \u5236\u7D04\u4ED8\u304D\u6700\u5927\u30D5\u30ED\u30FC\u3092\u6C42\u3081\u308B\
    .\n    // \u3082\u3057\u6D41\u91CF\u5236\u7D04\u3092\u6E80\u305F\u3059\u30D5\u30ED\
    \u30FC\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F false,0 \u3092\u8FD4\
    \u3059.\n    // \u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\
    \u3000\u3000\u3000\u5B58\u5728\u3059\u308B\u5834\u5408\u306F true,flow \u3092\u8FD4\
    \u3059.\n    // \u5236\u7D04: 0 <= s,t < n\n    // \u8A08\u7B97\u91CF: O(|V|^2|E|)\n\
    \    pair<bool, T> solve(int s, int t) {\n        T a = flow_solver.solve(super_s,\
    \ super_t);\n        T b = flow_solver.solve(super_s, t);\n        T c = flow_solver.solve(s,\
    \ super_t);\n        T d = flow_solver.solve(s, t);\n\n        bool does_exist\
    \ = ((a + b == max_flow_from_super_s) && (b == c));\n        return make_pair(does_exist,\
    \ does_exist ? c + d : T(0));\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"dinic.cpp\"\n\n// ConstrainedMaxFlow\n// \u6700\u5C0F\u6D41\u91CF\u5236\u7D04\
    \u4ED8\u304D\u6700\u5927\u6D41\u554F\u984C\u3092\u3068\u304F.\ntemplate <typename\
    \ T, const T INF>\nstruct ConstrainedMaxFlow {\n    int n, super_s, super_t;\n\
    \    T max_flow_from_super_s;\n    Dinic<T, INF> flow_solver;\n\n    ConstrainedMaxFlow(int\
    \ n) : n(n), super_s(n), super_t(n + 1), max_flow_from_super_s(0) {\n        flow_solver.resize(n\
    \ + 2);\n    }\n\n    // add_edge\n    // \u9802\u70B9a\u304B\u3089\u9802\u70B9\
    b\u3078\u3068\u5BB9\u91CFcap\u3067\u6700\u5C0F\u6D41\u91CF\u304Cmin_flow\u306E\
    \u8FBA\u3092\u5F35\u308B\n    // \u5236\u7D04: 0 <= a,b < n,0 <= min_flow <= cap\n\
    \    void add_edge(int a, int b, T cap, T min_flow = 0) {\n        if (min_flow\
    \ == 0) {\n            flow_solver.add_edge(a, b, cap);\n            return;\n\
    \        }\n        flow_solver.add_edge(a, b, cap - min_flow);\n        flow_solver.add_edge(a,\
    \ super_t, min_flow);\n        flow_solver.add_edge(super_s, b, min_flow);\n \
    \       max_flow_from_super_s += min_flow;\n    }\n\n    // solve\n    // \u9802\
    \u70B9s\u304B\u3089\u9802\u70B9t\u3078\u306E\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\
    \u4ED8\u304D\u6700\u5927\u30D5\u30ED\u30FC\u3092\u6C42\u3081\u308B.\n    // \u3082\
    \u3057\u6D41\u91CF\u5236\u7D04\u3092\u6E80\u305F\u3059\u30D5\u30ED\u30FC\u304C\
    \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F false,0 \u3092\u8FD4\u3059.\n\
    \    // \u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\
    \u3000\u3000\u5B58\u5728\u3059\u308B\u5834\u5408\u306F true,flow \u3092\u8FD4\u3059\
    .\n    // \u5236\u7D04: 0 <= s,t < n\n    // \u8A08\u7B97\u91CF: O(|V|^2|E|)\n\
    \    pair<bool, T> solve(int s, int t) {\n        T a = flow_solver.solve(super_s,\
    \ super_t);\n        T b = flow_solver.solve(super_s, t);\n        T c = flow_solver.solve(s,\
    \ super_t);\n        T d = flow_solver.solve(s, t);\n\n        bool does_exist\
    \ = ((a + b == max_flow_from_super_s) && (b == c));\n        return make_pair(does_exist,\
    \ does_exist ? c + d : T(0));\n    }\n};"
  dependsOn:
  - graph/dinic.cpp
  isVerificationFile: false
  path: graph/constrained_maxflow.cpp
  requiredBy: []
  timestamp: '2023-01-29 11:16:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/constrained_maxflow.cpp
layout: document
redirect_from:
- /library/graph/constrained_maxflow.cpp
- /library/graph/constrained_maxflow.cpp.html
title: graph/constrained_maxflow.cpp
---
