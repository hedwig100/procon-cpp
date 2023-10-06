---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic_programming/edit_distance.cpp
    title: dynamic_programming/edit_distance.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E&lang=ja
  bundledCode: "#line 1 \"test/edit_distance.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E&lang=ja\"\
    \n#line 3 \"dynamic_programming/edit_distance.cpp\"\nusing namespace std;\n\n\
    #line 2 \"template/const.hpp\"\nconstexpr int INF        = 1000'000'000;\nconstexpr\
    \ long long HINF = 4000'000'000'000'000'000;\nconstexpr long long MOD  = 998244353;\n\
    constexpr double EPS     = 1e-6;\nconstexpr double PI      = 3.14159265358979;\n\
    #line 6 \"dynamic_programming/edit_distance.cpp\"\n\n// edit_distance\n// \u6587\
    \u5B57\u5217s,\u6587\u5B57\u5217t\u306E\u7DE8\u96C6\u8DDD\u96E2, \u3059\u306A\u308F\
    \u3061\u4EE5\u4E0B\u306E\u64CD\u4F5C\u3092\u3057\u3066s\u3092t\u306B\u7B49\u3057\
    \u304F\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\u306A\u64CD\u4F5C\u56DE\u6570\
    \u306E\u6700\u5C0F\u5024\n// 1. s\u304B\u3089\u6587\u5B57\u3092\u4E00\u3064\u53D6\
    \u308A\u9664\u304F\n// 2. s\u306B\u6587\u5B57\u3092\u4E00\u3064\u633F\u5165\u3059\
    \u308B\n// 3. s\u306E\u6587\u5B57\u3092\u4E00\u3064\u5909\u63DB\u3059\u308B\n\
    // \u8A08\u7B97\u91CF: O(|S||T|)\nint edit_distance(string s, string t) {\n  \
    \  int n = (int)s.size(), m = (int)t.size();\n    vector<vector<int>> dp(n + 1,\
    \ vector<int>(m + 1, INF));\n    for (int j = 0; j <= m; j++)\n        dp[0][j]\
    \ = j;\n    for (int i = 0; i <= n; i++) {\n        dp[i][0] = i;\n    }\n   \
    \ for (int i = 0; i < n; i++) {\n        for (int j = 0; j < m; j++) {\n     \
    \       if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j];\n            dp[i + 1][j\
    \ + 1] = min({dp[i + 1][j + 1], dp[i][j + 1] + 1, dp[i + 1][j] + 1, dp[i][j] +\
    \ 1});\n        }\n    }\n    return dp[n][m];\n}\n#line 6 \"test/edit_distance.test.cpp\"\
    \n\nint main() {\n    string s, t;\n    cin >> s >> t;\n    cout << edit_distance(s,\
    \ t) << '\\n';\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E&lang=ja\"\
    \n#include \"../dynamic_programming/edit_distance.cpp\"\n\nint main() {\n    string\
    \ s, t;\n    cin >> s >> t;\n    cout << edit_distance(s, t) << '\\n';\n    return\
    \ 0;\n}"
  dependsOn:
  - dynamic_programming/edit_distance.cpp
  isVerificationFile: true
  path: test/edit_distance.test.cpp
  requiredBy: []
  timestamp: '2022-10-23 13:46:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/edit_distance.test.cpp
layout: document
redirect_from:
- /verify/test/edit_distance.test.cpp
- /verify/test/edit_distance.test.cpp.html
title: test/edit_distance.test.cpp
---
