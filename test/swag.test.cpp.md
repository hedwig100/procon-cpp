---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structures/sliding_window_aggregation.cpp
    title: data_structures/sliding_window_aggregation.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/489
    links:
    - https://yukicoder.me/problems/no/489
  bundledCode: "#line 1 \"test/swag.test.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define PROBLEM \"https://yukicoder.me/problems/no/489\"\n#line 3 \"\
    data_structures/sliding_window_aggregation.cpp\"\nusing namespace std;\n\n// SlidingWindowAggregation\n\
    // \u534A\u7FA4\u306B\u5BFE\u3057\u3066\u4EE5\u4E0B\u306E\u3053\u3068\u304C\u884C\
    \u3048\u308B\u30C7\u30FC\u30BF\u69CB\u9020\n//\n// push(x): x\u3092\u8FFD\u52A0\
    \u3059\u308B\n// pop(): queue\u306E\u8981\u9818\u3067\u8981\u7D20\u3092\u53D6\u308A\
    \u9664\u304F(FIFO)\n// fold(): \u4ECA\u5165\u3063\u3066\u3044\u308B\u8981\u7D20\
    \u3092\u65E9\u304F\u5165\u3063\u3066\u3044\u305F\u65B9\u304B\u3089a0,a1,...,an\u3068\
    \u3057\u305F\u3068\u304D\u306Ba0*a1*...an\u3092\u8A08\u7B97\u3059\u308B.\ntemplate\
    \ <typename SemiGrp>\nstruct SlidingWindowAggregation {\n    using Fx = function<SemiGrp(const\
    \ SemiGrp &, const SemiGrp &)>;\n\n    vector<SemiGrp> left, left_cum, right,\
    \ right_cum;\n    Fx op;\n\n    SlidingWindowAggregation(Fx op) : op(op) {}\n\n\
    \    inline int size() { return (int)left.size() + (int)right.size(); }\n    inline\
    \ bool empty() { return size() == 0; }\n\n    // push\n    // x\u3092\u8FFD\u52A0\
    \u3059\u308B\n    // \u8A08\u7B97\u91CF: O(1)\n    void push(SemiGrp x) {\n  \
    \      if ((int)right.size() == 0)\n            right.push_back(x), right_cum.push_back(x);\n\
    \        else\n            right.push_back(x), right_cum.push_back(op(right_cum.back(),\
    \ x));\n    }\n\n    // pop\n    // \u30C7\u30FC\u30BF\u3092FIFO\u3067\u53D6\u308A\
    \u51FA\u3059. \u7A7A\u306E\u5834\u5408\u306F\u4F55\u3082\u3057\u306A\u3044.\n\
    \    // \u8A08\u7B97\u91CF: \u511F\u5374 O(1)\n    void pop() {\n        if (empty())\
    \ return;\n        if ((int)left.size() != 0) {\n            left.pop_back(),\
    \ left_cum.pop_back();\n            return;\n        }\n\n        int sz = (int)right.size();\n\
    \        if (sz == 1) {\n            right.pop_back(), right_cum.pop_back();\n\
    \            return;\n        }\n        left.push_back(right.back()), left_cum.push_back(right.back());\n\
    \        right.pop_back(), right_cum.pop_back();\n        for (int i = 1; i <\
    \ sz - 1; i++) {\n            left.push_back(right.back()), left_cum.push_back(op(right.back(),\
    \ left_cum.back()));\n            right.pop_back(), right_cum.pop_back();\n  \
    \      }\n        right.pop_back(), right_cum.pop_back();\n    }\n\n    // fold\n\
    \    // \u4ECA\u5165\u3063\u3066\u3044\u308B\u8981\u7D20\u3092\u65E9\u304F\u5165\
    \u3063\u3066\u3044\u305F\u65B9\u304B\u3089a0,a1,...,an\u3068\u3057\u305F\u3068\
    \u304D\u306Ba0*a1*...an\u3092\u8FD4\u3059.\n    // \u5236\u7D04: \u7A7A\u3067\u306F\
    \u306A\u3044\n    // \u8A08\u7B97\u91CF: O(1)\n    SemiGrp fold() {\n        assert(!empty());\n\
    \        if ((int)left.size() == 0)\n            return right_cum.back();\n  \
    \      else if ((int)right.size() == 0)\n            return left_cum.back();\n\
    \        else\n            return op(left_cum.back(), right_cum.back());\n   \
    \ }\n\n    friend ostream &operator<<(ostream &os, const SlidingWindowAggregation<SemiGrp>\
    \ &swag) {\n        for (int i = (int)swag.left.size() - 1; i >= 0; i--)\n   \
    \         os << swag.left[i] << ' ';\n        for (int i = 0; i < (int)swag.right.size();\
    \ i++)\n            os << swag.right[i] << ' ';\n        return os;\n    }\n};\n\
    \n// example:\n// using SemiGrp = pair<int, int>;\n// SlidingWindowAggregation<SemiGrp>\
    \ swag([](const SemiGrp &a, const SemiGrp &b) {\n//     if (a.first < b.first)\n\
    //         return b;\n//     else\n//         return a;\n// });\n#line 6 \"test/swag.test.cpp\"\
    \n\nint main() {\n    int n, d, k;\n    cin >> n >> d >> k;\n    vector<int> X(n);\n\
    \    for (int i = 0; i < n; i++)\n        cin >> X[i];\n\n    using SemiGrp =\
    \ pair<int, int>;\n    SlidingWindowAggregation<SemiGrp> swag([](const SemiGrp\
    \ &a, const SemiGrp &b) {\n        if (a.first < b.first)\n            return\
    \ b;\n        else\n            return a;\n    });\n\n    int max_diff = 0;\n\
    \    int ai = -1, bi = -1;\n    for (int i = 0; i <= d; i++)\n        swag.push({X[i],\
    \ i});\n    for (int i = 0; i < n; i++) {\n        auto [x, j] = swag.fold();\n\
    \        if (max_diff < x - X[i]) {\n            max_diff = x - X[i];\n      \
    \      ai = i, bi = j;\n        }\n        swag.pop();\n        if (i + d + 1\
    \ < n) swag.push({X[i + d + 1], i + d + 1});\n    }\n\n    if (max_diff == 0)\n\
    \        cout << 0 << '\\n';\n    else {\n        cout << (long long)k * max_diff\
    \ << '\\n';\n        cout << ai << ' ' << bi << '\\n';\n    }\n\n    return 0;\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://yukicoder.me/problems/no/489\"\
    \n#include \"../data_structures/sliding_window_aggregation.cpp\"\n\nint main()\
    \ {\n    int n, d, k;\n    cin >> n >> d >> k;\n    vector<int> X(n);\n    for\
    \ (int i = 0; i < n; i++)\n        cin >> X[i];\n\n    using SemiGrp = pair<int,\
    \ int>;\n    SlidingWindowAggregation<SemiGrp> swag([](const SemiGrp &a, const\
    \ SemiGrp &b) {\n        if (a.first < b.first)\n            return b;\n     \
    \   else\n            return a;\n    });\n\n    int max_diff = 0;\n    int ai\
    \ = -1, bi = -1;\n    for (int i = 0; i <= d; i++)\n        swag.push({X[i], i});\n\
    \    for (int i = 0; i < n; i++) {\n        auto [x, j] = swag.fold();\n     \
    \   if (max_diff < x - X[i]) {\n            max_diff = x - X[i];\n           \
    \ ai = i, bi = j;\n        }\n        swag.pop();\n        if (i + d + 1 < n)\
    \ swag.push({X[i + d + 1], i + d + 1});\n    }\n\n    if (max_diff == 0)\n   \
    \     cout << 0 << '\\n';\n    else {\n        cout << (long long)k * max_diff\
    \ << '\\n';\n        cout << ai << ' ' << bi << '\\n';\n    }\n\n    return 0;\n\
    }"
  dependsOn:
  - data_structures/sliding_window_aggregation.cpp
  isVerificationFile: true
  path: test/swag.test.cpp
  requiredBy: []
  timestamp: '2022-09-23 10:29:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/swag.test.cpp
layout: document
redirect_from:
- /verify/test/swag.test.cpp
- /verify/test/swag.test.cpp.html
title: test/swag.test.cpp
---
