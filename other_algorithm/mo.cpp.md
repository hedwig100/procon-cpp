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
  bundledCode: "#line 2 \"other_algorithm/mo.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nstruct Mo {\n    int N, Q, width, l, r;\n    vector<int> L,\
    \ R, idx;\n    using T = int;\n    T ret;\n    vector<T> ans;\n\n    Mo(int N,\
    \ int Q) : N(N), Q(Q) {\n        int width = sqrt(N);\n        L.resize(Q);\n\
    \        R.resize(Q);\n        idx.resize(Q);\n        ans.resize(Q);\n    }\n\
    \    void add_query(int i, int l, int r) { // ith query is [l,r)\n        idx[i]\
    \ = i;\n        L[i]   = l;\n        R[i]   = r;\n    }\n    void build() {\n\
    \        sort(idx.begin(), idx.end(), [&](int a, int b) {\n            return\
    \ L[a] / width == L[b] / width ? R[a] < R[b] : L[a] < L[b];\n        });\n   \
    \     l = 0;\n        r = 0;\n    }\n    void del(int i) { //\u533A\u9593\u3092\
    \u7E2E\u3081\u308B\n    }\n    void add(int i) { //\u533A\u9593\u3092\u5E83\u3052\
    \u308B\n    }\n    T process(int i) { //[l,r)\n        i = idx[i];\n        while\
    \ (l > L[i])\n            add(--l);\n        while (r < R[i])\n            add(r++);\n\
    \        while (l < L[i])\n            del(l++);\n        while (r > R[i])\n \
    \           del(--r);\n        return ans[i] = ret;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct Mo\
    \ {\n    int N, Q, width, l, r;\n    vector<int> L, R, idx;\n    using T = int;\n\
    \    T ret;\n    vector<T> ans;\n\n    Mo(int N, int Q) : N(N), Q(Q) {\n     \
    \   int width = sqrt(N);\n        L.resize(Q);\n        R.resize(Q);\n       \
    \ idx.resize(Q);\n        ans.resize(Q);\n    }\n    void add_query(int i, int\
    \ l, int r) { // ith query is [l,r)\n        idx[i] = i;\n        L[i]   = l;\n\
    \        R[i]   = r;\n    }\n    void build() {\n        sort(idx.begin(), idx.end(),\
    \ [&](int a, int b) {\n            return L[a] / width == L[b] / width ? R[a]\
    \ < R[b] : L[a] < L[b];\n        });\n        l = 0;\n        r = 0;\n    }\n\
    \    void del(int i) { //\u533A\u9593\u3092\u7E2E\u3081\u308B\n    }\n    void\
    \ add(int i) { //\u533A\u9593\u3092\u5E83\u3052\u308B\n    }\n    T process(int\
    \ i) { //[l,r)\n        i = idx[i];\n        while (l > L[i])\n            add(--l);\n\
    \        while (r < R[i])\n            add(r++);\n        while (l < L[i])\n \
    \           del(l++);\n        while (r > R[i])\n            del(--r);\n     \
    \   return ans[i] = ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other_algorithm/mo.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other_algorithm/mo.cpp
layout: document
redirect_from:
- /library/other_algorithm/mo.cpp
- /library/other_algorithm/mo.cpp.html
title: other_algorithm/mo.cpp
---
