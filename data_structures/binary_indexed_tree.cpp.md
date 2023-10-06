---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/binary_indexed_tree.test.cpp
    title: test/binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/inversion_number.test.cpp
    title: test/inversion_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structures/binary_indexed_tree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// BinaryIndexedTree\n// \u53EF\u63DB\u7FA4T\u306B\u3064\
    \u3044\u3066\u4EE5\u4E0B\u306E\u4E8C\u3064\u306E\u64CD\u4F5C\u304C\u53EF\u80FD\
    \n//\n// 1. A[0] + A[1] + ... + A[k] \u3092\u6C42\u3081\u308B.\n// 2. A[k] +=\
    \ x \u3068\u66F4\u65B0.\n//\ntemplate <typename T>\nstruct BinaryIndexedTree {\n\
    \    int n, size;\n    int power;\n    vector<T> data;\n\n    BinaryIndexedTree(int\
    \ n) : n(n) {\n        size = 1;\n        while (size < n)\n            size <<=\
    \ 1;\n        data.assign(size + 1, 0);\n    }\n\n    // build\n    // A\u3067\
    \u521D\u671F\u5316\n    void build(const vector<T> &A) {\n        for (int i =\
    \ 0; i < n; ++i)\n            add(i, A[i]);\n    }\n\n    // add\n    // A[k]\u306B\
    x\u3092\u52A0\u3048\u308B.\n    // \u5236\u7D04: 0 <= k < n\n    // \u8A08\u7B97\
    \u91CF: O(logn)\n    void add(int k, T x) {\n        for (int i = ++k; i <= n;\
    \ i += (i & -i)) {\n            data[i] += x;\n        }\n    }\n\n    // sum\n\
    \    // \u03A3_{0 <= i <= k} A[i]\u3092\u6C42\u3081\u308B.\n    // \u5236\u7D04\
    : 0 <= k < n (\u305D\u308C\u4EE5\u5916\u306F0\u3092\u8FD4\u3059)\n    // \u8A08\
    \u7B97\u91CF: O(logn)\n    T sum(int k) {\n        if (k < 0) return 0;\n    \
    \    k = min(k, n - 1);\n\n        T ret = 0;\n        for (int i = ++k; i > 0;\
    \ i -= (i & -i)) {\n            ret += data[i];\n        }\n        return ret;\n\
    \    }\n\n    // sum\n    // \u03A3_{l <= i < r} A[i]\u3092\u6C42\u3081\u308B\
    .\n    // \u5236\u7D04: 0 <= l <= r <= N\n    // \u8A08\u7B97\u91CF: O(logN)\n\
    \    T sum(int l, int r) {\n        return sum(r - 1) - sum(l - 1);\n    }\n\n\
    \    // lower_bound\n    // \u03A3_{0 <= i <= k} >= x \u3092\u6E80\u305F\u3059\
    \u6700\u5C0F\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9k\u3092\u8FD4\u3059. \u305D\
    \u306E\u3088\u3046\u306A\u3082\u306E\u304C\u5B58\u5728\u3057\u306A\u3051\u308C\
    \u3070n\u3092\u8FD4\u3059.\n    // \u5236\u7D04: A[i] >= 0\n    // \u8A08\u7B97\
    \u91CF: O(logN)\n    int lower_bound(T x) {\n        int k = 0;\n        for (int\
    \ r = size; r > 0; r >>= 1) {\n            if (k + r <= size && data[k + r] <\
    \ x) {\n                x -= data[k + r];\n                k += r;\n         \
    \   }\n        }\n        return min(k, n);\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// BinaryIndexedTree\n\
    // \u53EF\u63DB\u7FA4T\u306B\u3064\u3044\u3066\u4EE5\u4E0B\u306E\u4E8C\u3064\u306E\
    \u64CD\u4F5C\u304C\u53EF\u80FD\n//\n// 1. A[0] + A[1] + ... + A[k] \u3092\u6C42\
    \u3081\u308B.\n// 2. A[k] += x \u3068\u66F4\u65B0.\n//\ntemplate <typename T>\n\
    struct BinaryIndexedTree {\n    int n, size;\n    int power;\n    vector<T> data;\n\
    \n    BinaryIndexedTree(int n) : n(n) {\n        size = 1;\n        while (size\
    \ < n)\n            size <<= 1;\n        data.assign(size + 1, 0);\n    }\n\n\
    \    // build\n    // A\u3067\u521D\u671F\u5316\n    void build(const vector<T>\
    \ &A) {\n        for (int i = 0; i < n; ++i)\n            add(i, A[i]);\n    }\n\
    \n    // add\n    // A[k]\u306Bx\u3092\u52A0\u3048\u308B.\n    // \u5236\u7D04\
    : 0 <= k < n\n    // \u8A08\u7B97\u91CF: O(logn)\n    void add(int k, T x) {\n\
    \        for (int i = ++k; i <= n; i += (i & -i)) {\n            data[i] += x;\n\
    \        }\n    }\n\n    // sum\n    // \u03A3_{0 <= i <= k} A[i]\u3092\u6C42\u3081\
    \u308B.\n    // \u5236\u7D04: 0 <= k < n (\u305D\u308C\u4EE5\u5916\u306F0\u3092\
    \u8FD4\u3059)\n    // \u8A08\u7B97\u91CF: O(logn)\n    T sum(int k) {\n      \
    \  if (k < 0) return 0;\n        k = min(k, n - 1);\n\n        T ret = 0;\n  \
    \      for (int i = ++k; i > 0; i -= (i & -i)) {\n            ret += data[i];\n\
    \        }\n        return ret;\n    }\n\n    // sum\n    // \u03A3_{l <= i <\
    \ r} A[i]\u3092\u6C42\u3081\u308B.\n    // \u5236\u7D04: 0 <= l <= r <= N\n  \
    \  // \u8A08\u7B97\u91CF: O(logN)\n    T sum(int l, int r) {\n        return sum(r\
    \ - 1) - sum(l - 1);\n    }\n\n    // lower_bound\n    // \u03A3_{0 <= i <= k}\
    \ >= x \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9k\u3092\u8FD4\u3059. \u305D\u306E\u3088\u3046\u306A\u3082\u306E\u304C\u5B58\
    \u5728\u3057\u306A\u3051\u308C\u3070n\u3092\u8FD4\u3059.\n    // \u5236\u7D04\
    : A[i] >= 0\n    // \u8A08\u7B97\u91CF: O(logN)\n    int lower_bound(T x) {\n\
    \        int k = 0;\n        for (int r = size; r > 0; r >>= 1) {\n          \
    \  if (k + r <= size && data[k + r] < x) {\n                x -= data[k + r];\n\
    \                k += r;\n            }\n        }\n        return min(k, n);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structures/binary_indexed_tree.cpp
  requiredBy: []
  timestamp: '2022-09-05 23:20:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/binary_indexed_tree.test.cpp
  - test/inversion_number.test.cpp
documentation_of: data_structures/binary_indexed_tree.cpp
layout: document
redirect_from:
- /library/data_structures/binary_indexed_tree.cpp
- /library/data_structures/binary_indexed_tree.cpp.html
title: data_structures/binary_indexed_tree.cpp
---
