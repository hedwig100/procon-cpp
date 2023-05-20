---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/stirling_number2.cpp
    title: math/stirling_number2.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bell_number.test.cpp
    title: test/bell_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/bell_number.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 3 \"math/stirling_number2.cpp\"\nusing namespace std;\n\
    \n// StirlingNumber2\n// n\u500B\u306E\u533A\u5225\u3067\u304D\u308B\u3082\u306E\
    \u3092k\u500B\u306E\u533A\u5225\u3067\u304D\u306A\u3044\u7BB1\u306B1\u500B\u4EE5\
    \u4E0A\u306B\u5206\u5272\u3059\u308B\u65B9\u6CD5\u304C\u4F55\u901A\u308A\u3042\
    \u308B\u304B\u6C42\u3081\u308B.\n// \u3053\u308C\u3092S(n,k)\u3068\u3059\u308B\
    . \u7B2C\u4E8C\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\ntemplate <typename\
    \ T>\nstruct StirlingNumber2 {\n    int n, k;\n    vector<vector<T>> dp;\n\n \
    \   StirlingNumber2(int n, int k) : n(n), k(k) {\n        dp.assign(n + 1, vector<T>(k\
    \ + 1, T(0)));\n    }\n\n    // solve\n    // S(i,j) (0 <= i <= n, 0 <= j <= k)\u3092\
    \u6C42\u3081\u308B.\n    // \u8A08\u7B97\u91CF: O(nk)\n    T solve() {\n     \
    \   dp[0][0] = T(1);\n        for (int i = 1; i <= n; i++) {\n            for\
    \ (int j = 0; j <= k; j++) {\n                dp[i][j] = T(j) * dp[i - 1][j];\n\
    \                if (j > 0) dp[i][j] += dp[i - 1][j - 1];\n            }\n   \
    \     }\n        return dp[n][k];\n    }\n\n    // S(i,j)\u3092\u8FD4\u3059.\n\
    \    // \u5236\u7D04: 0 <= i <= n, 0 <= j <= k\n    T operator()(int i, int j)\
    \ {\n        return dp[i][j];\n    }\n};\n#line 6 \"math/bell_number.cpp\"\n\n\
    /**\n * BellNumber\n * n\u500B\u306E\u533A\u5225\u3067\u304D\u308B\u3082\u306E\
    \u3092k\u500B\u306E\u533A\u5225\u3067\u304D\u306A\u3044\u7BB1\u306B0\u500B\u4EE5\
    \u4E0A\u306B\u5206\u5272\u3059\u308B\u65B9\u6CD5\u304C\u4F55\u901A\u308A\u3042\
    \u308B\u304B\u6C42\u3081\u308B.\n * \u3053\u308C\u3092B(n,k)\u3068\u3057\u3066\
    \u30D9\u30EB\u6570\u3068\u3044\u3046.\n */\ntemplate <typename T>\nstruct BellNumber\
    \ {\n    int n, k;\n    vector<vector<T>> dp;\n\n    BellNumber(int n, int k)\
    \ : n(n), k(k) {\n        dp.assign(n + 1, vector<T>(k + 1, T(0)));\n    }\n\n\
    \    /**\n     * solve\n     * 0 <= i <= n,0 <= j <= k\u306B\u3064\u3044\u3066\
    B(i,j)\u3092\u6C42\u3081\u308B.\n     * \u8A08\u7B97\u91CF: O(nk)\n     */\n \
    \   T solve() {\n        StirlingNumber2<T> s2(n, k);\n        s2.solve();\n \
    \       for (int i = 0; i <= n; i++) {\n            for (int j = 1; j <= k; j++)\
    \ {\n                dp[i][j] = dp[i][j - 1] + s2(i, j);\n            }\n    \
    \    }\n        return dp[n][k];\n    }\n\n    /**\n     * operator()\n     *\
    \ @param i int\n     * @param j int\n     * B(i,j) \u3092\u8FD4\u3059.\n     *\
    \ \u5236\u7D04: 0 <= i <= n,0 <= j <= k\n     */\n    T operator()(int i, int\
    \ j) {\n        return dp[i][j];\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../math/stirling_number2.cpp\"\n\n/**\n * BellNumber\n * n\u500B\u306E\u533A\
    \u5225\u3067\u304D\u308B\u3082\u306E\u3092k\u500B\u306E\u533A\u5225\u3067\u304D\
    \u306A\u3044\u7BB1\u306B0\u500B\u4EE5\u4E0A\u306B\u5206\u5272\u3059\u308B\u65B9\
    \u6CD5\u304C\u4F55\u901A\u308A\u3042\u308B\u304B\u6C42\u3081\u308B.\n * \u3053\
    \u308C\u3092B(n,k)\u3068\u3057\u3066\u30D9\u30EB\u6570\u3068\u3044\u3046.\n */\n\
    template <typename T>\nstruct BellNumber {\n    int n, k;\n    vector<vector<T>>\
    \ dp;\n\n    BellNumber(int n, int k) : n(n), k(k) {\n        dp.assign(n + 1,\
    \ vector<T>(k + 1, T(0)));\n    }\n\n    /**\n     * solve\n     * 0 <= i <= n,0\
    \ <= j <= k\u306B\u3064\u3044\u3066B(i,j)\u3092\u6C42\u3081\u308B.\n     * \u8A08\
    \u7B97\u91CF: O(nk)\n     */\n    T solve() {\n        StirlingNumber2<T> s2(n,\
    \ k);\n        s2.solve();\n        for (int i = 0; i <= n; i++) {\n         \
    \   for (int j = 1; j <= k; j++) {\n                dp[i][j] = dp[i][j - 1] +\
    \ s2(i, j);\n            }\n        }\n        return dp[n][k];\n    }\n\n   \
    \ /**\n     * operator()\n     * @param i int\n     * @param j int\n     * B(i,j)\
    \ \u3092\u8FD4\u3059.\n     * \u5236\u7D04: 0 <= i <= n,0 <= j <= k\n     */\n\
    \    T operator()(int i, int j) {\n        return dp[i][j];\n    }\n};"
  dependsOn:
  - math/stirling_number2.cpp
  isVerificationFile: false
  path: math/bell_number.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/bell_number.test.cpp
documentation_of: math/bell_number.cpp
layout: document
redirect_from:
- /library/math/bell_number.cpp
- /library/math/bell_number.cpp.html
title: math/bell_number.cpp
---