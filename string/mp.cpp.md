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
  bundledCode: "#line 2 \"string/mp.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// MP\n// l=(\u6587\u5B57\u5217S\u306E\u9577\u3055)\u3068\u3057\u3066\
    i=1,...,l+1\u306B\u3064\u3044\u3066\n// A[i] = (S[0:i)\u306E\u63A5\u5C3E\u8F9E\
    \u3068\u63A5\u982D\u8F9E\u3067\u3042\u3063\u3066\u4E00\u81F4\u3059\u308B\u3088\
    \u3046\u306A\u3082\u306E\u306E\u6700\u5927\u306E\u9577\u3055, \u305F\u3060\u3057\
    S[0:i)\u5168\u4F53\u306F\u81EA\u660E\u306B\u4E00\u81F4\u3059\u308B\u306E\u3067\
    \u9664\u304F)\n// \u306A\u308B\u914D\u5217\u3092\u8FD4\u3059\u3002A[0]\u306F\u5E38\
    \u306B-1\n// complexity: O(|S|)\nvector<int> MP(string s) {\n    int l = (int)s.size();\n\
    \    vector<int> A(l + 1, -1);\n    int j = -1;\n    for (int i = 0; i < l; i++)\
    \ {\n        while (j >= 0 && s[i] != s[j])\n            j = A[j];\n        j++;\n\
    \        A[i + 1] = j;\n    }\n    return A;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// MP\n//\
    \ l=(\u6587\u5B57\u5217S\u306E\u9577\u3055)\u3068\u3057\u3066i=1,...,l+1\u306B\
    \u3064\u3044\u3066\n// A[i] = (S[0:i)\u306E\u63A5\u5C3E\u8F9E\u3068\u63A5\u982D\
    \u8F9E\u3067\u3042\u3063\u3066\u4E00\u81F4\u3059\u308B\u3088\u3046\u306A\u3082\
    \u306E\u306E\u6700\u5927\u306E\u9577\u3055, \u305F\u3060\u3057S[0:i)\u5168\u4F53\
    \u306F\u81EA\u660E\u306B\u4E00\u81F4\u3059\u308B\u306E\u3067\u9664\u304F)\n//\
    \ \u306A\u308B\u914D\u5217\u3092\u8FD4\u3059\u3002A[0]\u306F\u5E38\u306B-1\n//\
    \ complexity: O(|S|)\nvector<int> MP(string s) {\n    int l = (int)s.size();\n\
    \    vector<int> A(l + 1, -1);\n    int j = -1;\n    for (int i = 0; i < l; i++)\
    \ {\n        while (j >= 0 && s[i] != s[j])\n            j = A[j];\n        j++;\n\
    \        A[i + 1] = j;\n    }\n    return A;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/mp.cpp
  requiredBy: []
  timestamp: '2022-08-19 13:49:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/mp.cpp
layout: document
redirect_from:
- /library/string/mp.cpp
- /library/string/mp.cpp.html
title: string/mp.cpp
---
