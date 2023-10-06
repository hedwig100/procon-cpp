---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/lowest_common_ancestor.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct LowestCommonAncestor {\n    int N, root, K;\n \
    \   vector<int> dist;\n    vector<vector<int>> G, parents;\n\n    void dfs() {\n\
    \        dist[root] = 0;\n        stack<int> st;\n        st.push(root);\n   \
    \     while (!st.empty()) {\n            int v = st.top();\n            st.pop();\n\
    \            for (int e : G[v]) {\n                if (dist[e] >= 0) {\n     \
    \               parents[v][0] = e;\n                    continue;\n          \
    \      }\n                dist[e] = dist[v] + 1;\n                st.push(e);\n\
    \            }\n        }\n    }\n\n    LowestCommonAncestor(int N, const vector<vector<int>>\
    \ &G, int root = 0)\n        : N(N), G(G), root(root) {\n        K = 1;\n    \
    \    while ((1 << K) < N)\n            ++K;\n        dist.assign(N, -1);\n   \
    \     dist[root] = 0;\n        parents.assign(N, vector<int>(K, -1));\n\n    \
    \    dfs();\n        for (int i = 0; i < K - 1; ++i) {\n            for (int j\
    \ = 0; j < N; ++j) {\n                if (parents[j][i] < 0) continue;\n     \
    \           parents[j][i + 1] = parents[parents[j][i]][i];\n            }\n  \
    \      }\n    }\n\n    int query(int u, int v) {\n        if (dist[u] < dist[v])\
    \ swap(u, v);\n        for (int k = 0; k < K; ++k) {\n            if (((dist[u]\
    \ - dist[v]) >> k) & 1) u = parents[u][k];\n        }\n        if (u == v) return\
    \ u;\n        for (int k = K - 1; k >= 0; --k) {\n            if (parents[u][k]\
    \ != parents[v][k]) {\n                u = parents[u][k];\n                v =\
    \ parents[v][k];\n            }\n        }\n        return parents[u][0];\n  \
    \  }\n\n    int operator[](int k) {\n        return dist[k];\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct LowestCommonAncestor\
    \ {\n    int N, root, K;\n    vector<int> dist;\n    vector<vector<int>> G, parents;\n\
    \n    void dfs() {\n        dist[root] = 0;\n        stack<int> st;\n        st.push(root);\n\
    \        while (!st.empty()) {\n            int v = st.top();\n            st.pop();\n\
    \            for (int e : G[v]) {\n                if (dist[e] >= 0) {\n     \
    \               parents[v][0] = e;\n                    continue;\n          \
    \      }\n                dist[e] = dist[v] + 1;\n                st.push(e);\n\
    \            }\n        }\n    }\n\n    LowestCommonAncestor(int N, const vector<vector<int>>\
    \ &G, int root = 0)\n        : N(N), G(G), root(root) {\n        K = 1;\n    \
    \    while ((1 << K) < N)\n            ++K;\n        dist.assign(N, -1);\n   \
    \     dist[root] = 0;\n        parents.assign(N, vector<int>(K, -1));\n\n    \
    \    dfs();\n        for (int i = 0; i < K - 1; ++i) {\n            for (int j\
    \ = 0; j < N; ++j) {\n                if (parents[j][i] < 0) continue;\n     \
    \           parents[j][i + 1] = parents[parents[j][i]][i];\n            }\n  \
    \      }\n    }\n\n    int query(int u, int v) {\n        if (dist[u] < dist[v])\
    \ swap(u, v);\n        for (int k = 0; k < K; ++k) {\n            if (((dist[u]\
    \ - dist[v]) >> k) & 1) u = parents[u][k];\n        }\n        if (u == v) return\
    \ u;\n        for (int k = K - 1; k >= 0; --k) {\n            if (parents[u][k]\
    \ != parents[v][k]) {\n                u = parents[u][k];\n                v =\
    \ parents[v][k];\n            }\n        }\n        return parents[u][0];\n  \
    \  }\n\n    int operator[](int k) {\n        return dist[k];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowest_common_ancestor.cpp
  requiredBy: []
  timestamp: '2022-08-27 12:40:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lowest_common_ancestor.cpp
layout: document
redirect_from:
- /library/graph/lowest_common_ancestor.cpp
- /library/graph/lowest_common_ancestor.cpp.html
title: graph/lowest_common_ancestor.cpp
---
