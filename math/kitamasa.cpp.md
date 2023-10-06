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
  bundledCode: "#line 2 \"math/kitamasa.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Kitamasa\n// \u521D\u671F\u5024: A_0,A_1,...A_{k-1}\n// \u7DDA\u5F62\
    \u6F38\u5316\u5F0F: A_n = D_0A_{n-k} + ... D_{k-1}A_{n-1}\n// \u304C\u4E0E\u3048\
    \u3089\u308C\u305F\u3068\u304D\u306B\n// A_n\u3092O(k^2logn)\u3067\u6C42\u3081\
    \u308B.\ntemplate <typename T>\nstruct Kitamasa {\n    int k;\n    vector<T> init,\
    \ coef;\n\n    Kitamasa(vector<T> &init, vector<T> &coef) : init(init), coef(coef)\
    \ {\n        k = (int)coef.size();\n    }\n\n    // solve\n    // \u5236\u7D04\
    : n >= 0\n    // \u8A08\u7B97\u91CF: O(k^2logn)\n    T solve(long long n) {\n\
    \        if (n == 0) return init[0];\n        vector<T> ret(k, 0);\n        ret[1]\
    \ = 1;\n\n        int msb = get_msb(n);\n        for (int i = msb - 1; i >= 0;\
    \ i--) {\n            ret = mul2(ret);\n            if ((n >> i) & 1) {\n    \
    \            ret = add1(ret);\n            }\n        }\n        T ans = T(0);\n\
    \        for (int i = 0; i < k; i++)\n            ans += init[i] * ret[i];\n \
    \       return ans;\n    }\n\n    int get_msb(long long n) {\n        for (int\
    \ i = 63; i >= 0; i--) {\n            if ((n >> i) & 1) return i;\n        }\n\
    \        return -1;\n    }\n\n    vector<T> add1(vector<T> &ret) {\n        vector<T>\
    \ ans(k, 0);\n        for (int i = 0; i < k; i++) {\n            if (i == 0)\n\
    \                ans[i] = coef[0] * ret[k - 1];\n            else\n          \
    \      ans[i] = ret[i - 1] + coef[i] * ret[k - 1];\n        }\n        return\
    \ ans;\n    }\n\n    vector<T> mul2(vector<T> &ret) {\n        vector<T> ans(k,\
    \ 0), k0 = ret;\n        for (int i = 0; i < k; i++) {\n            for (int j\
    \ = 0; j < k; j++) {\n                ans[j] += k0[i] * ret[j];\n            }\n\
    \            ret = add1(ret);\n        }\n        return ans;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Kitamasa\n\
    // \u521D\u671F\u5024: A_0,A_1,...A_{k-1}\n// \u7DDA\u5F62\u6F38\u5316\u5F0F:\
    \ A_n = D_0A_{n-k} + ... D_{k-1}A_{n-1}\n// \u304C\u4E0E\u3048\u3089\u308C\u305F\
    \u3068\u304D\u306B\n// A_n\u3092O(k^2logn)\u3067\u6C42\u3081\u308B.\ntemplate\
    \ <typename T>\nstruct Kitamasa {\n    int k;\n    vector<T> init, coef;\n\n \
    \   Kitamasa(vector<T> &init, vector<T> &coef) : init(init), coef(coef) {\n  \
    \      k = (int)coef.size();\n    }\n\n    // solve\n    // \u5236\u7D04: n >=\
    \ 0\n    // \u8A08\u7B97\u91CF: O(k^2logn)\n    T solve(long long n) {\n     \
    \   if (n == 0) return init[0];\n        vector<T> ret(k, 0);\n        ret[1]\
    \ = 1;\n\n        int msb = get_msb(n);\n        for (int i = msb - 1; i >= 0;\
    \ i--) {\n            ret = mul2(ret);\n            if ((n >> i) & 1) {\n    \
    \            ret = add1(ret);\n            }\n        }\n        T ans = T(0);\n\
    \        for (int i = 0; i < k; i++)\n            ans += init[i] * ret[i];\n \
    \       return ans;\n    }\n\n    int get_msb(long long n) {\n        for (int\
    \ i = 63; i >= 0; i--) {\n            if ((n >> i) & 1) return i;\n        }\n\
    \        return -1;\n    }\n\n    vector<T> add1(vector<T> &ret) {\n        vector<T>\
    \ ans(k, 0);\n        for (int i = 0; i < k; i++) {\n            if (i == 0)\n\
    \                ans[i] = coef[0] * ret[k - 1];\n            else\n          \
    \      ans[i] = ret[i - 1] + coef[i] * ret[k - 1];\n        }\n        return\
    \ ans;\n    }\n\n    vector<T> mul2(vector<T> &ret) {\n        vector<T> ans(k,\
    \ 0), k0 = ret;\n        for (int i = 0; i < k; i++) {\n            for (int j\
    \ = 0; j < k; j++) {\n                ans[j] += k0[i] * ret[j];\n            }\n\
    \            ret = add1(ret);\n        }\n        return ans;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/kitamasa.cpp
  requiredBy: []
  timestamp: '2022-09-11 15:57:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/kitamasa.cpp
layout: document
redirect_from:
- /library/math/kitamasa.cpp
- /library/math/kitamasa.cpp.html
title: math/kitamasa.cpp
---
