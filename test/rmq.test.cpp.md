---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structures/segment_tree.cpp
    title: data_structures/segment_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
  bundledCode: "#line 1 \"test/rmq.test.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp\"\
    \n#line 3 \"data_structures/segment_tree.cpp\"\nusing namespace std;\n\n// SegmentTree\n\
    // Mon\u306F\u30E2\u30CE\u30A4\u30C9, \u3059\u306A\u308F\u3061 *: Mon \xD7 Mon\
    \ -> Mon\u306A\u308B\u6F14\u7B97\u3068e(\u5358\u4F4D\u5143)\u304C\u3042\u3063\u3066\
    ,\n// \u4EE5\u4E0B\u3092\u6E80\u305F\u3059\u3082\u306E.\n// - e * a = a * e =\
    \ a\n// - a * (b * c) = (a * b) * c\n//\n// \u4EE5\u4E0B\u306E\u4E8C\u3064\u306E\
    \u64CD\u4F5C\u304C\u3067\u304D\u308B.\n// 1. A[x]\u3092\u66F4\u65B0\u3059\u308B\
    \n// 2. A[l]*...*A[r-1] \u3092\u8A08\u7B97\u3059\u308B\ntemplate <typename Mon>\n\
    struct SegmentTree {\n    using Fx = function<Mon(Mon, Mon)>;\n\n    int n;\n\
    \    int size;\n    vector<Mon> tree;\n    Fx op;\n    Mon e;\n\n    SegmentTree(int\
    \ n, Fx op, Mon e) : n(n), op(op), e(e) {\n        size = 1;\n        while (size\
    \ < n)\n            size <<= 1;\n        tree.assign(2 * size, e);\n    }\n\n\
    \    // build\n    // array\u3067\u521D\u671F\u5316\u3059\u308B.\n    void build(vector<Mon>\
    \ &array) {\n        for (int i = size; i < size + n; i++)\n            tree[i]\
    \ = array[i - size];\n        for (int i = size - 1; i > 0; i--)\n           \
    \ tree[i] = op(tree[i << 1], tree[i << 1 | 1]);\n    }\n\n    // update\n    //\
    \ A[k] = A[k] * x \u3068\u66F4\u65B0\u3059\u308B\n    // \u5236\u7D04: 0 <= k\
    \ < n\n    // \u8A08\u7B97\u91CF: O(logn)\n    void update(int k, Mon x) {\n \
    \       k += size;\n        tree[k] = op(tree[k], x);\n        while (k > 1) {\n\
    \            k >>= 1;\n            tree[k] = op(tree[k << 1], tree[k << 1 | 1]);\n\
    \        }\n    }\n\n    // set\n    // A[k] = x \u3068\u66F4\u65B0\u3059\u308B\
    \n    // \u5236\u7D04: 0 <= k < n\n    // \u8A08\u7B97\u91CF: O(logn)\n    void\
    \ set(int k, Mon x) {\n        k += size;\n        tree[k] = x;\n        while\
    \ (k > 1) {\n            k >>= 1;\n            tree[k] = op(tree[k << 1], tree[k\
    \ << 1 | 1]);\n        }\n    }\n\n    // get\n    // A[k]\u3092\u8FD4\u3059.\n\
    \    // \u5236\u7D04: 0 <= k < n\n    // \u8A08\u7B97\u91CF: O(1)\n    Mon get(int\
    \ k) {\n        return tree[k + size];\n    }\n\n    // prod\n    // A[l]*...*A[r-1]\
    \ \u3092\u8A08\u7B97\u3059\u308B. l = r\u306E\u3068\u304D\u306Fe\u3092\u8FD4\u3059\
    .\n    // \u5236\u7D04: 0 <= l <= r <= n\n    // \u8A08\u7B97\u91CF: O(logn)\n\
    \    Mon prod(int l, int r) {\n        l += size;\n        r += size;\n      \
    \  Mon vl = e, vr = e;\n        while (l < r) {\n            if (l & 1) {\n  \
    \              vl = op(vl, tree[l]);\n                l++;\n            }\n  \
    \          if (r & 1) {\n                r--;\n                vr = op(tree[r],\
    \ vr);\n            }\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return op(vl, vr);\n    }\n\n    // max_right\n    // l < r <= n\u3067\
    f(A[l]*...*A[r-1]) = true\u306A\u308B\u6700\u5927\u306Er, \u305D\u306E\u3088\u3046\
    \u306Ar\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306Fl\u3092\u8FD4\u3059\
    .\n    // \u5236\u7D04: 0 <= l <= n,f(e) = true\n    // \u8A08\u7B97\u91CF: O(logn)\n\
    \    int max_right(int l, function<bool(Mon)> f) {\n        if (l == n) return\
    \ n;\n        int r = l + size;\n        Mon x = e;\n        do {\n          \
    \  while (r % 2 == 0)\n                r >>= 1;\n            if (f(op(x, tree[r])))\
    \ {\n                x = op(x, tree[r]);\n                r++;\n            }\
    \ else {\n                while (r < size) {\n                    r <<= 1;\n \
    \                   if (f(op(x, tree[r]))) {\n                        x = op(x,\
    \ tree[r]);\n                        r++;\n                    }\n           \
    \     }\n                return r - size;\n            }\n        } while ((r\
    \ & -r) != r);\n        return n;\n    }\n};\n#line 6 \"test/rmq.test.cpp\"\n\n\
    int main() {\n    int n, q;\n    cin >> n >> q;\n    SegmentTree<long long> st(\n\
    \        n, [](long a, long b) { return min(a, b); }, (1LL << 31) - 1);\n\n  \
    \  int t;\n    long long x, y;\n    for (int i = 0; i < q; i++) {\n        cin\
    \ >> t >> x >> y;\n        if (t == 0) {\n            st.set(x, y);\n        }\
    \ else {\n            cout << st.prod(x, y + 1) << '\\n';\n        }\n    }\n\n\
    \    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp\"\
    \n#include \"../data_structures/segment_tree.cpp\"\n\nint main() {\n    int n,\
    \ q;\n    cin >> n >> q;\n    SegmentTree<long long> st(\n        n, [](long a,\
    \ long b) { return min(a, b); }, (1LL << 31) - 1);\n\n    int t;\n    long long\
    \ x, y;\n    for (int i = 0; i < q; i++) {\n        cin >> t >> x >> y;\n    \
    \    if (t == 0) {\n            st.set(x, y);\n        } else {\n            cout\
    \ << st.prod(x, y + 1) << '\\n';\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - data_structures/segment_tree.cpp
  isVerificationFile: true
  path: test/rmq.test.cpp
  requiredBy: []
  timestamp: '2022-09-04 14:36:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/rmq.test.cpp
layout: document
redirect_from:
- /verify/test/rmq.test.cpp
- /verify/test/rmq.test.cpp.html
title: test/rmq.test.cpp
---
