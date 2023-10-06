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
  bundledCode: "#line 2 \"string/run_length.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nvector<pair<char, int>> run_length(string s) {\n    vector<pair<char,\
    \ int>> ret;\n    pair<char, int> now = make_pair(s[0], 1);\n    for (int i =\
    \ 1; i < (int)s.size(); i++) {\n        if (s[i] == s[i - 1]) {\n            now.second++;\n\
    \        } else {\n            ret.push_back(now);\n            now = make_pair(s[i],\
    \ 1);\n        }\n    }\n    ret.push_back(now);\n    return ret;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nvector<pair<char,\
    \ int>> run_length(string s) {\n    vector<pair<char, int>> ret;\n    pair<char,\
    \ int> now = make_pair(s[0], 1);\n    for (int i = 1; i < (int)s.size(); i++)\
    \ {\n        if (s[i] == s[i - 1]) {\n            now.second++;\n        } else\
    \ {\n            ret.push_back(now);\n            now = make_pair(s[i], 1);\n\
    \        }\n    }\n    ret.push_back(now);\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/run_length.cpp
  requiredBy: []
  timestamp: '2022-08-27 12:40:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/run_length.cpp
layout: document
redirect_from:
- /library/string/run_length.cpp
- /library/string/run_length.cpp.html
title: string/run_length.cpp
---
