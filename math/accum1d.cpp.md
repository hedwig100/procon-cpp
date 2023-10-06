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
  bundledCode: "#line 2 \"math/accum1d.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Accum1D\n// 1\u6B21\u5143\u7D2F\u7A4D\u548C\u3092\u8A08\u7B97\u3059\
    \u308B\u69CB\u9020\u4F53\n// n: \u914D\u5217\u306E\u9577\u3055\n// m: \u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\u306E mod m \u3054\u3068\u306E\u7D2F\u7A4D\u548C\u3092\
    \u8A08\u7B97\u3059\u308B. m = 1\u3067\u901A\u5E38\u306E\u7D2F\u7A4D\u548C\ntemplate\
    \ <typename T>\nstruct Accum1D {\n    int n, m;\n    vector<T> A, cum;\n\n   \
    \ Accum1D(int n, int m = 1) : n(n), m(m) {\n        A.assign(n, T(0));\n     \
    \   cum.assign(n + 1, T(0));\n    }\n\n    // build\n    // data\u3092\u3082\u3068\
    \u306B\u7D2F\u7A4D\u548C\u3092\u8A08\u7B97\u3059\u308B.\n    // \u8A08\u7B97\u91CF\
    : O(n)\n    // \u5236\u7D04: n = data.size()\n    void build(const vector<T> &data)\
    \ {\n        A = data;\n        for (int i = 0; i < n; i++) {\n            cum[i\
    \ + 1] = cum[max(i + 1 - m, 0)] + A[i];\n        }\n    }\n\n    // sum\n    //\
    \ \\sum_{(l <= i < r) and ( i \u2261 k mod m )} A[i] \u3092\u8A08\u7B97\u3059\u308B\
    .\n    // \u8A08\u7B97\u91CF: O(1)\n    // \u5236\u7D04: 0 <= l <= r <= n,0 <=\
    \ k < m\n    T sum(int l, int r, int k = 0) {\n        l = _calc_ind(l, k), r\
    \ = _calc_ind(r, k);\n        return cum[r + 1] - cum[l + 1];\n    }\n\n  private:\n\
    \    // _calc_ind\n    // 0 <= i < x \u304B\u3064 i \u2261 k mod m \u3092\u6E80\
    \u305F\u3059i\u3092\u8FD4\u3059.\n    // \u305D\u306E\u3088\u3046\u306Ai\u304C\
    \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F-1\u3092\u8FD4\u3059.\n    //\
    \ \u5236\u7D04: 0 <= x,0 <= k < m\n    int _calc_ind(int x, int k) {\n       \
    \ if (x <= k) return -1;\n        return m * ((x - k) / m - int((x - k) % m ==\
    \ 0)) + k;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Accum1D\n\
    // 1\u6B21\u5143\u7D2F\u7A4D\u548C\u3092\u8A08\u7B97\u3059\u308B\u69CB\u9020\u4F53\
    \n// n: \u914D\u5217\u306E\u9577\u3055\n// m: \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \u306E mod m \u3054\u3068\u306E\u7D2F\u7A4D\u548C\u3092\u8A08\u7B97\u3059\u308B\
    . m = 1\u3067\u901A\u5E38\u306E\u7D2F\u7A4D\u548C\ntemplate <typename T>\nstruct\
    \ Accum1D {\n    int n, m;\n    vector<T> A, cum;\n\n    Accum1D(int n, int m\
    \ = 1) : n(n), m(m) {\n        A.assign(n, T(0));\n        cum.assign(n + 1, T(0));\n\
    \    }\n\n    // build\n    // data\u3092\u3082\u3068\u306B\u7D2F\u7A4D\u548C\u3092\
    \u8A08\u7B97\u3059\u308B.\n    // \u8A08\u7B97\u91CF: O(n)\n    // \u5236\u7D04\
    : n = data.size()\n    void build(const vector<T> &data) {\n        A = data;\n\
    \        for (int i = 0; i < n; i++) {\n            cum[i + 1] = cum[max(i + 1\
    \ - m, 0)] + A[i];\n        }\n    }\n\n    // sum\n    // \\sum_{(l <= i < r)\
    \ and ( i \u2261 k mod m )} A[i] \u3092\u8A08\u7B97\u3059\u308B.\n    // \u8A08\
    \u7B97\u91CF: O(1)\n    // \u5236\u7D04: 0 <= l <= r <= n,0 <= k < m\n    T sum(int\
    \ l, int r, int k = 0) {\n        l = _calc_ind(l, k), r = _calc_ind(r, k);\n\
    \        return cum[r + 1] - cum[l + 1];\n    }\n\n  private:\n    // _calc_ind\n\
    \    // 0 <= i < x \u304B\u3064 i \u2261 k mod m \u3092\u6E80\u305F\u3059i\u3092\
    \u8FD4\u3059.\n    // \u305D\u306E\u3088\u3046\u306Ai\u304C\u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408\u306F-1\u3092\u8FD4\u3059.\n    // \u5236\u7D04: 0 <= x,0 <=\
    \ k < m\n    int _calc_ind(int x, int k) {\n        if (x <= k) return -1;\n \
    \       return m * ((x - k) / m - int((x - k) % m == 0)) + k;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/accum1d.cpp
  requiredBy: []
  timestamp: '2023-02-05 13:53:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/accum1d.cpp
layout: document
redirect_from:
- /library/math/accum1d.cpp
- /library/math/accum1d.cpp.html
title: math/accum1d.cpp
---
