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
  bundledCode: "#line 2 \"data_structures/binary_indexed_tree2d.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// BinaryIndexedTree2D\ntemplate <typename T>\nstruct\
    \ BinaryIndexedTree2D {\n    int h, w;\n    vector<vector<T>> data;\n\n    BinaryIndexedTree2D(int\
    \ h, int w) : h(h), w(w) {\n        data.assign(h + 1, std::vector<T>(w + 1, 0));\n\
    \    }\n\n    // add\n    // A[k][l] += x\u3068\u3059\u308B.\n    // \u5236\u7D04\
    : 0 <= k < h,0 <= l < w\n    // \u8A08\u7B97\u91CF: O(loghlogw)\n    void add(int\
    \ k, int l, T x) {\n        k++, l++;\n        for (int i = k; i <= h; i += (i\
    \ & -i)) {\n            for (int j = l; j <= w; j += (j & -j)) {\n           \
    \     data[i][j] += x;\n            }\n        }\n    }\n\n    // _sum\n    //\
    \ \u03A3_{0 <= i <= k,0 <= j <= l} A[i][j]\u3092\u6C42\u3081\u308B.\n    // \u5236\
    \u7D04: 0 <= k < h,0 <= l < w\n    // \u8A08\u7B97\u91CF: O(loghlogw)\n    T _sum(int\
    \ k, int l) {\n        if (k < 0 || l < 0) return 0;\n        k = min(k, h - 1);\n\
    \        l = min(l, w - 1);\n\n        T ret = 0;\n        k++, l++;\n       \
    \ for (int i = k; i > 0; i -= (i & -i)) {\n            for (int j = l; j > 0;\
    \ j -= (j & -j)) {\n                ret += data[i][j];\n            }\n      \
    \  }\n        return ret;\n    }\n\n    // sum\n    // \u03A3_{h1 <= i < h2 and\
    \ w1 <= j < w2}A[i][j]\u3092\u6C42\u3081\u308B.\n    // \u5236\u7D04: 0 <= h1\
    \ <= h2 <= h,0 <= w1 <= w2 <= w\n    // \u8A08\u7B97\u91CF: O(loghlogw)\n    T\
    \ sum(int h1, int h2, int w1, int w2) {\n        return _sum(h2 - 1, w2 - 1) -\
    \ _sum(h2 - 1, w1 - 1) - _sum(h1 - 1, w2 - 1) + _sum(h1 - 1, w1 - 1);\n    }\n\
    };\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// BinaryIndexedTree2D\n\
    template <typename T>\nstruct BinaryIndexedTree2D {\n    int h, w;\n    vector<vector<T>>\
    \ data;\n\n    BinaryIndexedTree2D(int h, int w) : h(h), w(w) {\n        data.assign(h\
    \ + 1, std::vector<T>(w + 1, 0));\n    }\n\n    // add\n    // A[k][l] += x\u3068\
    \u3059\u308B.\n    // \u5236\u7D04: 0 <= k < h,0 <= l < w\n    // \u8A08\u7B97\
    \u91CF: O(loghlogw)\n    void add(int k, int l, T x) {\n        k++, l++;\n  \
    \      for (int i = k; i <= h; i += (i & -i)) {\n            for (int j = l; j\
    \ <= w; j += (j & -j)) {\n                data[i][j] += x;\n            }\n  \
    \      }\n    }\n\n    // _sum\n    // \u03A3_{0 <= i <= k,0 <= j <= l} A[i][j]\u3092\
    \u6C42\u3081\u308B.\n    // \u5236\u7D04: 0 <= k < h,0 <= l < w\n    // \u8A08\
    \u7B97\u91CF: O(loghlogw)\n    T _sum(int k, int l) {\n        if (k < 0 || l\
    \ < 0) return 0;\n        k = min(k, h - 1);\n        l = min(l, w - 1);\n\n \
    \       T ret = 0;\n        k++, l++;\n        for (int i = k; i > 0; i -= (i\
    \ & -i)) {\n            for (int j = l; j > 0; j -= (j & -j)) {\n            \
    \    ret += data[i][j];\n            }\n        }\n        return ret;\n    }\n\
    \n    // sum\n    // \u03A3_{h1 <= i < h2 and w1 <= j < w2}A[i][j]\u3092\u6C42\
    \u3081\u308B.\n    // \u5236\u7D04: 0 <= h1 <= h2 <= h,0 <= w1 <= w2 <= w\n  \
    \  // \u8A08\u7B97\u91CF: O(loghlogw)\n    T sum(int h1, int h2, int w1, int w2)\
    \ {\n        return _sum(h2 - 1, w2 - 1) - _sum(h2 - 1, w1 - 1) - _sum(h1 - 1,\
    \ w2 - 1) + _sum(h1 - 1, w1 - 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structures/binary_indexed_tree2d.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structures/binary_indexed_tree2d.cpp
layout: document
redirect_from:
- /library/data_structures/binary_indexed_tree2d.cpp
- /library/data_structures/binary_indexed_tree2d.cpp.html
title: data_structures/binary_indexed_tree2d.cpp
---
