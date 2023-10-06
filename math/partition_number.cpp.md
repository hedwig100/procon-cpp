---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/partition_number.test.cpp
    title: test/partition_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/partition_number.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// PartionNumber\n// n\u500B\u306E\u533A\u5225\u3067\u304D\
    \u306A\u3044\u3082\u306E\u3092k\u500B\u306E\u533A\u5225\u3067\u304D\u306A\u3044\
    \u7BB1\u306B0\u500B\u4EE5\u4E0A\u306B\u5206\u5272\u3059\u308B\u65B9\u6CD5\u304C\
    \u4F55\u901A\u308A\u3042\u308B\u304B\u6C42\u3081\u308B.\n// \u3053\u308C\u3092\
    P(n,k)\u3068\u3059\u308B\u3068P(n,0) = 0 (n > 0)\ntemplate <typename T>\nstruct\
    \ PartitionNumber {\n    int n, k;\n    vector<vector<T>> dp;\n\n    PartitionNumber(int\
    \ n, int k) : n(n), k(k) {\n        dp.assign(n + 1, vector<T>(k + 1, T(0)));\n\
    \    }\n\n    // solve\n    // 0 <= i <= n,0 <= j <= k\u306E\u5206\u5272\u6570\
    \u3092\u6C42\u3081\u308B.\n    // \u8A08\u7B97\u91CF: O(nk)\n    void solve()\
    \ {\n        dp[0][0] = T(1);\n        for (int i = 0; i <= n; i++) {\n      \
    \      for (int j = 1; j <= k; j++) {\n                dp[i][j] = dp[i][j - 1];\n\
    \                if (i - j >= 0) dp[i][j] += dp[i - j][j];\n            }\n  \
    \      }\n    }\n\n    // P(i,j)\u3092\u8FD4\u3059.\n    // \u5236\u7D04: 0 <=\
    \ i <= n,0 <= j <= k\n    T operator()(int i, int j) {\n        return dp[i][j];\n\
    \    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// PartionNumber\n\
    // n\u500B\u306E\u533A\u5225\u3067\u304D\u306A\u3044\u3082\u306E\u3092k\u500B\u306E\
    \u533A\u5225\u3067\u304D\u306A\u3044\u7BB1\u306B0\u500B\u4EE5\u4E0A\u306B\u5206\
    \u5272\u3059\u308B\u65B9\u6CD5\u304C\u4F55\u901A\u308A\u3042\u308B\u304B\u6C42\
    \u3081\u308B.\n// \u3053\u308C\u3092P(n,k)\u3068\u3059\u308B\u3068P(n,0) = 0 (n\
    \ > 0)\ntemplate <typename T>\nstruct PartitionNumber {\n    int n, k;\n    vector<vector<T>>\
    \ dp;\n\n    PartitionNumber(int n, int k) : n(n), k(k) {\n        dp.assign(n\
    \ + 1, vector<T>(k + 1, T(0)));\n    }\n\n    // solve\n    // 0 <= i <= n,0 <=\
    \ j <= k\u306E\u5206\u5272\u6570\u3092\u6C42\u3081\u308B.\n    // \u8A08\u7B97\
    \u91CF: O(nk)\n    void solve() {\n        dp[0][0] = T(1);\n        for (int\
    \ i = 0; i <= n; i++) {\n            for (int j = 1; j <= k; j++) {\n        \
    \        dp[i][j] = dp[i][j - 1];\n                if (i - j >= 0) dp[i][j] +=\
    \ dp[i - j][j];\n            }\n        }\n    }\n\n    // P(i,j)\u3092\u8FD4\u3059\
    .\n    // \u5236\u7D04: 0 <= i <= n,0 <= j <= k\n    T operator()(int i, int j)\
    \ {\n        return dp[i][j];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/partition_number.cpp
  requiredBy: []
  timestamp: '2022-08-28 17:14:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/partition_number.test.cpp
documentation_of: math/partition_number.cpp
layout: document
redirect_from:
- /library/math/partition_number.cpp
- /library/math/partition_number.cpp.html
title: math/partition_number.cpp
---
