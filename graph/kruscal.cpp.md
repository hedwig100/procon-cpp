---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structures/unionfind.cpp
    title: data_structures/unionfind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/kruscal.test.cpp
    title: test/kruscal.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/kruscal.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 3 \"data_structures/unionfind.cpp\"\nusing namespace std;\n\n\
    // UnionFind\n// \u30B0\u30EB\u30FC\u30D7\u3092\u7BA1\u7406\u3059\u308B\u30C7\u30FC\
    \u30BF\u69CB\u9020\nstruct UnionFind {\n    int n;\n    vector<int> parents;\n\
    \n    UnionFind(int n) : n(n) {\n        parents.assign(n, -1);\n    }\n\n   \
    \ // find\n    // x\u306E\u89AA\u3092\u8FD4\u3059.\n    // \u5236\u7D04: 0 <=\
    \ x < n\n    int find(int x) {\n        if (parents[x] < 0) return x;\n      \
    \  return parents[x] = find(parents[x]);\n    }\n\n    // unite\n    // x\u3068\
    y\u3092\u542B\u3080\u30B0\u30EB\u30FC\u30D7\u3092\u4F75\u5408\n    // \u5236\u7D04\
    : 0 <= x,y < n\n    void unite(int x, int y) { // x\u3068y\u306E\u542B\u3080\u30B0\
    \u30EB\u30FC\u30D7\u3092\u4F75\u5408\n        int px = find(x);\n        int py\
    \ = find(y);\n        if (parents[px] > parents[py]) swap(px, py);\n        if\
    \ (px != py) {\n            parents[px] += parents[py];\n            parents[py]\
    \ = px;\n        }\n    }\n\n    // same\n    // x\u3068y\u304C\u540C\u3058\u30B0\
    \u30EB\u30FC\u30D7\u306B\u3044\u308B\u304B\u5224\u5B9A\n    // \u5236\u7D04: 0\
    \ <= x,y < n\n    bool same(int x, int y) {\n        return find(x) == find(y);\n\
    \    }\n\n    // size\n    // x\u3068\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306E\
    \u30E1\u30F3\u30D0\u30FC\u306E\u500B\u6570\n    // \u5236\u7D04: 0 <= x < n\n\
    \    int size(int x) {\n        return -parents[find(x)];\n    }\n\n    // root\n\
    \    // \u6839\u3092\u5168\u3066\u5217\u6319\u3059\u308B\n    vector<int> root()\
    \ {\n        vector<int> res;\n        for (int i = 0; i < n; i++) {\n       \
    \     if (parents[i] < 0) res.push_back(i);\n        }\n        return res;\n\
    \    }\n\n    // group_count\n    // \u30B0\u30EB\u30FC\u30D7\u306E\u6570\u3092\
    \u8FD4\u3059.\n    int group_count() { // uf\u306E\u30B0\u30EB\u30FC\u30D7\u306E\
    \u6570\u3092\u6570\u3048\u308B\n        return (int)root().size();\n    }\n};\n\
    #line 6 \"graph/kruscal.cpp\"\n\n// Kruscal\n// Kruscal\u6CD5\u3067\u6700\u5C0F\
    \u5168\u57DF\u68EE\u3092\u6C42\u3081\u308B.\ntemplate <typename T, const T INF>\n\
    struct Kruscal {\n    struct edge {\n        int a, b;\n        T cost;\n    \
    \    int id;\n        edge(int a, int b, T c, int id) : a(a), b(b), cost(c), id(id)\
    \ {}\n    };\n\n    int n;\n    int m = 0;\n    vector<edge> edges;\n    vector<int>\
    \ used_id;\n\n    Kruscal(int n) : n(n) {}\n\n    // add_edge\n    // a\u304B\u3089\
    b\u3078\u30B3\u30B9\u30C8c\u306E\u8FBA\u3092\u5F35\u308B\n    void add_edge(int\
    \ a, int b, T c) {\n        edges.emplace_back(a, b, c, m++);\n    }\n\n    //\
    \ solve\n    // \u6700\u5C0F\u5168\u57DF\u68EE\u3092\u6C42\u3081\u3066, \u305D\
    \u306E\u30B3\u30B9\u30C8\u3092\u8FD4\u3059.\n    // \u8A08\u7B97\u91CF: O(|E|log|E|)\n\
    \    T solve() {\n        used_id.assign(m, 0);\n        sort(edges.begin(), edges.end(),\n\
    \             [](const edge &a, const edge &b) { return a.cost < b.cost; });\n\
    \n        T ans = T(0);\n        UnionFind uf(n);\n        for (const edge &e\
    \ : edges) {\n            if (uf.same(e.a, e.b)) continue;\n            ans +=\
    \ e.cost;\n            used_id[e.id] = 1;\n            uf.unite(e.a, e.b);\n \
    \       }\n        return ans;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../data_structures/unionfind.cpp\"\n\n// Kruscal\n// Kruscal\u6CD5\u3067\u6700\
    \u5C0F\u5168\u57DF\u68EE\u3092\u6C42\u3081\u308B.\ntemplate <typename T, const\
    \ T INF>\nstruct Kruscal {\n    struct edge {\n        int a, b;\n        T cost;\n\
    \        int id;\n        edge(int a, int b, T c, int id) : a(a), b(b), cost(c),\
    \ id(id) {}\n    };\n\n    int n;\n    int m = 0;\n    vector<edge> edges;\n \
    \   vector<int> used_id;\n\n    Kruscal(int n) : n(n) {}\n\n    // add_edge\n\
    \    // a\u304B\u3089b\u3078\u30B3\u30B9\u30C8c\u306E\u8FBA\u3092\u5F35\u308B\n\
    \    void add_edge(int a, int b, T c) {\n        edges.emplace_back(a, b, c, m++);\n\
    \    }\n\n    // solve\n    // \u6700\u5C0F\u5168\u57DF\u68EE\u3092\u6C42\u3081\
    \u3066, \u305D\u306E\u30B3\u30B9\u30C8\u3092\u8FD4\u3059.\n    // \u8A08\u7B97\
    \u91CF: O(|E|log|E|)\n    T solve() {\n        used_id.assign(m, 0);\n       \
    \ sort(edges.begin(), edges.end(),\n             [](const edge &a, const edge\
    \ &b) { return a.cost < b.cost; });\n\n        T ans = T(0);\n        UnionFind\
    \ uf(n);\n        for (const edge &e : edges) {\n            if (uf.same(e.a,\
    \ e.b)) continue;\n            ans += e.cost;\n            used_id[e.id] = 1;\n\
    \            uf.unite(e.a, e.b);\n        }\n        return ans;\n    }\n};\n"
  dependsOn:
  - data_structures/unionfind.cpp
  isVerificationFile: false
  path: graph/kruscal.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/kruscal.test.cpp
documentation_of: graph/kruscal.cpp
layout: document
redirect_from:
- /library/graph/kruscal.cpp
- /library/graph/kruscal.cpp.html
title: graph/kruscal.cpp
---
