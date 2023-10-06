---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other_algorithm/two_pointers.cpp
    title: other_algorithm/two_pointers.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C&lang=jp
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C&lang=jp
  bundledCode: "#line 1 \"test/two_pointers.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C&lang=jp\"\
    \n#line 3 \"other_algorithm/two_pointers.cpp\"\nusing namespace std;\n\n// TwoPointers\n\
    // \u6761\u4EF6P\u3092\u6E80\u305F\u3059\u9023\u7D9A\u90E8\u5206\u5217[l,r)\u306E\
    \u6570\u3048\u4E0A\u3052, \u3082\u3057\u304F\u306F\u6700\u5927\u306E\u9577\u3055\
    \u3092\u8A08\u7B97\u3059\u308B.\n// \u305F\u3060\u3057\u6761\u4EF6P\u306F\u4EE5\
    \u4E0B\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3088\u3046\u306A\u3082\u306E\
    \u3067\u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044.\n// \u6761\u4EF6\n// -\
    \ \u9023\u7D9A\u90E8\u5206\u5217[l,r)\u304C\u6761\u4EF6P\u3092\u6E80\u305F\u3059\
    \u3068\u304D, [l,r)\u5185\u306E\u4EFB\u610F\u306E\u9023\u7D9A\u90E8\u5206\u5217\
    \u304C\u6761\u4EF6P\u3092\u6E80\u305F\u3059.\n//\ntemplate <typename Data, const\
    \ Data initial_state>\nstruct TwoPointers {\n    using Fcond = function<bool(Data\
    \ data, int r)>;\n    using Fincl = function<void(Data &data, int &l)>;\n    using\
    \ Fincr = function<void(Data &data, int &r)>;\n\n    int n;\n    long long count\
    \ = 0;\n    int max_length  = 0;\n\n  private:\n    Data data = initial_state;\n\
    \n    // cond\n    // data\u306F\u9023\u7D9A\u90E8\u5206\u5217[l,r-1)\u306B\u95A2\
    \u3059\u308B\u60C5\u5831\u3092\u6301\u3063\u3066\u304A\u308A, [l,r)\u304C\u6761\
    \u4EF6P\u3092\u6E80\u305F\u3059\u5834\u5408\u306Ftrue,\u305D\u3046\u3067\u306A\
    \u3044\u6642\u306Ffalse\u3092\u8FD4\u3059.\n    // \u5236\u7D04: 0 <= l < r <=\
    \ n\n    Fcond cond;\n\n    // increase_l\n    // l\u3092l+1\u306B\u3059\u308B\
    . \u540C\u6642\u306B\u30C7\u30FC\u30BF\u306E\u5909\u66F4\u3092\u884C\u3046.\n\
    \    // \u5236\u7D04: 0 <= l < n\n    Fincl increase_l;\n\n    // increase_r\n\
    \    // r\u3092r+1\u306B\u3059\u308B. \u540C\u6642\u306B\u30C7\u30FC\u30BF\u306E\
    \u5909\u66F4\u3092\u884C\u3046.\n    // \u5236\u7D04: 0 <= r < n\n    Fincr increase_r;\n\
    \n    void init() {\n        count      = 0;\n        max_length = 0;\n      \
    \  data       = initial_state;\n    }\n\n  public:\n    TwoPointers(int n, Fcond\
    \ cond, Fincl increase_l, Fincr increase_r)\n        : n(n), cond(cond), increase_l(increase_l),\
    \ increase_r(increase_r) {}\n\n    // solve\n    // \u5C3A\u53D6\u6CD5\u3092\u7528\
    \u3044\u3066\u6761\u4EF6P\u3092\u6E80\u305F\u3059\u9023\u7D9A\u90E8\u5206\u5217\
    \u306E\u6700\u5927\u306E\u9577\u3055\u3068\u6570\u3092\u6570\u3048\u308B.\n  \
    \  // \u8A08\u7B97\u91CF: O(n)\n    void solve() {\n        init();\n        int\
    \ r = 0;\n        for (int l = 0; l < n; increase_l(data, l)) {\n            while\
    \ (r < n && cond(data, r + 1)) {\n                increase_r(data, r);\n     \
    \       }\n            count += r - l;\n            max_length = max(max_length,\
    \ r - l);\n            if (r == l)\n                increase_r(data, r);\n   \
    \     }\n    }\n};\n\n// \u672AVerify\n// TwoPointers2\n// \u6761\u4EF6Q\u3092\
    \u6E80\u305F\u3059\u9023\u7D9A\u90E8\u5206\u5217[l,r)\u306E\u6570\u3048\u4E0A\u3052\
    , \u3082\u3057\u304F\u306F\u6700\u5C0F\u306E\u9577\u3055\u3092\u8A08\u7B97\u3059\
    \u308B.\n// \u305F\u3060\u3057\u6761\u4EF6Q\u306F\u4EE5\u4E0B\u306E\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u3088\u3046\u306A\u3082\u306E\u3067\u306A\u3051\u308C\
    \u3070\u306A\u3089\u306A\u3044.\n// \u6761\u4EF6\n// - \u9023\u7D9A\u90E8\u5206\
    \u5217[l,r)\u304C\u6761\u4EF6Q\u3092\u6E80\u305F\u3059\u3068\u304D, [l,r)\u3092\
    \u542B\u3080\u4EFB\u610F\u306E\u9023\u7D9A\u90E8\u5206\u5217\u304C\u6761\u4EF6\
    Q\u3092\u6E80\u305F\u3059.\n//\ntemplate <typename Data, const Data initial_state>\n\
    struct TwoPointers2 {\n    using Fcond = function<bool(Data data)>;\n    using\
    \ Fincl = function<void(Data &data, int &l)>;\n    using Fincr = function<void(Data\
    \ &data, int &r)>;\n\n    int n;\n    long long count;\n    int min_length;\n\n\
    \  private:\n    Data data = initial_state;\n\n    // cond\n    // data\u306F\u9023\
    \u7D9A\u90E8\u5206\u5217[l,r)\u306B\u95A2\u3059\u308B\u60C5\u5831\u3092\u6301\u3063\
    \u3066\u304A\u308A, [l,r)\u304C\u6761\u4EF6Q\u3092\u6E80\u305F\u3059\u5834\u5408\
    \u306Ftrue,\u305D\u3046\u3067\u306A\u3044\u6642\u306Ffalse\u3092\u8FD4\u3059.\n\
    \    // \u5236\u7D04: 0 <= l < r <= n\n    Fcond cond;\n\n    // increase_l\n\
    \    // l\u3092l+1\u306B\u3059\u308B. \u540C\u6642\u306B\u30C7\u30FC\u30BF\u306E\
    \u5909\u66F4\u3092\u884C\u3046.\n    // \u5236\u7D04: 0 <= l < n\n    Fincl increase_l;\n\
    \n    // increase_r\n    // r\u3092r+1\u306B\u3059\u308B. \u540C\u6642\u306B\u30C7\
    \u30FC\u30BF\u306E\u5909\u66F4\u3092\u884C\u3046.\n    // \u5236\u7D04: 0 <= r\
    \ < n\n    Fincr increase_r;\n\n    void init() {\n        count      = 0;\n \
    \       min_length = n + 1;\n        data       = initial_state;\n    }\n\n  public:\n\
    \    TwoPointers2(int n, Fcond cond, Fincl increase_l, Fincr increase_r)\n   \
    \     : n(n), cond(cond), increase_l(increase_l), increase_r(increase_r) {}\n\n\
    \    // solve\n    // \u5C3A\u53D6\u6CD5\u3092\u7528\u3044\u3066\u6761\u4EF6Q\u3092\
    \u6E80\u305F\u3059\u9023\u7D9A\u90E8\u5206\u5217\u306E\u6700\u5C0F\u306E\u9577\
    \u3055\u3068\u6570\u3092\u6570\u3048\u308B.\n    // \u8A08\u7B97\u91CF: O(n)\n\
    \    void solve() {\n        init();\n        int r = 0;\n        for (int l =\
    \ 0; l < n; increse_l(data, l)) {\n            while (r <= n && !cond(data)) {\n\
    \                if (r == n) {\n                    r++;\n                   \
    \ break;\n                }\n                increase_r(data, r);\n          \
    \  }\n            if (r == n + 1) break;\n            count += n - r + 1;\n  \
    \          min_length = min(min_length, r - l);\n            if (r == l)\n   \
    \             increase_r(data, r);\n        }\n    }\n};\n\n// \u4F7F\u7528\u4F8B\
    \n// https://atcoder.jp/contests/abc032/submissions/34471465\n// https://atcoder.jp/contests/abc038/submissions/34471634\n\
    //\n// using Data = long long;\n// TwoPointers<Data, 0> tp(\n//     n,\n//   \
    \  [&](Data data, int r) { return data + A[r - 1] <= x; },\n//     [&](Data &data,\
    \ int &l) { data -= A[l]; l++; },\n//     [&](Data &data, int &r) { data += A[r];\
    \ r++; });\n#line 6 \"test/two_pointers.test.cpp\"\n\nint main() {\n    int n,\
    \ q;\n    cin >> n >> q;\n    vector<long long> A(n);\n    for (int i = 0; i <\
    \ n; i++)\n        cin >> A[i];\n\n    long long x = 0;\n    TwoPointers<long\
    \ long, 0> tp(\n        n,\n        [&](long long data, int r) { return data +\
    \ A[r - 1] <= x; },\n        [&](long long &data, int &l) { data -= A[l]; l++;\
    \ },\n        [&](long long &data, int &r) { data += A[r]; r++; });\n    for (int\
    \ i = 0; i < q; i++) {\n        cin >> x;\n        tp.solve();\n        cout <<\
    \ tp.count << '\\n';\n    }\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C&lang=jp\"\
    \n#include \"../other_algorithm/two_pointers.cpp\"\n\nint main() {\n    int n,\
    \ q;\n    cin >> n >> q;\n    vector<long long> A(n);\n    for (int i = 0; i <\
    \ n; i++)\n        cin >> A[i];\n\n    long long x = 0;\n    TwoPointers<long\
    \ long, 0> tp(\n        n,\n        [&](long long data, int r) { return data +\
    \ A[r - 1] <= x; },\n        [&](long long &data, int &l) { data -= A[l]; l++;\
    \ },\n        [&](long long &data, int &r) { data += A[r]; r++; });\n    for (int\
    \ i = 0; i < q; i++) {\n        cin >> x;\n        tp.solve();\n        cout <<\
    \ tp.count << '\\n';\n    }\n\n    return 0;\n}"
  dependsOn:
  - other_algorithm/two_pointers.cpp
  isVerificationFile: true
  path: test/two_pointers.test.cpp
  requiredBy: []
  timestamp: '2022-08-31 15:48:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/two_pointers.test.cpp
layout: document
redirect_from:
- /verify/test/two_pointers.test.cpp
- /verify/test/two_pointers.test.cpp.html
title: test/two_pointers.test.cpp
---
