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
  bundledCode: "#line 2 \"other_algorithm/perm_search.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// PermSearch\n// \u9806\u5217\u3092\u5168\u63A2\u7D22\
    \u3059\u308B.\n// 0~n-1\u307E\u3067\u306E\u6570\u5B57\u304B\u3089\u306A\u308B\u9806\
    \u5217\u3092\u63A2\u7D22\u3059\u308B. f\u306F\u3042\u308B\u9806\u5217\u3092vector\u3067\
    \u53D7\u3051\u53D6\u3063\u3066\u51E6\u7406\u3092\u3059\u308B\u95A2\u6570\nstruct\
    \ PermSearch {\n    int n;\n    vector<int> A;\n    function<void(vector<int>\
    \ &)> f;\n\n    PermSearch(int n, function<void(vector<int> &)> f) : n(n), f(f)\
    \ {\n        A.resize(n);\n    }\n\n    // solve\n    // \u8A08\u7B97\u91CF\u306F\
    O(n!)\n    void solve() {\n        iota(A.begin(), A.end(), 0);\n        do {\n\
    \            f(A);\n        } while (next_permutation(A.begin(), A.end()));\n\
    \    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// PermSearch\n\
    // \u9806\u5217\u3092\u5168\u63A2\u7D22\u3059\u308B.\n// 0~n-1\u307E\u3067\u306E\
    \u6570\u5B57\u304B\u3089\u306A\u308B\u9806\u5217\u3092\u63A2\u7D22\u3059\u308B\
    . f\u306F\u3042\u308B\u9806\u5217\u3092vector\u3067\u53D7\u3051\u53D6\u3063\u3066\
    \u51E6\u7406\u3092\u3059\u308B\u95A2\u6570\nstruct PermSearch {\n    int n;\n\
    \    vector<int> A;\n    function<void(vector<int> &)> f;\n\n    PermSearch(int\
    \ n, function<void(vector<int> &)> f) : n(n), f(f) {\n        A.resize(n);\n \
    \   }\n\n    // solve\n    // \u8A08\u7B97\u91CF\u306FO(n!)\n    void solve()\
    \ {\n        iota(A.begin(), A.end(), 0);\n        do {\n            f(A);\n \
    \       } while (next_permutation(A.begin(), A.end()));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other_algorithm/perm_search.cpp
  requiredBy: []
  timestamp: '2022-08-28 17:14:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other_algorithm/perm_search.cpp
layout: document
redirect_from:
- /library/other_algorithm/perm_search.cpp
- /library/other_algorithm/perm_search.cpp.html
title: other_algorithm/perm_search.cpp
---
