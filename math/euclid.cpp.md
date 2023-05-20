---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/number_theory.cpp
    title: math/number_theory.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ext_gcd.test.cpp
    title: test/ext_gcd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/garner.test.cpp
    title: test/garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/gcd.test.cpp
    title: test/gcd.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/euclid.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// gcd\n// \u975E\u8CA0\u6574\u6570a,b\u306E\u6700\u5927\u516C\u7D04\
    \u6570\u3092\u6C42\u3081\u308B.\n// \u5236\u7D04: a,b >= 0\n// \u8A08\u7B97\u91CF\
    : O(logmax(a,b))\ntemplate <typename T>\nT gcd(T a, T b) { return (b ? gcd(b,\
    \ a % b) : a); }\n\n// lcm\n// \u975E\u8CA0\u6574\u6570a,b\u306E\u6700\u5C0F\u516C\
    \u500D\u6570\u3092\u6C42\u3081\u308B.\n// \u5236\u7D04: a,b >= 0\n// \u8A08\u7B97\
    \u91CF: O(logmax(a,b))\ntemplate <typename T>\nT lcm(T a, T b) { return a / gcd(a,\
    \ b) * b; }\n\n// ext_gcd\n// \u62E1\u5F35Euclid\u306E\u4E92\u9664\u6CD5\u3067\
    \u975E\u8CA0\u6574\u6570a,b\u306B\u5BFE\u3057\u3066ax + by = gcd(a,b)\u3092\u6E80\
    \u305F\u3059\u6574\u6570x,y\u3092\u6C42\u3081\u308B.\n// \u51FA\u529B\u3055\u308C\
    \u308B\u5024\u306F xy != 0 \u306A\u3089\u3070 |x| <= b,|y| <= a \u3092\u6E80\u305F\
    \u3059.\n// \u5236\u7D04: a,b >= 0\n// \u8A08\u7B97\u91CF: O(logmax(a,b))\ntemplate\
    \ <typename T>\npair<T, T> ext_gcd(T a, T b) {\n    if (b == 0) {\n        return\
    \ make_pair(1, 0);\n    }\n    auto [x, y] = ext_gcd(b, a % b);\n    return make_pair(y,\
    \ x - a / b * y);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// gcd\n\
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
    \ b * y);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/euclid.cpp
  requiredBy:
  - math/number_theory.cpp
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/garner.test.cpp
  - test/gcd.test.cpp
  - test/ext_gcd.test.cpp
documentation_of: math/euclid.cpp
layout: document
redirect_from:
- /library/math/euclid.cpp
- /library/math/euclid.cpp.html
title: math/euclid.cpp
---
