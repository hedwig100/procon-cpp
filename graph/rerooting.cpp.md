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
  bundledCode: "#line 2 \"graph/rerooting.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct DP {\n    int dp;\n    DP(int dp = 1) : dp(dp) {}\n    DP operator+(const\
    \ DP &a) const { // merge function\n        return DP(dp + a.dp);\n    }\n   \
    \ DP addroot() const { // g = g(f(dp_0,dp_1,...,dp_N),v) : add root\n        return\
    \ DP(dp + 1);\n    }\n};\nDP unit = DP(); // unit\n\ntemplate <class T>\nstruct\
    \ Rerooting {\n    int N;\n    vector<int> parents;\n    vector<vector<int>> G;\n\
    \    vector<vector<T>> dp;\n    vector<T> ans;\n    Rerooting(int N, const vector<vector<int>>\
    \ &G) : N(N), G(G) {\n        parents.assign(N, -1);\n        dp.resize(N);\n\
    \        ans.resize(N);\n        dfs(0);\n        bfs(0);\n    }\n    T dfs(int\
    \ v, int p = -1) {\n        T ret = unit;\n        dp[v] = vector<T>(G[v].size());\n\
    \        for (int i = 0; i < (int)G[v].size(); ++i) {\n            if (p == G[v][i])\
    \ {\n                parents[v] = i;\n                continue;\n            }\n\
    \            dp[v][i] = dfs(G[v][i], v);\n            ret      = ret + dp[v][i];\n\
    \        }\n        return ret.addroot();\n    }\n    void bfs(int v, const T\
    \ &res_p = unit, int p = -1) {\n        if (p != -1) dp[v][parents[v]] = res_p;\n\
    \        int deg = G[v].size();\n        vector<T> dpl(deg + 1), dpr(deg + 1);\n\
    \        dpl[0]   = unit;\n        dpr[deg] = unit;\n        for (int i = 0; i\
    \ < deg; ++i)\n            dpl[i + 1] = dpl[i] + dp[v][i];\n        for (int i\
    \ = deg - 1; i >= 0; --i)\n            dpr[i] = dpr[i + 1] + dp[v][i];\n     \
    \   ans[v] = dpr[0].addroot();\n        for (int i = 0; i < deg; ++i) {\n    \
    \        if (parents[v] == i) continue;\n            T d = dpl[i] + dpr[i + 1];\n\
    \            bfs(G[v][i], d.addroot(), v);\n        }\n    }\n    T operator[](int\
    \ k) {\n        return ans[k];\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct DP\
    \ {\n    int dp;\n    DP(int dp = 1) : dp(dp) {}\n    DP operator+(const DP &a)\
    \ const { // merge function\n        return DP(dp + a.dp);\n    }\n    DP addroot()\
    \ const { // g = g(f(dp_0,dp_1,...,dp_N),v) : add root\n        return DP(dp +\
    \ 1);\n    }\n};\nDP unit = DP(); // unit\n\ntemplate <class T>\nstruct Rerooting\
    \ {\n    int N;\n    vector<int> parents;\n    vector<vector<int>> G;\n    vector<vector<T>>\
    \ dp;\n    vector<T> ans;\n    Rerooting(int N, const vector<vector<int>> &G)\
    \ : N(N), G(G) {\n        parents.assign(N, -1);\n        dp.resize(N);\n    \
    \    ans.resize(N);\n        dfs(0);\n        bfs(0);\n    }\n    T dfs(int v,\
    \ int p = -1) {\n        T ret = unit;\n        dp[v] = vector<T>(G[v].size());\n\
    \        for (int i = 0; i < (int)G[v].size(); ++i) {\n            if (p == G[v][i])\
    \ {\n                parents[v] = i;\n                continue;\n            }\n\
    \            dp[v][i] = dfs(G[v][i], v);\n            ret      = ret + dp[v][i];\n\
    \        }\n        return ret.addroot();\n    }\n    void bfs(int v, const T\
    \ &res_p = unit, int p = -1) {\n        if (p != -1) dp[v][parents[v]] = res_p;\n\
    \        int deg = G[v].size();\n        vector<T> dpl(deg + 1), dpr(deg + 1);\n\
    \        dpl[0]   = unit;\n        dpr[deg] = unit;\n        for (int i = 0; i\
    \ < deg; ++i)\n            dpl[i + 1] = dpl[i] + dp[v][i];\n        for (int i\
    \ = deg - 1; i >= 0; --i)\n            dpr[i] = dpr[i + 1] + dp[v][i];\n     \
    \   ans[v] = dpr[0].addroot();\n        for (int i = 0; i < deg; ++i) {\n    \
    \        if (parents[v] == i) continue;\n            T d = dpl[i] + dpr[i + 1];\n\
    \            bfs(G[v][i], d.addroot(), v);\n        }\n    }\n    T operator[](int\
    \ k) {\n        return ans[k];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/rerooting.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/rerooting.cpp
layout: document
redirect_from:
- /library/graph/rerooting.cpp
- /library/graph/rerooting.cpp.html
title: graph/rerooting.cpp
---
