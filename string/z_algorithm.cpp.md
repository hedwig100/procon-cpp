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
  bundledCode: "#line 2 \"string/z_algorithm.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// Z-algorithum\n// l=(\u6587\u5B57\u5217S\u306E\u9577\u3055\
    )\u3068\u3057\u3066i=0,..,l-1\u306B\u5BFE\u3057\u3066\n// Z[i] = (S\u3068S[i:l)\u306E\
    \u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055)\n// \u306A\u308B\
    \u914D\u5217A\u3092\u8FD4\u3059\u3002\n// complexity : O(|S|)\nvector<int> Z_algorithm(string\
    \ s) {\n    int l = (int)s.size();\n    vector<int> Z(l);\n    Z[0]  = l;\n  \
    \  int i = 1, j = 0;\n    while (i < l) {\n        while (i + j < l && s[j] ==\
    \ s[i + j])\n            j++;\n        Z[i] = j;\n\n        if (j == 0) {\n  \
    \          i++;\n            continue;\n        }\n        int k = 1;\n      \
    \  while (k < j && k + Z[k] < j) {\n            Z[i + k] = Z[k];\n           \
    \ k++;\n        }\n        i += k;\n        j -= k;\n    }\n\n    return Z;\n\
    }\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Z-algorithum\n\
    // l=(\u6587\u5B57\u5217S\u306E\u9577\u3055)\u3068\u3057\u3066i=0,..,l-1\u306B\
    \u5BFE\u3057\u3066\n// Z[i] = (S\u3068S[i:l)\u306E\u6700\u9577\u5171\u901A\u63A5\
    \u982D\u8F9E\u306E\u9577\u3055)\n// \u306A\u308B\u914D\u5217A\u3092\u8FD4\u3059\
    \u3002\n// complexity : O(|S|)\nvector<int> Z_algorithm(string s) {\n    int l\
    \ = (int)s.size();\n    vector<int> Z(l);\n    Z[0]  = l;\n    int i = 1, j =\
    \ 0;\n    while (i < l) {\n        while (i + j < l && s[j] == s[i + j])\n   \
    \         j++;\n        Z[i] = j;\n\n        if (j == 0) {\n            i++;\n\
    \            continue;\n        }\n        int k = 1;\n        while (k < j &&\
    \ k + Z[k] < j) {\n            Z[i + k] = Z[k];\n            k++;\n        }\n\
    \        i += k;\n        j -= k;\n    }\n\n    return Z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.cpp
  requiredBy: []
  timestamp: '2022-08-19 13:49:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/z_algorithm.cpp
layout: document
redirect_from:
- /library/string/z_algorithm.cpp
- /library/string/z_algorithm.cpp.html
title: string/z_algorithm.cpp
---
