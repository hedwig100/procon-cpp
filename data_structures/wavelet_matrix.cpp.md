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
  bundledCode: "#line 2 \"data_structures/wavelet_matrix.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct FullyIndexableDictionary {\n    int bit_size, block_size;\n\
    \    vector<unsigned int> bit;\n    vector<int> block;\n\n    FullyIndexableDictionary(int\
    \ bit_size = 0) : bit_size(bit_size), block_size((bit_size + 32 - 1) >> 5) {\n\
    \        bit.resize(bit_size, 0);\n        block.resize(block_size, 0);\n    }\n\
    \n    // set(k) set the k-th bit\n    // constraint: 0 <= k < bit_size\n    //\
    \ time complexity: O(1)\n    void set(int k) {\n        bit[k >> 5] |= 1U << (k\
    \ & 31);\n    }\n\n    void build() {\n        block[0] = 0;\n        for (int\
    \ i = 1; i < block_size; ++i) {\n            block[i] = block[i - 1] + __builtin_popcount(bit[i\
    \ - 1]);\n        }\n    }\n\n    // op[k] returns k-th bit\n    // constraint:\
    \ 0 <= k < bit_size\n    // time complexity: O(1)\n    bool operator[](int k)\
    \ {\n        return bool((bit[k >> 5] >> (k & 31)) & 1U);\n    }\n\n    // _rank(k)\
    \ returns the number of 1 in [0,k)\n    // constraint: 0 <= k <= bit_size\n  \
    \  // time complexity: O(1)\n    int _rank(int k) {\n        return block[k >>\
    \ 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1));\n    }\n\n  \
    \  // rank(v,k) returns the number of v in [0,k)\n    // constraint: 0 <= k <=\
    \ bit_size,(v = 0 or v = 1)\n    // time complexity: O(1)\n    int rank(bool v,\
    \ int k) {\n        return (v ? _rank(k) : k - _rank(k));\n    }\n\n    // select(v,k)\
    \ returns the k-th position of v\n    // constraint: k >= 0, (v = 0 or v = 1)\n\
    \    // time complexity: O(logN),N = bit_size\n    int select(bool v, int k) {\n\
    \        if (k < 0 || rank(v, bit_size) <= k) return -1;\n        int l = 0, r\
    \ = bit_size;\n        while (r - l > 1) {\n            int mid = (r + l) >> 1;\n\
    \            if (rank(v, mid) >= k + 1)\n                r = mid;\n          \
    \  else\n                l = mid;\n        }\n        return r - 1;\n    }\n\n\
    \    int select(bool v, int i, int l) {\n        return select(v, i + rank(v,\
    \ l));\n    }\n};\n\ntemplate <class T, int MAXLOG>\nstruct WaveletMatrix {\n\
    \    int len;\n    FullyIndexableDictionary mat[MAXLOG];\n    int zeros[MAXLOG],\
    \ buff1[MAXLOG], buff2[MAXLOG];\n\n    WaveletMatrix(vector<T> data) {\n     \
    \   len = data.size();\n        vector<T> l(len), r(len);\n        for (int dep\
    \ = 0; dep < MAXLOG; ++dep) {\n            mat[dep] = FullyIndexableDictionary(len\
    \ + 1);\n            int p = 0, q = 0;\n            for (int i = 0; i < len; ++i)\
    \ {\n                bool k = (data[i] >> (MAXLOG - (dep + 1))) & 1;\n       \
    \         if (k)\n                    r[q++] = data[i], mat[dep].set(i);\n   \
    \             else\n                    l[p++] = data[i];\n            }\n   \
    \         zeros[dep] = p;\n            mat[dep].build();\n            swap(l,\
    \ data);\n            for (int i = 0; i < q; ++i)\n                data[p + i]\
    \ = r[i];\n        }\n    }\n    T access(int k) {\n        T res    = 0;\n  \
    \      bool bit = 0;\n        for (int dep = 0; dep < MAXLOG; ++dep) {\n     \
    \       bit = mat[dep][k];\n            res = (res << 1) | bit;\n            k\
    \   = mat[dep].rank(bit, k) + zeros[dep] * bit;\n        }\n        return res;\n\
    \    }\n    // return the number of v in [0,k)\n    int rank(T v, int k) {\n \
    \       int l = 0, r = k;\n        for (int dep = 0; dep < MAXLOG; ++dep) {\n\
    \            buff1[dep] = l, buff2[dep] = r;\n            bool bit = (v >> (MAXLOG\
    \ - (dep + 1))) & 1;\n            l        = mat[dep].rank(bit, l) + zeros[dep]\
    \ * bit;\n            r        = mat[dep].rank(bit, r) + zeros[dep] * bit;\n \
    \       }\n        return r - l;\n    }\n    // return the position of k-th v\n\
    \    int select(T v, int k) {\n        rank(v, len);\n        for (int dep = MAXLOG\
    \ - 1; dep >= 0; --dep) {\n            bool bit = (v >> (MAXLOG - (dep + 1)))\
    \ & 1;\n            k        = mat[dep].select(bit, k, buff1[dep]);\n        \
    \    if (k >= buff2[dep] || k < 0) return -1;\n            k -= buff1[dep];\n\
    \        }\n        return k;\n    }\n    // return k-th largest value in [l,r)\n\
    \    T quantile(int l, int r, int k) {\n        if (r - l <= k || k < 0) return\
    \ -1;\n        T res = 0;\n        for (int dep = 0; dep < MAXLOG; ++dep) {\n\
    \            int p = mat[dep].rank(1, l);\n            int q = mat[dep].rank(1,\
    \ r);\n            if (q - p < k) {\n                l = p + zeros[dep];\n   \
    \             r = q + zeros[dep];\n                res |= (T(1) << (MAXLOG - (dep\
    \ + 1)));\n            } else {\n                k -= (q - p);\n             \
    \   l -= p;\n                r -= q;\n            }\n        }\n        return\
    \ res;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct FullyIndexableDictionary\
    \ {\n    int bit_size, block_size;\n    vector<unsigned int> bit;\n    vector<int>\
    \ block;\n\n    FullyIndexableDictionary(int bit_size = 0) : bit_size(bit_size),\
    \ block_size((bit_size + 32 - 1) >> 5) {\n        bit.resize(bit_size, 0);\n \
    \       block.resize(block_size, 0);\n    }\n\n    // set(k) set the k-th bit\n\
    \    // constraint: 0 <= k < bit_size\n    // time complexity: O(1)\n    void\
    \ set(int k) {\n        bit[k >> 5] |= 1U << (k & 31);\n    }\n\n    void build()\
    \ {\n        block[0] = 0;\n        for (int i = 1; i < block_size; ++i) {\n \
    \           block[i] = block[i - 1] + __builtin_popcount(bit[i - 1]);\n      \
    \  }\n    }\n\n    // op[k] returns k-th bit\n    // constraint: 0 <= k < bit_size\n\
    \    // time complexity: O(1)\n    bool operator[](int k) {\n        return bool((bit[k\
    \ >> 5] >> (k & 31)) & 1U);\n    }\n\n    // _rank(k) returns the number of 1\
    \ in [0,k)\n    // constraint: 0 <= k <= bit_size\n    // time complexity: O(1)\n\
    \    int _rank(int k) {\n        return block[k >> 5] + __builtin_popcount(bit[k\
    \ >> 5] & ((1U << (k & 31)) - 1));\n    }\n\n    // rank(v,k) returns the number\
    \ of v in [0,k)\n    // constraint: 0 <= k <= bit_size,(v = 0 or v = 1)\n    //\
    \ time complexity: O(1)\n    int rank(bool v, int k) {\n        return (v ? _rank(k)\
    \ : k - _rank(k));\n    }\n\n    // select(v,k) returns the k-th position of v\n\
    \    // constraint: k >= 0, (v = 0 or v = 1)\n    // time complexity: O(logN),N\
    \ = bit_size\n    int select(bool v, int k) {\n        if (k < 0 || rank(v, bit_size)\
    \ <= k) return -1;\n        int l = 0, r = bit_size;\n        while (r - l > 1)\
    \ {\n            int mid = (r + l) >> 1;\n            if (rank(v, mid) >= k +\
    \ 1)\n                r = mid;\n            else\n                l = mid;\n \
    \       }\n        return r - 1;\n    }\n\n    int select(bool v, int i, int l)\
    \ {\n        return select(v, i + rank(v, l));\n    }\n};\n\ntemplate <class T,\
    \ int MAXLOG>\nstruct WaveletMatrix {\n    int len;\n    FullyIndexableDictionary\
    \ mat[MAXLOG];\n    int zeros[MAXLOG], buff1[MAXLOG], buff2[MAXLOG];\n\n    WaveletMatrix(vector<T>\
    \ data) {\n        len = data.size();\n        vector<T> l(len), r(len);\n   \
    \     for (int dep = 0; dep < MAXLOG; ++dep) {\n            mat[dep] = FullyIndexableDictionary(len\
    \ + 1);\n            int p = 0, q = 0;\n            for (int i = 0; i < len; ++i)\
    \ {\n                bool k = (data[i] >> (MAXLOG - (dep + 1))) & 1;\n       \
    \         if (k)\n                    r[q++] = data[i], mat[dep].set(i);\n   \
    \             else\n                    l[p++] = data[i];\n            }\n   \
    \         zeros[dep] = p;\n            mat[dep].build();\n            swap(l,\
    \ data);\n            for (int i = 0; i < q; ++i)\n                data[p + i]\
    \ = r[i];\n        }\n    }\n    T access(int k) {\n        T res    = 0;\n  \
    \      bool bit = 0;\n        for (int dep = 0; dep < MAXLOG; ++dep) {\n     \
    \       bit = mat[dep][k];\n            res = (res << 1) | bit;\n            k\
    \   = mat[dep].rank(bit, k) + zeros[dep] * bit;\n        }\n        return res;\n\
    \    }\n    // return the number of v in [0,k)\n    int rank(T v, int k) {\n \
    \       int l = 0, r = k;\n        for (int dep = 0; dep < MAXLOG; ++dep) {\n\
    \            buff1[dep] = l, buff2[dep] = r;\n            bool bit = (v >> (MAXLOG\
    \ - (dep + 1))) & 1;\n            l        = mat[dep].rank(bit, l) + zeros[dep]\
    \ * bit;\n            r        = mat[dep].rank(bit, r) + zeros[dep] * bit;\n \
    \       }\n        return r - l;\n    }\n    // return the position of k-th v\n\
    \    int select(T v, int k) {\n        rank(v, len);\n        for (int dep = MAXLOG\
    \ - 1; dep >= 0; --dep) {\n            bool bit = (v >> (MAXLOG - (dep + 1)))\
    \ & 1;\n            k        = mat[dep].select(bit, k, buff1[dep]);\n        \
    \    if (k >= buff2[dep] || k < 0) return -1;\n            k -= buff1[dep];\n\
    \        }\n        return k;\n    }\n    // return k-th largest value in [l,r)\n\
    \    T quantile(int l, int r, int k) {\n        if (r - l <= k || k < 0) return\
    \ -1;\n        T res = 0;\n        for (int dep = 0; dep < MAXLOG; ++dep) {\n\
    \            int p = mat[dep].rank(1, l);\n            int q = mat[dep].rank(1,\
    \ r);\n            if (q - p < k) {\n                l = p + zeros[dep];\n   \
    \             r = q + zeros[dep];\n                res |= (T(1) << (MAXLOG - (dep\
    \ + 1)));\n            } else {\n                k -= (q - p);\n             \
    \   l -= p;\n                r -= q;\n            }\n        }\n        return\
    \ res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structures/wavelet_matrix.cpp
  requiredBy: []
  timestamp: '2022-08-27 12:40:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structures/wavelet_matrix.cpp
layout: document
redirect_from:
- /library/data_structures/wavelet_matrix.cpp
- /library/data_structures/wavelet_matrix.cpp.html
title: data_structures/wavelet_matrix.cpp
---
