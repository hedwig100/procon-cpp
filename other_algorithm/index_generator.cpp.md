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
  bundledCode: "#line 2 \"other_algorithm/index_generator.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Grid\u306E(i,j)\u306A\u308B\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\u30921\u6B21\u5143\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u306B\
    \u76F4\u3059\n\ntemplate <typename T>\nstruct IndexGenerator {\n    T H, W;\n\
    \    IndexGenerator(T H, T W) : H(H), W(W) {}\n    T N() { return H * W; }\n \
    \   T operator()(T i, T j) { return i * W + j; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Grid\u306E\
    (i,j)\u306A\u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u30921\u6B21\u5143\u306E\
    \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u306B\u76F4\u3059\n\ntemplate <typename T>\n\
    struct IndexGenerator {\n    T H, W;\n    IndexGenerator(T H, T W) : H(H), W(W)\
    \ {}\n    T N() { return H * W; }\n    T operator()(T i, T j) { return i * W +\
    \ j; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other_algorithm/index_generator.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other_algorithm/index_generator.cpp
layout: document
redirect_from:
- /library/other_algorithm/index_generator.cpp
- /library/other_algorithm/index_generator.cpp.html
title: other_algorithm/index_generator.cpp
---
