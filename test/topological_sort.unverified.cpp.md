---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/topological_sort.cpp
    title: graph/topological_sort.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=ja
  bundledCode: "#line 1 \"test/topological_sort.unverified.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=ja\"\
    \n#line 3 \"graph/topological_sort.cpp\"\nusing namespace std;\n\n// topological_sort\n\
    // \u6709\u5411\u30B0\u30E9\u30D5G\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u3092\u53D7\
    \u3051\u53D6\u3063\u3066DAG\u3067\u3042\u308C\u3070\u30C8\u30DD\u30ED\u30B8\u30AB\
    \u30EB\u30BD\u30FC\u30C8\u3057\u305F\u7D50\u679C\u3092\u8FD4\u3057,\n// \u305D\
    \u3046\u3067\u306A\u3051\u308C\u3070{-1}\u3092\u8FD4\u3059.\nvector<int> topological_sort(const\
    \ vector<vector<int>> &G) {\n    int n = (int)G.size();\n    vector<int> ans;\n\
    \    stack<int> stk;\n    vector<int> indeg(n, 0);\n    for (int i = 0; i < n;\
    \ i++) {\n        for (const int &v : G[i])\n            indeg[v]++;\n    }\n\
    \    for (int i = 0; i < n; i++) {\n        if (indeg[i] == 0) {\n           \
    \ stk.push(i);\n            indeg[i] = -1;\n        }\n    }\n    while (!stk.empty())\
    \ {\n        int v = stk.top();\n        ans.push_back(v);\n        stk.pop();\n\
    \        for (const int &u : G[v]) {\n            if (--indeg[u] == 0) {\n   \
    \             stk.push(u);\n                indeg[u] = -1;\n            }\n  \
    \      }\n    }\n    if (all_of(indeg.begin(), indeg.end(), [](int x) { return\
    \ x < 0; }))\n        return ans;\n    else\n        return {-1};\n}\n#line 6\
    \ \"test/topological_sort.unverified.cpp\"\n\nint main() {\n    int n, m;\n  \
    \  cin >> n >> m;\n    vector<vector<int>> G(n);\n    for (int i = 0; i < m; i++)\
    \ {\n        int u, v;\n        cin >> u >> v;\n        G[u].push_back(v);\n \
    \   }\n\n    auto ret = topological_sort(G);\n    for (auto &a : ret)\n      \
    \  cout << a << '\\n';\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=ja\"\
    \n#include \"../graph/topological_sort.cpp\"\n\nint main() {\n    int n, m;\n\
    \    cin >> n >> m;\n    vector<vector<int>> G(n);\n    for (int i = 0; i < m;\
    \ i++) {\n        int u, v;\n        cin >> u >> v;\n        G[u].push_back(v);\n\
    \    }\n\n    auto ret = topological_sort(G);\n    for (auto &a : ret)\n     \
    \   cout << a << '\\n';\n    return 0;\n}"
  dependsOn:
  - graph/topological_sort.cpp
  isVerificationFile: false
  path: test/topological_sort.unverified.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/topological_sort.unverified.cpp
layout: document
redirect_from:
- /library/test/topological_sort.unverified.cpp
- /library/test/topological_sort.unverified.cpp.html
title: test/topological_sort.unverified.cpp
---
