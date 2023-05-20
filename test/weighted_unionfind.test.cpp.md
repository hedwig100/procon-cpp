---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structures/weighted_unionfind.cpp
    title: data_structures/weighted_unionfind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
  bundledCode: "#line 1 \"test/weighted_unionfind.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\"\
    \n#line 3 \"data_structures/weighted_unionfind.cpp\"\nusing namespace std;\n\n\
    // WeightedUnionFind\n// \u901A\u5E38\u306EUnionFind\u306B\u52A0\u3048\u3066,\
    \ \u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u3044\u308B\u30CE\u30FC\u30C9\u306E\
    \u89AA\u306B\u5BFE\u3059\u308B\u91CD\u307F\u3082\n// \u7BA1\u7406\u3059\u308B\u30C7\
    \u30FC\u30BF\u69CB\u9020.\ntemplate <typename Abel, Abel unit>\nstruct WeightedUnionFind\
    \ {\n    int n;\n    vector<int> parents;\n    vector<Abel> diff_weight;\n\n \
    \   WeightedUnionFind(int n) : n(n) {\n        parents.assign(n, -1);\n      \
    \  diff_weight.assign(n, unit);\n    }\n\n    // find\n    // x\u306E\u89AA\u3092\
    \u8FD4\u3059. \u7D4C\u8DEF\u5727\u7E2E\u3059\u308B\u305F\u3081, diff_weight\u3082\
    \u66F4\u65B0\u3059\u308B\n    // \u5236\u7D04: 0 <= x < n\n    int find(int x)\
    \ {\n        if (parents[x] < 0)\n            return x;\n        else {\n    \
    \        int p = find(parents[x]);\n            diff_weight[x] += diff_weight[parents[x]];\n\
    \            return parents[x] = p;\n        }\n    }\n\n    // weight\n    //\
    \ x\u306Eparent\u304B\u3089\u306E\u91CD\u307F\u3092\u8FD4\u3059\n    // \u5236\
    \u7D04: 0 <= x < n\n    Abel weight(int x) {\n        find(x);\n        return\
    \ diff_weight[x];\n    }\n\n    // diff\n    // x\u3068y\u304C\u540C\u3058\u30B0\
    \u30EB\u30FC\u30D7\u306B\u3044\u308B\u6642, x\u306B\u5BFE\u3059\u308By\u306E\u91CD\
    \u307F\u3092\u8FD4\u3059.\n    // x\u3068y\u304C\u540C\u3058\u30B0\u30EB\u30FC\
    \u30D7\u306B\u3044\u306A\u3044\u6642, \u8FD4\u3059\u5024\u306B\u306F\u610F\u5473\
    \u304C\u306A\u3044.\n    // \u5236\u7D04: 0 <= x,y < n, x\u3068y\u306F\u540C\u3058\
    \u30B0\u30EB\u30FC\u30D7\n    Abel diff(int x, int y) {\n        return weight(y)\
    \ - weight(x);\n    }\n\n    // unite\n    // weight(y) = weight(x) + w\u3068\u306A\
    \u308B\u3088\u3046\u306Bx\u3068y\u3092\u4F75\u5408\u3059\u308B.\n    // \u3082\
    \u3057\u3059\u3067\u306Bx\u3068y\u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u3067\
    weight(y) != weight(x) + w\u3067\u3042\u308C\u3070false\u3092\u8FD4\u3059.\n \
    \   // \u305D\u3046\u3067\u306A\u3044\u5834\u5408\u306Ftrue\u3092\u8FD4\u3059\
    .\n    // \u5236\u7D04: 0 <= x,y < n\n    bool unite(int x, int y, Abel w) {\n\
    \        w += weight(x);\n        w -= weight(y);\n\n        x = find(x);\n  \
    \      y = find(y);\n        if (x == y) {\n            if (diff(x, y) == w)\n\
    \                return true;\n            else\n                return false;\n\
    \        }\n\n        if (parents[x] > parents[y]) {\n            swap(x, y);\n\
    \            w *= -1;\n        }\n\n        parents[x] += parents[y];\n      \
    \  parents[y]     = x;\n        diff_weight[y] = w;\n        return true;\n  \
    \  }\n\n    // same\n    // x\u3068y\u304C\u540C\u3058\u304B\u3069\u3046\u304B\
    \u5224\u5B9A\u3059\u308B\n    // \u5236\u7D04: 0 <= x,y < n\n    bool same(int\
    \ x, int y) {\n        return find(x) == find(y);\n    }\n\n    // size\n    //\
    \ x\u3068\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\
    \u3059.\n    // \u5236\u7D04: 0 <= x < n\n    int size(int x) {\n        return\
    \ -parents[find(x)];\n    }\n};\n#line 6 \"test/weighted_unionfind.test.cpp\"\n\
    \nvoid solve(int n, int m) {\n    WeightedUnionFind<int, 0> wuf(n);\n    int a,\
    \ b, w;\n    for (int i = 0; i < m; i++) {\n        char q;\n        cin >> q;\n\
    \        if (q == '!') {\n            cin >> a >> b >> w;\n            wuf.unite(--a,\
    \ --b, w);\n        } else {\n            cin >> a >> b;\n            if (!wuf.same(--a,\
    \ --b))\n                cout << \"UNKNOWN\\n\";\n            else\n         \
    \       cout << wuf.diff(a, b) << '\\n';\n        }\n    }\n}\n\nint main() {\n\
    \    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed <<\
    \ setprecision(20);\n\n    int n, m;\n    while (1) {\n        cin >> n >> m;\n\
    \        if (n == 0 && m == 0) break;\n        solve(n, m);\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\"\
    \n#include \"../data_structures/weighted_unionfind.cpp\"\n\nvoid solve(int n,\
    \ int m) {\n    WeightedUnionFind<int, 0> wuf(n);\n    int a, b, w;\n    for (int\
    \ i = 0; i < m; i++) {\n        char q;\n        cin >> q;\n        if (q == '!')\
    \ {\n            cin >> a >> b >> w;\n            wuf.unite(--a, --b, w);\n  \
    \      } else {\n            cin >> a >> b;\n            if (!wuf.same(--a, --b))\n\
    \                cout << \"UNKNOWN\\n\";\n            else\n                cout\
    \ << wuf.diff(a, b) << '\\n';\n        }\n    }\n}\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(20);\n\n\
    \    int n, m;\n    while (1) {\n        cin >> n >> m;\n        if (n == 0 &&\
    \ m == 0) break;\n        solve(n, m);\n    }\n\n    return 0;\n}"
  dependsOn:
  - data_structures/weighted_unionfind.cpp
  isVerificationFile: true
  path: test/weighted_unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/weighted_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/weighted_unionfind.test.cpp
- /verify/test/weighted_unionfind.test.cpp.html
title: test/weighted_unionfind.test.cpp
---
