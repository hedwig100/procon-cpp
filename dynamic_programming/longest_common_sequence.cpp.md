---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/longest_common_sequence.test.cpp
    title: test/longest_common_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dynamic_programming/longest_common_sequence.cpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nstruct LongestCommonSequence {\n  \
    \  int n, m;\n    string s, t, ret;\n    vector<vector<int>> dp;\n\n    LongestCommonSequence(string\
    \ s, string t) : s(s), t(t) {\n        n = (int)s.size();\n        m = (int)t.size();\n\
    \        dp.assign(n + 1, vector<int>(m + 1, 0));\n    }\n\n    // solve\n   \
    \ // \u6700\u9577\u5171\u901A\u90E8\u5206\u5217\u554F\u984C\u3092\u89E3\u3044\u3066\
    \u305D\u306E\u9577\u3055\u3092\u8FD4\u3059\u3002\n    // \u8A08\u7B97\u91CF: O(nm)\n\
    \    int solve() {\n        for (int i = 0; i < n; i++) {\n            for (int\
    \ j = 0; j < m; j++) {\n                if (s[i] == t[j]) {\n                \
    \    dp[i + 1][j + 1] = dp[i][j] + 1;\n                } else {\n            \
    \        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);\n               \
    \ }\n            }\n        }\n        return dp[n][m];\n    }\n\n    // restore_common_string\n\
    \    // \u6700\u9577\u5171\u901A\u90E8\u5206\u5217(\u6587\u5B57\u5217)\u3092\u8FD4\
    \u3059\n    // \u8A08\u7B97\u91CF: O(l),l\u306F\u6700\u9577\u5171\u901A\u90E8\u5206\
    \u5217\u306E\u9577\u3055\n    string restore_common_string() {\n        vector<char>\
    \ ret;\n        int ni = n, nj = m;\n        while (ni != 0 && nj != 0) {\n  \
    \          if (s[ni - 1] == t[nj - 1]) {\n                ret.push_back(s[ni -\
    \ 1]);\n                ni--;\n                nj--;\n            } else {\n \
    \               if (dp[ni][nj] == dp[ni - 1][nj])\n                    ni--;\n\
    \                else\n                    nj--;\n            }\n        }\n \
    \       reverse(ret.begin(), ret.end());\n        string ans = \"\";\n       \
    \ for (auto &c : ret)\n            ans += c;\n        return ans;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct LongestCommonSequence\
    \ {\n    int n, m;\n    string s, t, ret;\n    vector<vector<int>> dp;\n\n   \
    \ LongestCommonSequence(string s, string t) : s(s), t(t) {\n        n = (int)s.size();\n\
    \        m = (int)t.size();\n        dp.assign(n + 1, vector<int>(m + 1, 0));\n\
    \    }\n\n    // solve\n    // \u6700\u9577\u5171\u901A\u90E8\u5206\u5217\u554F\
    \u984C\u3092\u89E3\u3044\u3066\u305D\u306E\u9577\u3055\u3092\u8FD4\u3059\u3002\
    \n    // \u8A08\u7B97\u91CF: O(nm)\n    int solve() {\n        for (int i = 0;\
    \ i < n; i++) {\n            for (int j = 0; j < m; j++) {\n                if\
    \ (s[i] == t[j]) {\n                    dp[i + 1][j + 1] = dp[i][j] + 1;\n   \
    \             } else {\n                    dp[i + 1][j + 1] = max(dp[i + 1][j],\
    \ dp[i][j + 1]);\n                }\n            }\n        }\n        return\
    \ dp[n][m];\n    }\n\n    // restore_common_string\n    // \u6700\u9577\u5171\u901A\
    \u90E8\u5206\u5217(\u6587\u5B57\u5217)\u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF\
    : O(l),l\u306F\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\u306E\u9577\u3055\n \
    \   string restore_common_string() {\n        vector<char> ret;\n        int ni\
    \ = n, nj = m;\n        while (ni != 0 && nj != 0) {\n            if (s[ni - 1]\
    \ == t[nj - 1]) {\n                ret.push_back(s[ni - 1]);\n               \
    \ ni--;\n                nj--;\n            } else {\n                if (dp[ni][nj]\
    \ == dp[ni - 1][nj])\n                    ni--;\n                else\n      \
    \              nj--;\n            }\n        }\n        reverse(ret.begin(), ret.end());\n\
    \        string ans = \"\";\n        for (auto &c : ret)\n            ans += c;\n\
    \        return ans;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_programming/longest_common_sequence.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/longest_common_sequence.test.cpp
documentation_of: dynamic_programming/longest_common_sequence.cpp
layout: document
redirect_from:
- /library/dynamic_programming/longest_common_sequence.cpp
- /library/dynamic_programming/longest_common_sequence.cpp.html
title: dynamic_programming/longest_common_sequence.cpp
---
