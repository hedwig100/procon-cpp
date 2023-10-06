---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/euclid.cpp
    title: math/euclid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/garner.test.cpp
    title: test/garner.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/number_theory.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 3 \"math/euclid.cpp\"\nusing namespace std;\n\n// gcd\n\
    // \u975E\u8CA0\u6574\u6570a,b\u306E\u6700\u5927\u516C\u7D04\u6570\u3092\u6C42\
    \u3081\u308B.\n// \u5236\u7D04: a,b >= 0\n// \u8A08\u7B97\u91CF: O(logmax(a,b))\n\
    template <typename T>\nT gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }\n\n\
    // lcm\n// \u975E\u8CA0\u6574\u6570a,b\u306E\u6700\u5C0F\u516C\u500D\u6570\u3092\
    \u6C42\u3081\u308B.\n// \u5236\u7D04: a,b >= 0\n// \u8A08\u7B97\u91CF: O(logmax(a,b))\n\
    template <typename T>\nT lcm(T a, T b) { return a / gcd(a, b) * b; }\n\n// ext_gcd\n\
    // \u62E1\u5F35Euclid\u306E\u4E92\u9664\u6CD5\u3067\u975E\u8CA0\u6574\u6570a,b\u306B\
    \u5BFE\u3057\u3066ax + by = gcd(a,b)\u3092\u6E80\u305F\u3059\u6574\u6570x,y\u3092\
    \u6C42\u3081\u308B.\n// \u51FA\u529B\u3055\u308C\u308B\u5024\u306F xy != 0 \u306A\
    \u3089\u3070 |x| <= b,|y| <= a \u3092\u6E80\u305F\u3059.\n// \u5236\u7D04: a,b\
    \ >= 0\n// \u8A08\u7B97\u91CF: O(logmax(a,b))\ntemplate <typename T>\npair<T,\
    \ T> ext_gcd(T a, T b) {\n    if (b == 0) {\n        return make_pair(1, 0);\n\
    \    }\n    auto [x, y] = ext_gcd(b, a % b);\n    return make_pair(y, x - a /\
    \ b * y);\n}\n#line 6 \"math/number_theory.cpp\"\n\n// pow_mod\n// x^k mod m\u3092\
    \u8A08\u7B97\u3059\u308B.\n// \u8A08\u7B97\u91CF: O(logk)\ntemplate <typename\
    \ T>\nT pow_mod(T x, long long k, int m) {\n    T ret = T(1);\n    while (k >\
    \ 0) {\n        if (k & 1) {\n            ret *= x;\n            ret %= m;\n \
    \       }\n        k >>= 1;\n        x *= x;\n        x %= m;\n    }\n    return\
    \ ret;\n}\n\n// inv_mod\n// ax = 1 (mod m) \u306A\u308Bx (0 <= x < m)\u304C\u5B58\
    \u5728\u3059\u308B\u306A\u3089\u3070\n// \u305D\u308C\u3092\u8FD4\u3057, \u5B58\
    \u5728\u3057\u306A\u3051\u308C\u3070-1\u3092\u8FD4\u3059.\n// \u8A08\u7B97\u91CF\
    : O(log|max(a,m)|)\ntemplate <typename T>\nT inv_mod(T a, T m) {\n    auto [x,\
    \ y] = ext_gcd(a, m);\n    T g         = a * x + m * y;\n    if (g != 1) return\
    \ -1;\n    return (m + x % m) % m;\n}\n\n// linear_congruence\n// forall i,A_i\
    \ x = B_i mod M_i <=> x = b mod m\n// \u3068\u304B\u3051\u308B\u3068\u304D\u306B\
    (b,m)\u306E\u7D44\u3092\u8FD4\u3059. \u305F\u3060\u3057(0 <= b < m)\u3092\u307F\
    \u305F\u3059. \u3053\u306E\u3088\u3046\u306B\u66F8\u3051\u306A\u3044\u6642\u306F\
    (-1,-1)\u3092\u8FD4\u3059.\n// \u8A08\u7B97\u91CF: O(nlogmax|M_i|),n\u306F\u5F0F\
    \u306E\u6570\ntemplate <typename T>\npair<T, T> linear_congruence(const vector<T>\
    \ &A, const vector<T> &B, const vector<T> &M) {\n    T x = 0, m = 1;\n    for\
    \ (int i = 0; i < (int)A.size(); i++) {\n        T a = A[i] * m, b = B[i] - A[i]\
    \ * x, d = gcd(M[i], a);\n        if (b % d != 0) return make_pair(-1, -1);\n\
    \        T t = b / d * inv_mod(a / d, M[i] / d) % (M[i] / d);\n        x += m\
    \ * t;\n        m *= M[i] / d;\n    }\n    return make_pair((m + x % m) % m, m);\n\
    }\n\n// garner\n// forall i, x = R_i mod M_i <=> x = b mod m\n// \u3068\u304B\u3051\
    \u308B\u3068\u304D\u306B(b,m)\u306E\u7D44\u3092\u8FD4\u3059. \u305F\u3060\u3057\
    (0 <= b < m)\u3092\u307F\u305F\u3059. \u3053\u306E\u3088\u3046\u306B\u66F8\u3051\
    \u306A\u3044\u6642\u306F(-1,-1)\u3092\u8FD4\u3059.\n// \u8A08\u7B97\u91CF: O(nlogmax|M_i|),n\u306F\
    \u5F0F\u306E\u6570\ntemplate <typename T>\npair<T, T> garner(const vector<T> &R,\
    \ const vector<T> &M) {\n    vector<T> A(R.size(), 1);\n    return linear_congruence(A,\
    \ R, M);\n}\n\n// a\u306Ek\u4E57\u6839\u3092\u6C42\u3081\u308B\nlong long root_int(long\
    \ long a, int k) {\n    if (k == 0) return 0;\n    long long x = pow(a, (double)1.0\
    \ / k);\n    while (pow(x, k) > a)\n        x--;\n    while (pow(x + 1, k) <=\
    \ a)\n        x++;\n    return x;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"euclid.cpp\"\n\n// pow_mod\n// x^k mod m\u3092\u8A08\u7B97\u3059\u308B.\n\
    // \u8A08\u7B97\u91CF: O(logk)\ntemplate <typename T>\nT pow_mod(T x, long long\
    \ k, int m) {\n    T ret = T(1);\n    while (k > 0) {\n        if (k & 1) {\n\
    \            ret *= x;\n            ret %= m;\n        }\n        k >>= 1;\n \
    \       x *= x;\n        x %= m;\n    }\n    return ret;\n}\n\n// inv_mod\n//\
    \ ax = 1 (mod m) \u306A\u308Bx (0 <= x < m)\u304C\u5B58\u5728\u3059\u308B\u306A\
    \u3089\u3070\n// \u305D\u308C\u3092\u8FD4\u3057, \u5B58\u5728\u3057\u306A\u3051\
    \u308C\u3070-1\u3092\u8FD4\u3059.\n// \u8A08\u7B97\u91CF: O(log|max(a,m)|)\ntemplate\
    \ <typename T>\nT inv_mod(T a, T m) {\n    auto [x, y] = ext_gcd(a, m);\n    T\
    \ g         = a * x + m * y;\n    if (g != 1) return -1;\n    return (m + x %\
    \ m) % m;\n}\n\n// linear_congruence\n// forall i,A_i x = B_i mod M_i <=> x =\
    \ b mod m\n// \u3068\u304B\u3051\u308B\u3068\u304D\u306B(b,m)\u306E\u7D44\u3092\
    \u8FD4\u3059. \u305F\u3060\u3057(0 <= b < m)\u3092\u307F\u305F\u3059. \u3053\u306E\
    \u3088\u3046\u306B\u66F8\u3051\u306A\u3044\u6642\u306F(-1,-1)\u3092\u8FD4\u3059\
    .\n// \u8A08\u7B97\u91CF: O(nlogmax|M_i|),n\u306F\u5F0F\u306E\u6570\ntemplate\
    \ <typename T>\npair<T, T> linear_congruence(const vector<T> &A, const vector<T>\
    \ &B, const vector<T> &M) {\n    T x = 0, m = 1;\n    for (int i = 0; i < (int)A.size();\
    \ i++) {\n        T a = A[i] * m, b = B[i] - A[i] * x, d = gcd(M[i], a);\n   \
    \     if (b % d != 0) return make_pair(-1, -1);\n        T t = b / d * inv_mod(a\
    \ / d, M[i] / d) % (M[i] / d);\n        x += m * t;\n        m *= M[i] / d;\n\
    \    }\n    return make_pair((m + x % m) % m, m);\n}\n\n// garner\n// forall i,\
    \ x = R_i mod M_i <=> x = b mod m\n// \u3068\u304B\u3051\u308B\u3068\u304D\u306B\
    (b,m)\u306E\u7D44\u3092\u8FD4\u3059. \u305F\u3060\u3057(0 <= b < m)\u3092\u307F\
    \u305F\u3059. \u3053\u306E\u3088\u3046\u306B\u66F8\u3051\u306A\u3044\u6642\u306F\
    (-1,-1)\u3092\u8FD4\u3059.\n// \u8A08\u7B97\u91CF: O(nlogmax|M_i|),n\u306F\u5F0F\
    \u306E\u6570\ntemplate <typename T>\npair<T, T> garner(const vector<T> &R, const\
    \ vector<T> &M) {\n    vector<T> A(R.size(), 1);\n    return linear_congruence(A,\
    \ R, M);\n}\n\n// a\u306Ek\u4E57\u6839\u3092\u6C42\u3081\u308B\nlong long root_int(long\
    \ long a, int k) {\n    if (k == 0) return 0;\n    long long x = pow(a, (double)1.0\
    \ / k);\n    while (pow(x, k) > a)\n        x--;\n    while (pow(x + 1, k) <=\
    \ a)\n        x++;\n    return x;\n}\n"
  dependsOn:
  - math/euclid.cpp
  isVerificationFile: false
  path: math/number_theory.cpp
  requiredBy: []
  timestamp: '2022-09-22 13:17:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/garner.test.cpp
documentation_of: math/number_theory.cpp
layout: document
redirect_from:
- /library/math/number_theory.cpp
- /library/math/number_theory.cpp.html
title: math/number_theory.cpp
---
