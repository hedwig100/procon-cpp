---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/prim.test.cpp
    title: test/prim.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/prim.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Prim\n// Prim\u6CD5\u3067\u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\
    \u3081\u308B.\ntemplate <typename T, const T INF>\nstruct Prim {\n    struct edge\
    \ {\n        int to;\n        T cost;\n        int id;\n\n        edge(int to,\
    \ T c, int id) : to(to), cost(c), id(id) {}\n    };\n    function<bool(const edge\
    \ &, const edge &)> compare = [](const edge &a, const edge &b) {\n        return\
    \ a.cost > b.cost;\n    };\n\n    int n;\n    int m = 0;\n    vector<int> used_id;\n\
    \    vector<vector<edge>> G;\n\n    Prim(int n) : n(n) {\n        G.resize(n);\n\
    \    }\n\n    // add_edge\n    // a\u3068b\u306E\u9593\u306B\u30B3\u30B9\u30C8\
    c\u306E\u7121\u5411\u8FBA\u3092\u306F\u308B\n    void add_edge(int a, int b, T\
    \ c) {\n        G[a].emplace_back(b, c, m);\n        G[b].emplace_back(a, c, m++);\n\
    \    }\n\n    // solve\n    // \u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\
    \u308B.\n    // \u8A08\u7B97\u91CF: O(|E|log|V|)\n    T solve() {\n        used_id.assign(m,\
    \ 0);\n        T ans = T(0);\n        vector<int> visited(n, 0);\n        priority_queue<edge,\
    \ vector<edge>, decltype(compare)> q{compare};\n        q.emplace(0, 0, -1);\n\
    \n        while (!q.empty()) {\n            edge e = q.top();\n            q.pop();\n\
    \            if (visited[e.to]) continue;\n            if (e.id >= 0) used_id[e.id]\
    \ = 1;\n            ans += e.cost;\n            visited[e.to] = 1;\n         \
    \   for (const edge &e2 : G[e.to]) {\n                if (visited[e2.to]) continue;\n\
    \                q.push(e2);\n            }\n        }\n        return ans;\n\
    \    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Prim\n\
    // Prim\u6CD5\u3067\u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B.\ntemplate\
    \ <typename T, const T INF>\nstruct Prim {\n    struct edge {\n        int to;\n\
    \        T cost;\n        int id;\n\n        edge(int to, T c, int id) : to(to),\
    \ cost(c), id(id) {}\n    };\n    function<bool(const edge &, const edge &)> compare\
    \ = [](const edge &a, const edge &b) {\n        return a.cost > b.cost;\n    };\n\
    \n    int n;\n    int m = 0;\n    vector<int> used_id;\n    vector<vector<edge>>\
    \ G;\n\n    Prim(int n) : n(n) {\n        G.resize(n);\n    }\n\n    // add_edge\n\
    \    // a\u3068b\u306E\u9593\u306B\u30B3\u30B9\u30C8c\u306E\u7121\u5411\u8FBA\u3092\
    \u306F\u308B\n    void add_edge(int a, int b, T c) {\n        G[a].emplace_back(b,\
    \ c, m);\n        G[b].emplace_back(a, c, m++);\n    }\n\n    // solve\n    //\
    \ \u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B.\n    // \u8A08\u7B97\
    \u91CF: O(|E|log|V|)\n    T solve() {\n        used_id.assign(m, 0);\n       \
    \ T ans = T(0);\n        vector<int> visited(n, 0);\n        priority_queue<edge,\
    \ vector<edge>, decltype(compare)> q{compare};\n        q.emplace(0, 0, -1);\n\
    \n        while (!q.empty()) {\n            edge e = q.top();\n            q.pop();\n\
    \            if (visited[e.to]) continue;\n            if (e.id >= 0) used_id[e.id]\
    \ = 1;\n            ans += e.cost;\n            visited[e.to] = 1;\n         \
    \   for (const edge &e2 : G[e.to]) {\n                if (visited[e2.to]) continue;\n\
    \                q.push(e2);\n            }\n        }\n        return ans;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/prim.cpp
  requiredBy: []
  timestamp: '2022-08-29 15:12:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/prim.test.cpp
documentation_of: graph/prim.cpp
layout: document
redirect_from:
- /library/graph/prim.cpp
- /library/graph/prim.cpp.html
title: graph/prim.cpp
---
