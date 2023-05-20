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
  bundledCode: "#line 2 \"string/suffix_array.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nvector<int> suffix_array(string &s) {\n    // O(Nlog^2N)\n\
    \    int n = s.size();\n    vector<int> sa(n + 1), rank(n + 1), tmp(n + 1);\n\
    \    for (int i = 0; i <= n; ++i) {\n        sa[i]   = i;\n        rank[i] = (i\
    \ < n ? s[i] : -1);\n    }\n    for (int k = 1; k <= n; k <<= 1) {\n        auto\
    \ cmp = [&](int i, int j) {\n            if (rank[i] != rank[j])\n           \
    \     return rank[i] < rank[j];\n            else {\n                int ri =\
    \ (i + k <= n ? rank[i + k] : -1);\n                int rj = (j + k <= n ? rank[j\
    \ + k] : -1);\n                return ri < rj;\n            }\n        };\n  \
    \      sort(sa.begin(), sa.end(), cmp);\n        tmp[sa[0]] = 0;\n        for\
    \ (int i = 1; i <= n; ++i) {\n            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i\
    \ - 1], sa[i]) ? 1 : 0);\n        }\n        for (int i = 0; i <= n; ++i) {\n\
    \            rank[i] = tmp[i];\n        }\n    }\n    return sa;\n}\n\nvector<int>\
    \ lcp_array(string &s, vector<int> &sa) {\n    int n = s.size();\n    vector<int>\
    \ rank(n);\n    for (int i = 0; i < n; ++i) {\n        rank[sa[i]] = i;\n    }\n\
    }\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nvector<int>\
    \ suffix_array(string &s) {\n    // O(Nlog^2N)\n    int n = s.size();\n    vector<int>\
    \ sa(n + 1), rank(n + 1), tmp(n + 1);\n    for (int i = 0; i <= n; ++i) {\n  \
    \      sa[i]   = i;\n        rank[i] = (i < n ? s[i] : -1);\n    }\n    for (int\
    \ k = 1; k <= n; k <<= 1) {\n        auto cmp = [&](int i, int j) {\n        \
    \    if (rank[i] != rank[j])\n                return rank[i] < rank[j];\n    \
    \        else {\n                int ri = (i + k <= n ? rank[i + k] : -1);\n \
    \               int rj = (j + k <= n ? rank[j + k] : -1);\n                return\
    \ ri < rj;\n            }\n        };\n        sort(sa.begin(), sa.end(), cmp);\n\
    \        tmp[sa[0]] = 0;\n        for (int i = 1; i <= n; ++i) {\n           \
    \ tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n        }\n\
    \        for (int i = 0; i <= n; ++i) {\n            rank[i] = tmp[i];\n     \
    \   }\n    }\n    return sa;\n}\n\nvector<int> lcp_array(string &s, vector<int>\
    \ &sa) {\n    int n = s.size();\n    vector<int> rank(n);\n    for (int i = 0;\
    \ i < n; ++i) {\n        rank[sa[i]] = i;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_array.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/suffix_array.cpp
layout: document
redirect_from:
- /library/string/suffix_array.cpp
- /library/string/suffix_array.cpp.html
title: string/suffix_array.cpp
---
