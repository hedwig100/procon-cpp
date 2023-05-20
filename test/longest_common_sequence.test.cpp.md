---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic_programming/longest_common_sequence.cpp
    title: dynamic_programming/longest_common_sequence.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=jp
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=jp
  bundledCode: "#line 1 \"test/longest_common_sequence.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=jp\"\
    \n#line 3 \"dynamic_programming/longest_common_sequence.cpp\"\nusing namespace\
    \ std;\n\nstruct LongestCommonSequence {\n    int n, m;\n    string s, t, ret;\n\
    \    vector<vector<int>> dp;\n\n    LongestCommonSequence(string s, string t)\
    \ : s(s), t(t) {\n        n = (int)s.size();\n        m = (int)t.size();\n   \
    \     dp.assign(n + 1, vector<int>(m + 1, 0));\n    }\n\n    // solve\n    //\
    \ \u6700\u9577\u5171\u901A\u90E8\u5206\u5217\u554F\u984C\u3092\u89E3\u3044\u3066\
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
    \ for (auto &c : ret)\n            ans += c;\n        return ans;\n    }\n};\n\
    #line 6 \"test/longest_common_sequence.test.cpp\"\n\nint main() {\n    int q;\n\
    \    cin >> q;\n    string s, t;\n    while (q--) {\n        cin >> s >> t;\n\
    \        LongestCommonSequence lcs(s, t);\n        cout << lcs.solve() << '\\\
    n';\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=jp\"\
    \n#include \"../dynamic_programming/longest_common_sequence.cpp\"\n\nint main()\
    \ {\n    int q;\n    cin >> q;\n    string s, t;\n    while (q--) {\n        cin\
    \ >> s >> t;\n        LongestCommonSequence lcs(s, t);\n        cout << lcs.solve()\
    \ << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - dynamic_programming/longest_common_sequence.cpp
  isVerificationFile: true
  path: test/longest_common_sequence.test.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/longest_common_sequence.test.cpp
layout: document
redirect_from:
- /verify/test/longest_common_sequence.test.cpp
- /verify/test/longest_common_sequence.test.cpp.html
title: test/longest_common_sequence.test.cpp
---
