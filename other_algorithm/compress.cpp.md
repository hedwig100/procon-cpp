---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/inversion_number.test.cpp
    title: test/inversion_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other_algorithm/compress.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T>\nstruct Compress {\n  private:\n\
    \    int n;\n    vector<T> A;\n    map<T, int> val_to_id;\n\n  public:\n    Compress(const\
    \ vector<T> &_A) : A(_A) {\n        sort(A.begin(), A.end());\n        A.erase(unique(A.begin(),\
    \ A.end()), A.end());\n        n = (int)A.size();\n        for (int i = 0; i <\
    \ n; i++)\n            val_to_id[A[i]] = i;\n    }\n\n    int operator()(T val)\
    \ {\n        return val_to_id[val];\n    }\n\n    T operator[](int id) {\n   \
    \     return A[id];\n    }\n\n    int size() {\n        return n;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T>\nstruct Compress {\n  private:\n    int n;\n    vector<T> A;\n\
    \    map<T, int> val_to_id;\n\n  public:\n    Compress(const vector<T> &_A) :\
    \ A(_A) {\n        sort(A.begin(), A.end());\n        A.erase(unique(A.begin(),\
    \ A.end()), A.end());\n        n = (int)A.size();\n        for (int i = 0; i <\
    \ n; i++)\n            val_to_id[A[i]] = i;\n    }\n\n    int operator()(T val)\
    \ {\n        return val_to_id[val];\n    }\n\n    T operator[](int id) {\n   \
    \     return A[id];\n    }\n\n    int size() {\n        return n;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: other_algorithm/compress.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/inversion_number.test.cpp
documentation_of: other_algorithm/compress.cpp
layout: document
redirect_from:
- /library/other_algorithm/compress.cpp
- /library/other_algorithm/compress.cpp.html
title: other_algorithm/compress.cpp
---
