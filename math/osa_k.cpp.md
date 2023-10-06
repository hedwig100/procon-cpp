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
  bundledCode: "#line 2 \"math/osa_k.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// OsaK\n// n\u4EE5\u4E0B\u306E\u6574\u6570\u306E\u7D20\u56E0\u6570\u5206\
    \u89E3\u3092\u9AD8\u901F\u306B\u884C\u3046.\n// \u5236\u7D04: n >= 1\nstruct OsaK\
    \ {\n    int n;\n    vector<int> smallest_prime_factor;\n\n    OsaK(int n) : n(n)\
    \ {\n        smallest_prime_factor.assign(n + 1, -1);\n    }\n\n    // build\n\
    \    // spf\u914D\u5217\u3092\u7528\u610F\u3059\u308B.\n    // \u8A08\u7B97\u91CF\
    : O(nloglogn)\n    void build() {\n        long long i = 2;\n        for (; i\
    \ * i <= n; ++i) {\n            if (smallest_prime_factor[i] < 0) {\n        \
    \        smallest_prime_factor[i] = i;\n                for (long long p = i *\
    \ i; p <= n; p += i) {\n                    if (smallest_prime_factor[p] < 0)\
    \ smallest_prime_factor[p] = i;\n                }\n            }\n        }\n\
    \        for (int j = i; j <= n; ++j) {\n            if (smallest_prime_factor[j]\
    \ < 0) smallest_prime_factor[j] = j;\n        }\n    }\n\n    // factorize\n \
    \   // \u6574\u6570m\u3092\u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\n    // \u5236\
    \u7D04: 1 <= m <= n\n    // \u8A08\u7B97\u91CF: O(logm)\n    template <typename\
    \ T>\n    vector<pair<T, int>> factorize(T m) {\n        vector<pair<T, int>>\
    \ ans;\n        while (m > 1) {\n            int p = smallest_prime_factor[m],\
    \ e = 1;\n            m /= p;\n            while (p == smallest_prime_factor[m])\
    \ {\n                ++e;\n                m /= p;\n            }\n          \
    \  ans.emplace_back(p, e);\n        }\n        return ans;\n    }\n\n    // count_factor\n\
    \    // \u6574\u6570m\u306E\u7D04\u6570\u306E\u6570\u3092\u6570\u3048\u308B.\n\
    \    // \u5236\u7D04: 1 <= m <= n\n    // \u8A08\u7B97\u91CF: O(logm)\n    template\
    \ <typename T>\n    long long count_factor(T m) {\n        auto ret      = factorize(m);\n\
    \        long long ans = 1;\n        for (const auto &p : ret) {\n           \
    \ ans *= (p.second + 1);\n        }\n        return ans;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// OsaK\n\
    // n\u4EE5\u4E0B\u306E\u6574\u6570\u306E\u7D20\u56E0\u6570\u5206\u89E3\u3092\u9AD8\
    \u901F\u306B\u884C\u3046.\n// \u5236\u7D04: n >= 1\nstruct OsaK {\n    int n;\n\
    \    vector<int> smallest_prime_factor;\n\n    OsaK(int n) : n(n) {\n        smallest_prime_factor.assign(n\
    \ + 1, -1);\n    }\n\n    // build\n    // spf\u914D\u5217\u3092\u7528\u610F\u3059\
    \u308B.\n    // \u8A08\u7B97\u91CF: O(nloglogn)\n    void build() {\n        long\
    \ long i = 2;\n        for (; i * i <= n; ++i) {\n            if (smallest_prime_factor[i]\
    \ < 0) {\n                smallest_prime_factor[i] = i;\n                for (long\
    \ long p = i * i; p <= n; p += i) {\n                    if (smallest_prime_factor[p]\
    \ < 0) smallest_prime_factor[p] = i;\n                }\n            }\n     \
    \   }\n        for (int j = i; j <= n; ++j) {\n            if (smallest_prime_factor[j]\
    \ < 0) smallest_prime_factor[j] = j;\n        }\n    }\n\n    // factorize\n \
    \   // \u6574\u6570m\u3092\u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\n    // \u5236\
    \u7D04: 1 <= m <= n\n    // \u8A08\u7B97\u91CF: O(logm)\n    template <typename\
    \ T>\n    vector<pair<T, int>> factorize(T m) {\n        vector<pair<T, int>>\
    \ ans;\n        while (m > 1) {\n            int p = smallest_prime_factor[m],\
    \ e = 1;\n            m /= p;\n            while (p == smallest_prime_factor[m])\
    \ {\n                ++e;\n                m /= p;\n            }\n          \
    \  ans.emplace_back(p, e);\n        }\n        return ans;\n    }\n\n    // count_factor\n\
    \    // \u6574\u6570m\u306E\u7D04\u6570\u306E\u6570\u3092\u6570\u3048\u308B.\n\
    \    // \u5236\u7D04: 1 <= m <= n\n    // \u8A08\u7B97\u91CF: O(logm)\n    template\
    \ <typename T>\n    long long count_factor(T m) {\n        auto ret      = factorize(m);\n\
    \        long long ans = 1;\n        for (const auto &p : ret) {\n           \
    \ ans *= (p.second + 1);\n        }\n        return ans;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/osa_k.cpp
  requiredBy: []
  timestamp: '2022-08-30 16:11:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/osa_k.cpp
layout: document
redirect_from:
- /library/math/osa_k.cpp
- /library/math/osa_k.cpp.html
title: math/osa_k.cpp
---
