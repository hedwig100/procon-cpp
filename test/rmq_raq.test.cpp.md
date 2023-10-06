---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structures/lazy_segment_tree.cpp
    title: data_structures/lazy_segment_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
  bundledCode: "#line 1 \"test/rmq_raq.test.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\
    \n#line 3 \"data_structures/lazy_segment_tree.cpp\"\nusing namespace std;\n\n\
    // LazySegmentTree\n// *: Mon \xD7 Mon -> Mon\u306F\u30E2\u30CE\u30A4\u30C9\u3067\
    \u3042\u308A, e\u3092Mon\u306E\u5358\u4F4D\u5143\n// \xD7: OpMon \xD7 OpMon ->\
    \ OpMon\u306F\u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308A, id\u3092OpMon\u306E\u5358\
    \u4F4D\u5143 \u3068\u3059\u308B.\n// ^: Mon \xD7 OpMon -> Mon \u306A\u308BMon\u3078\
    \u306E\u53F3\u4F5C\u7528\u306F\u6B21\u306E\u6027\u8CEA\u3092\u6E80\u305F\u3059\
    \u3068\u3059\u308B.\n//\n// 1. x^id = x\n// 2. (x * y)^a = x^a * y^a\n// 3. (x^a)^b\
    \ = x^(a \xD7 b)\n//\n// \u3053\u306E\u3068\u304D, \u4EE5\u4E0B\u306E\u64CD\u4F5C\
    \u304C\u53EF\u80FD\n// 1. A[l]*...*A[r-1]\u3092\u6C42\u3081\u308B\n// 2. A[i]\
    \ = A[i]^a (l <= i < r)\u3068\u66F4\u65B0\u3059\u308B\ntemplate <typename Mon,\
    \ typename OpMon>\nstruct LazySegmentTree {\n    using Fx  = function<Mon(Mon,\
    \ Mon)>;\n    using Fop = function<Mon(Mon, OpMon)>;\n    using Fy  = function<OpMon(OpMon,\
    \ OpMon)>;\n\n    int n, size, log;\n    vector<Mon> data;\n    vector<OpMon>\
    \ lazy; // lazy[i] = i\u81EA\u8EAB\u3068i\u306E\u5B50\u5B6B\u306B\u3053\u308C\u304B\
    \u3089\u4F1D\u64AD\u3057\u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\u5024\
    \n\n    Fx op;\n    Mon e;\n    Fy composition;\n    OpMon id;\n    Fop mapping;\n\
    \n    LazySegmentTree(int n, Fx op, Mon e, Fy composition, OpMon id, Fop mapping)\n\
    \        : n(n), op(op), e(e), composition(composition), id(id), mapping(mapping)\
    \ {\n        size = 1, log = 0;\n        while (size < n)\n            size <<=\
    \ 1, log++;\n        data.assign(2 * size, e);\n        lazy.assign(2 * size,\
    \ id);\n    }\n\n    // build\n    // \u9577\u3055n\u306E\u914D\u5217A\u3067\u521D\
    \u671F\u5316\u3059\u308B.\n    // \u8A08\u7B97\u91CF: O(n)\n    void build(vector<Mon>\
    \ &A) {\n        for (int i = size; i < size + n; i++)\n            data[i] =\
    \ A[i - size];\n        for (int i = size - 1; i >= 1; i--)\n            data[i]\
    \ = op(data[i << 1], data[i << 1 | 1]);\n    }\n\n    // apply\n    // A[i] =\
    \ A[i] * x (l <= i < r)\u3068\u3059\u308B.\n    // \u5236\u7D04: 0 <= l <= r <=\
    \ n\n    // \u8A08\u7B97\u91CF: O(logn)\n    void apply(int l, int r, OpMon x)\
    \ {\n        l += size;\n        r += size;\n        int tmp_l = l, tmp_r = r;\n\
    \        propagate_above(l);\n        propagate_above(r - 1);\n        while (l\
    \ < r) {\n            if (l & 1) {\n                lazy[l] = composition(lazy[l],\
    \ x);\n                l++;\n            }\n            if (r & 1) {\n       \
    \         r--;\n                lazy[r] = composition(lazy[r], x);\n         \
    \   }\n            l >>= 1;\n            r >>= 1;\n        }\n        recalc_above(tmp_l);\n\
    \        recalc_above(tmp_r - 1);\n    }\n\n    // prod\n    // A[l]*...*A[r-1]\u3092\
    \u8FD4\u3059. l = r\u306A\u3089e\u3092\u8FD4\u3059.\n    // \u5236\u7D04: 0 <=\
    \ l <= r <= n\n    // \u8A08\u7B97\u91CF; O(logn)\n    Mon prod(int l, int r)\
    \ {\n        l += size;\n        r += size;\n        propagate_above(l);\n   \
    \     propagate_above(r - 1);\n        Mon vl = e, vr = e;\n        while (l <\
    \ r) {\n            if (l & 1) {\n                vl = op(vl, propagate(l));\n\
    \                l++;\n            }\n            if (r & 1) {\n             \
    \   r--;\n                vr = op(propagate(r), vr);\n            }\n        \
    \    l >>= 1;\n            r >>= 1;\n        }\n        return op(vl, vr);\n \
    \   }\n\n  private:\n    // propagate\n    // lazy[i]\u3092data[i]\u306B\u53CD\
    \u6620\u3055\u305B, i\u306E\u5B50\u304C\u3042\u308C\u3070\u305D\u306Elazy\u306E\
    \u66F4\u65B0\u3092\u3059\u308B.\n    // \u66F4\u65B0\u3057\u305Fdata[i]\u3092\u8FD4\
    \u3059.\n    Mon propagate(int i) {\n        data[i] = mapping(data[i], lazy[i]);\n\
    \        if (i < size) {\n            lazy[i << 1]     = composition(lazy[i <<\
    \ 1], lazy[i]);\n            lazy[i << 1 | 1] = composition(lazy[i << 1 | 1],\
    \ lazy[i]);\n        }\n        lazy[i] = id;\n        return data[i];\n    }\n\
    \    // propagate_above\n    // i\u3092\u542B\u3080i\u3088\u308A\u4E0A\u306E\u533A\
    \u9593\u306Edata\u3092\u4EE5\u524D\u306E\u30C7\u30FC\u30BF\u3092\u4F1D\u64AD\u3059\
    \u308B\u3053\u3068\u3067\u6B63\u3057\u3044\u72B6\u614B\u306B\u3059\u308B.\n  \
    \  void propagate_above(int i) {\n        for (int k = log; k >= 0; k--)\n   \
    \         if ((i >> k) >= 1) propagate(i >> k);\n    }\n    // recalc_above\n\
    \    // i\u3092\u542B\u307E\u306A\u3044i\u3088\u308A\u4E0A\u306E\u533A\u9593\u306E\
    data\u3092\u3044\u307E\u66F4\u65B0\u3055\u308C\u305Fdata\u3092\u7528\u3044\u3066\
    \u6B63\u3057\u3044\u72B6\u614B\u306B\u4FDD\u3064.\n    void recalc_above(int i)\
    \ {\n        while (i > 1) {\n            i >>= 1;\n            data[i] = op(propagate(i\
    \ << 1), propagate(i << 1 | 1));\n        }\n    }\n};\n#line 6 \"test/rmq_raq.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n\n    using Mon   = int;\n\
    \    using OpMon = int;\n\n    auto op          = [](const Mon &x, const Mon &y)\
    \ { return min(x, y); };\n    auto composition = [](const OpMon &a, const OpMon\
    \ &b) { return a + b; };\n    auto mapping     = [](const Mon &x, const OpMon\
    \ &a) { return x + a; };\n    LazySegmentTree<Mon, OpMon> lst(n, op, INT_MAX,\
    \ composition, 0, mapping);\n    vector<Mon> A(n, 0);\n    lst.build(A);\n\n \
    \   int typ, s, t, x;\n    for (int i = 0; i < q; i++) {\n        cin >> typ;\n\
    \        if (typ == 0) {\n            cin >> s >> t >> x;\n            lst.apply(s,\
    \ t + 1, x);\n        } else {\n            cin >> s >> t;\n            cout <<\
    \ lst.prod(s, t + 1) << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\
    \n#include \"../data_structures/lazy_segment_tree.cpp\"\n\nint main() {\n    int\
    \ n, q;\n    cin >> n >> q;\n\n    using Mon   = int;\n    using OpMon = int;\n\
    \n    auto op          = [](const Mon &x, const Mon &y) { return min(x, y); };\n\
    \    auto composition = [](const OpMon &a, const OpMon &b) { return a + b; };\n\
    \    auto mapping     = [](const Mon &x, const OpMon &a) { return x + a; };\n\
    \    LazySegmentTree<Mon, OpMon> lst(n, op, INT_MAX, composition, 0, mapping);\n\
    \    vector<Mon> A(n, 0);\n    lst.build(A);\n\n    int typ, s, t, x;\n    for\
    \ (int i = 0; i < q; i++) {\n        cin >> typ;\n        if (typ == 0) {\n  \
    \          cin >> s >> t >> x;\n            lst.apply(s, t + 1, x);\n        }\
    \ else {\n            cin >> s >> t;\n            cout << lst.prod(s, t + 1) <<\
    \ \"\\n\";\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - data_structures/lazy_segment_tree.cpp
  isVerificationFile: true
  path: test/rmq_raq.test.cpp
  requiredBy: []
  timestamp: '2022-09-04 19:05:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/rmq_raq.test.cpp
layout: document
redirect_from:
- /verify/test/rmq_raq.test.cpp
- /verify/test/rmq_raq.test.cpp.html
title: test/rmq_raq.test.cpp
---
