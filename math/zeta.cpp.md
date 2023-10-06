---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/gcd_convolutiion.test.cpp
    title: test/gcd_convolutiion.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/zeta.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// a <= b <=> a <= b\n// g[x] = \\\\sum_{ i <= x } f[i]\ntemplate <class\
    \ R>\nstruct ZetaOrder {\n    // TODO:verify\n  public:\n    ZetaOrder() {}\n\n\
    \    void zeta(std::vector<R> &f) {\n        int sz = (int)f.size();\n       \
    \ for (int x = 1; x < sz; x++) {\n            f[x] += f[x - 1];\n        }\n \
    \   }\n\n    void mebius(std::vector<R> &f) {\n        int sz = (int)f.size();\n\
    \        for (int x = sz - 1; x >= 1; x--) {\n            f[x] -= f[x - 1];\n\
    \        }\n    }\n\n    std::vector<R> convolve(std::vector<R> f, std::vector<R>\
    \ g) {\n        int sz = std::max((int)f.size(), (int)g.size());\n        f.resize(sz,\
    \ 0);\n        g.resize(sz, 0);\n        zeta(f);\n        zeta(g);\n        std::vector<R>\
    \ h(sz);\n        for (int i = 0; i < sz; i++) {\n            h[i] = f[i] * g[i];\n\
    \        }\n        mebius(h);\n        return h;\n    }\n};\n\n// min_pow2 returns\
    \ minimum power of 2 larger than x (x <= 2^i)\n// and i (pair{i,2^i}).\n// x must\
    \ be more than 0\ntemplate <class T>\nstd::pair<int, T> min_pow2(T x) {\n    int\
    \ i = 0;\n    T ret = 1;\n    while (x > ret) {\n        i++;\n        ret <<=\
    \ 1;\n    }\n    return std::make_pair(i, ret);\n}\n\n// S <= T <=> S \\subset\
    \ T\n// g[T] = \\sum_{ S \\subset T } f[S]\ntemplate <class R>\nstruct ZetaSubset\
    \ {\n    // TODO:verify\n  private:\n    // min_pow2 returns minimum power of\
    \ 2 larger than x (x <= 2^i)\n    // and i (pair{i,2^i}).\n    // x must be more\
    \ than 0\n    std::pair<int, int> min_pow2(int x) {\n        int i   = 0;\n  \
    \      int ret = 1;\n        while (x > ret) {\n            i++;\n           \
    \ ret <<= 1;\n        }\n        return std::make_pair(i, ret);\n    }\n\n  public:\n\
    \    ZetaSubset() {}\n\n    void zeta(std::vector<R> &f) {\n        auto [d, sz]\
    \ = min_pow2((int)f.size());\n        f.resize(sz, (R)0);\n        for (int i\
    \ = 0; i < d; i++) {\n            for (int T = 0; T < sz; T++) {\n           \
    \     if (T & (1 << i))\n                    f[T] += f[T ^ (1 << i)];\n      \
    \      }\n        }\n    }\n\n    void mebius(std::vector<R> &f) {\n        auto\
    \ [d, sz] = min_pow2((int)f.size());\n        f.resize(sz, (R)0);\n        for\
    \ (int i = 0; i < d; i++) {\n            for (int T = 0; T < sz; T++) {\n    \
    \            if (T & (1 << i))\n                    f[T] -= f[T ^ (1 << i)];\n\
    \            }\n        }\n    }\n\n    std::vector<R> convolve(std::vector<R>\
    \ f, std::vector<R> g) {\n        int sz = std::max((int)f.size(), (int)g.size());\n\
    \        f.resize(sz, 0);\n        g.resize(sz, 0);\n        zeta(f);\n      \
    \  zeta(g);\n        std::vector<R> h(sz);\n        for (int i = 0; i < sz; i++)\
    \ {\n            h[i] = f[i] * g[i];\n        }\n        mebius(h);\n        return\
    \ h;\n    }\n};\n\n// a <= b <=> b | a\n// g[x] = \\sum_{ x | i } f[i]\ntemplate\
    \ <class R>\nstruct ZetaDiv {\n    // TODO: O(nloglogn) zeta transform\n  private:\n\
    \    // min_pow2 returns minimum power of 2 larger than x (x <= 2^i)\n    // and\
    \ i (pair{i,2^i}).\n    // x must be more than 0\n    std::pair<int, int> min_pow2(int\
    \ x) {\n        int i   = 0;\n        int ret = 1;\n        while (x > ret) {\n\
    \            i++;\n            ret <<= 1;\n        }\n        return std::make_pair(i,\
    \ ret);\n    }\n\n  public:\n    ZetaDiv() {}\n\n    void zeta(std::vector<R>\
    \ &f) {\n        int sz = (int)f.size();\n        for (int x = 1; x < sz; x++)\
    \ {\n            for (int i = 2 * x; i < sz; i += x) {\n                f[x] +=\
    \ f[i];\n            }\n        }\n    }\n\n    void mebius(std::vector<R> &f)\
    \ {\n        int sz = (int)f.size();\n        for (int x = sz - 1; x >= 1; x--)\
    \ {\n            for (int i = 2 * x; i < sz; i += x) {\n                f[x] -=\
    \ f[i];\n            }\n        }\n    }\n\n    std::vector<R> convolve(std::vector<R>\
    \ f, std::vector<R> g) {\n        int sz = std::min((int)f.size(), (int)g.size());\n\
    \        zeta(f);\n        zeta(g);\n        std::vector<R> h(sz);\n        for\
    \ (int i = 0; i < sz; i++) {\n            h[i] = f[i] * g[i];\n        }\n   \
    \     mebius(h);\n        return h;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// a <= b\
    \ <=> a <= b\n// g[x] = \\\\sum_{ i <= x } f[i]\ntemplate <class R>\nstruct ZetaOrder\
    \ {\n    // TODO:verify\n  public:\n    ZetaOrder() {}\n\n    void zeta(std::vector<R>\
    \ &f) {\n        int sz = (int)f.size();\n        for (int x = 1; x < sz; x++)\
    \ {\n            f[x] += f[x - 1];\n        }\n    }\n\n    void mebius(std::vector<R>\
    \ &f) {\n        int sz = (int)f.size();\n        for (int x = sz - 1; x >= 1;\
    \ x--) {\n            f[x] -= f[x - 1];\n        }\n    }\n\n    std::vector<R>\
    \ convolve(std::vector<R> f, std::vector<R> g) {\n        int sz = std::max((int)f.size(),\
    \ (int)g.size());\n        f.resize(sz, 0);\n        g.resize(sz, 0);\n      \
    \  zeta(f);\n        zeta(g);\n        std::vector<R> h(sz);\n        for (int\
    \ i = 0; i < sz; i++) {\n            h[i] = f[i] * g[i];\n        }\n        mebius(h);\n\
    \        return h;\n    }\n};\n\n// min_pow2 returns minimum power of 2 larger\
    \ than x (x <= 2^i)\n// and i (pair{i,2^i}).\n// x must be more than 0\ntemplate\
    \ <class T>\nstd::pair<int, T> min_pow2(T x) {\n    int i = 0;\n    T ret = 1;\n\
    \    while (x > ret) {\n        i++;\n        ret <<= 1;\n    }\n    return std::make_pair(i,\
    \ ret);\n}\n\n// S <= T <=> S \\subset T\n// g[T] = \\sum_{ S \\subset T } f[S]\n\
    template <class R>\nstruct ZetaSubset {\n    // TODO:verify\n  private:\n    //\
    \ min_pow2 returns minimum power of 2 larger than x (x <= 2^i)\n    // and i (pair{i,2^i}).\n\
    \    // x must be more than 0\n    std::pair<int, int> min_pow2(int x) {\n   \
    \     int i   = 0;\n        int ret = 1;\n        while (x > ret) {\n        \
    \    i++;\n            ret <<= 1;\n        }\n        return std::make_pair(i,\
    \ ret);\n    }\n\n  public:\n    ZetaSubset() {}\n\n    void zeta(std::vector<R>\
    \ &f) {\n        auto [d, sz] = min_pow2((int)f.size());\n        f.resize(sz,\
    \ (R)0);\n        for (int i = 0; i < d; i++) {\n            for (int T = 0; T\
    \ < sz; T++) {\n                if (T & (1 << i))\n                    f[T] +=\
    \ f[T ^ (1 << i)];\n            }\n        }\n    }\n\n    void mebius(std::vector<R>\
    \ &f) {\n        auto [d, sz] = min_pow2((int)f.size());\n        f.resize(sz,\
    \ (R)0);\n        for (int i = 0; i < d; i++) {\n            for (int T = 0; T\
    \ < sz; T++) {\n                if (T & (1 << i))\n                    f[T] -=\
    \ f[T ^ (1 << i)];\n            }\n        }\n    }\n\n    std::vector<R> convolve(std::vector<R>\
    \ f, std::vector<R> g) {\n        int sz = std::max((int)f.size(), (int)g.size());\n\
    \        f.resize(sz, 0);\n        g.resize(sz, 0);\n        zeta(f);\n      \
    \  zeta(g);\n        std::vector<R> h(sz);\n        for (int i = 0; i < sz; i++)\
    \ {\n            h[i] = f[i] * g[i];\n        }\n        mebius(h);\n        return\
    \ h;\n    }\n};\n\n// a <= b <=> b | a\n// g[x] = \\sum_{ x | i } f[i]\ntemplate\
    \ <class R>\nstruct ZetaDiv {\n    // TODO: O(nloglogn) zeta transform\n  private:\n\
    \    // min_pow2 returns minimum power of 2 larger than x (x <= 2^i)\n    // and\
    \ i (pair{i,2^i}).\n    // x must be more than 0\n    std::pair<int, int> min_pow2(int\
    \ x) {\n        int i   = 0;\n        int ret = 1;\n        while (x > ret) {\n\
    \            i++;\n            ret <<= 1;\n        }\n        return std::make_pair(i,\
    \ ret);\n    }\n\n  public:\n    ZetaDiv() {}\n\n    void zeta(std::vector<R>\
    \ &f) {\n        int sz = (int)f.size();\n        for (int x = 1; x < sz; x++)\
    \ {\n            for (int i = 2 * x; i < sz; i += x) {\n                f[x] +=\
    \ f[i];\n            }\n        }\n    }\n\n    void mebius(std::vector<R> &f)\
    \ {\n        int sz = (int)f.size();\n        for (int x = sz - 1; x >= 1; x--)\
    \ {\n            for (int i = 2 * x; i < sz; i += x) {\n                f[x] -=\
    \ f[i];\n            }\n        }\n    }\n\n    std::vector<R> convolve(std::vector<R>\
    \ f, std::vector<R> g) {\n        int sz = std::min((int)f.size(), (int)g.size());\n\
    \        zeta(f);\n        zeta(g);\n        std::vector<R> h(sz);\n        for\
    \ (int i = 0; i < sz; i++) {\n            h[i] = f[i] * g[i];\n        }\n   \
    \     mebius(h);\n        return h;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/zeta.cpp
  requiredBy: []
  timestamp: '2022-08-27 12:40:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/gcd_convolutiion.test.cpp
documentation_of: math/zeta.cpp
layout: document
redirect_from:
- /library/math/zeta.cpp
- /library/math/zeta.cpp.html
title: math/zeta.cpp
---
