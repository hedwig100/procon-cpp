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
  bundledCode: "#line 2 \"graph/lowlink.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct LowLink {\n    int N;\n    vector<vector<int>> G;\n    vector<int>\
    \ low, ord, articulation;\n    vector<pair<int,int>> bridge;\n\n    LowLink(int\
    \ N, vector<vector<int>> &G) : N(N), G(G) {\n        low.assign(N, -1);\n    \
    \    ord.assign(N, -1);\n    }\n\n    void dfs(int v, int time, int p = -1) {\n\
    \        ord[v] = low[v] = time;\n        ++time;\n\n        bool isArticulation\
    \ = false;\n        int cnt             = 0;\n\n        for (int e : G[v]) {\n\
    \            if (low[e] < 0) {\n                ++cnt;\n                dfs(e,\
    \ time, v);\n                low[v] = min(low[v], low[e]);\n                if\
    \ (p != -1 && ord[v] <= low[e]) isArticulation = true;\n                if (ord[v]\
    \ < low[e]) bridge.push_back({v, e});\n            } else if (p != e) {\n    \
    \            low[v] = min(low[v], ord[e]);\n            }\n        }\n\n     \
    \   if (p == -1 && cnt >= 2) isArticulation = true;\n        if (isArticulation)\
    \ articulation.push_back(v);\n    }\n\n    void build() {\n        dfs(0, 0);\n\
    \    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct LowLink\
    \ {\n    int N;\n    vector<vector<int>> G;\n    vector<int> low, ord, articulation;\n\
    \    vector<pair<int,int>> bridge;\n\n    LowLink(int N, vector<vector<int>> &G)\
    \ : N(N), G(G) {\n        low.assign(N, -1);\n        ord.assign(N, -1);\n   \
    \ }\n\n    void dfs(int v, int time, int p = -1) {\n        ord[v] = low[v] =\
    \ time;\n        ++time;\n\n        bool isArticulation = false;\n        int\
    \ cnt             = 0;\n\n        for (int e : G[v]) {\n            if (low[e]\
    \ < 0) {\n                ++cnt;\n                dfs(e, time, v);\n         \
    \       low[v] = min(low[v], low[e]);\n                if (p != -1 && ord[v] <=\
    \ low[e]) isArticulation = true;\n                if (ord[v] < low[e]) bridge.push_back({v,\
    \ e});\n            } else if (p != e) {\n                low[v] = min(low[v],\
    \ ord[e]);\n            }\n        }\n\n        if (p == -1 && cnt >= 2) isArticulation\
    \ = true;\n        if (isArticulation) articulation.push_back(v);\n    }\n\n \
    \   void build() {\n        dfs(0, 0);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowlink.cpp
  requiredBy: []
  timestamp: '2022-08-27 12:40:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lowlink.cpp
layout: document
redirect_from:
- /library/graph/lowlink.cpp
- /library/graph/lowlink.cpp.html
title: graph/lowlink.cpp
---
