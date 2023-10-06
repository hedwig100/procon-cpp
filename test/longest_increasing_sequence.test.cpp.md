---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic_programming/longest_increasing_sequence.cpp
    title: dynamic_programming/longest_increasing_sequence.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp
  bundledCode: "#line 1 \"test/longest_increasing_sequence.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp\"\
    \n#line 3 \"dynamic_programming/longest_increasing_sequence.cpp\"\nusing namespace\
    \ std;\n\n// LongestIncreasingSequece\n// A\u306E\u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217\u3092\u6C42\u3081\u308B. \u3059\u306A\u308F\u3061\n// 0 <= i1 < i2\
    \ < ... < ik < n, A[i1] < A[i2] < ... < A[ik]\u306A\u308Bk\u306E\u6700\u5927\u5024\
    \u3092\u6C42\u3081\u308B\u3002\ntemplate <typename T, T INF>\nstruct LongestIncreasingSequence\
    \ {\n\n    // dp[i] = \u9577\u3055i+1\u3067\u3042\u308B\u3088\u3046\u306A\u5897\
    \u52A0\u90E8\u5206\u5217\u3067\u306E\u6700\u5F8C\u306E\u8981\u7D20\u306E\u6700\
    \u5C0F\u5024, \u306A\u3044\u5834\u5408\u306FINF\n    // dp_ind[i] = \u9577\u3055\
    i+1\u3067\u3042\u308B\u3088\u3046\u306A\u5897\u52A0\u90E8\u5206\u5217\u3067\u306E\
    \u6700\u5F8C\u306E\u8981\u7D20\u306E\u6700\u5C0F\u5024\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9, \u306A\u3044\u5834\u5408\u306F-1\n    // prev[i] = A[i]\u3092\
    \u542B\u3080\u4E2D\u3067\u6700\u9577\u306E\u5897\u52A0\u90E8\u5206\u5217\u3067\
    \u306EA[i]\u306E\u524D\u306E\u8981\u7D20\u304CA[j]\u3067\u3042\u308B\u3068\u304D\
    j, \u5148\u982D\u306E\u3068\u304D\u306F-1\n    int n;\n    vector<T> A, dp;\n\
    \    vector<int> prev, dp_ind;\n\n    LongestIncreasingSequence(int n, vector<T>\
    \ &A) : n(n), A(A) {\n        dp.assign(n + 1, INF);\n        dp_ind.assign(n\
    \ + 1, -1);\n        prev.assign(n, -1);\n    }\n\n    // solve\n    // A\u306E\
    \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u3092\u6C42\u3081\u308B.\n    // \u8A08\
    \u7B97\u91CF: O(nlogn)\n    int solve() {\n        for (int i = 0; i < n; i++)\
    \ {\n            int j     = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();\n\
    \            dp[j]     = A[i];\n            dp_ind[j] = i;\n            prev[i]\
    \   = (j > 0 ? dp_ind[j - 1] : -1);\n        }\n        return lower_bound(dp.begin(),\
    \ dp.end(), INF) - dp.begin();\n    }\n\n    // restore_lis\n    // \u6700\u9577\
    \u5897\u52A0\u90E8\u5206\u5217\u3092\u5FA9\u5143\u3059\u308B\n    // \u8A08\u7B97\
    \u91CF: O(l),l\u306F\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\u3055\
    \n    vector<T> restore_lis() {\n        vector<T> ans;\n        int max_len =\
    \ lower_bound(dp.begin(), dp.end(), INF) - dp.begin();\n        for (int now_ind\
    \ = dp_ind[max_len - 1]; now_ind >= 0; now_ind = prev[now_ind])\n            ans.push_back(A[now_ind]);\n\
    \        reverse(ans.begin(), ans.end());\n        return ans;\n    }\n};\n#line\
    \ 2 \"template/const.hpp\"\nconstexpr int INF        = 1000'000'000;\nconstexpr\
    \ long long HINF = 4000'000'000'000'000'000;\nconstexpr long long MOD  = 998244353;\n\
    constexpr double EPS     = 1e-6;\nconstexpr double PI      = 3.14159265358979;\n\
    #line 7 \"test/longest_increasing_sequence.test.cpp\"\n\nint main() {\n    int\
    \ n;\n    cin >> n;\n    vector<long long> A(n);\n    for (int i = 0; i < n; i++)\n\
    \        cin >> A[i];\n    LongestIncreasingSequence<long long, HINF> lis(n, A);\n\
    \    cout << lis.solve() << '\\n';\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp\"\
    \n#include \"../dynamic_programming/longest_increasing_sequence.cpp\"\n#include\
    \ \"../template/const.hpp\"\n\nint main() {\n    int n;\n    cin >> n;\n    vector<long\
    \ long> A(n);\n    for (int i = 0; i < n; i++)\n        cin >> A[i];\n    LongestIncreasingSequence<long\
    \ long, HINF> lis(n, A);\n    cout << lis.solve() << '\\n';\n\n    return 0;\n\
    }"
  dependsOn:
  - dynamic_programming/longest_increasing_sequence.cpp
  isVerificationFile: true
  path: test/longest_increasing_sequence.test.cpp
  requiredBy: []
  timestamp: '2022-10-23 13:46:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/longest_increasing_sequence.test.cpp
layout: document
redirect_from:
- /verify/test/longest_increasing_sequence.test.cpp
- /verify/test/longest_increasing_sequence.test.cpp.html
title: test/longest_increasing_sequence.test.cpp
---
