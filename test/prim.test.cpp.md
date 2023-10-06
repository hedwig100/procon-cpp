---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/prim.cpp
    title: graph/prim.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"test/prim.test.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n#line 3 \"graph/prim.cpp\"\nusing namespace std;\n\n// Prim\n// Prim\u6CD5\u3067\
    \u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B.\ntemplate <typename T,\
    \ const T INF>\nstruct Prim {\n    struct edge {\n        int to;\n        T cost;\n\
    \        int id;\n\n        edge(int to, T c, int id) : to(to), cost(c), id(id)\
    \ {}\n    };\n    function<bool(const edge &, const edge &)> compare = [](const\
    \ edge &a, const edge &b) {\n        return a.cost > b.cost;\n    };\n\n    int\
    \ n;\n    int m = 0;\n    vector<int> used_id;\n    vector<vector<edge>> G;\n\n\
    \    Prim(int n) : n(n) {\n        G.resize(n);\n    }\n\n    // add_edge\n  \
    \  // a\u3068b\u306E\u9593\u306B\u30B3\u30B9\u30C8c\u306E\u7121\u5411\u8FBA\u3092\
    \u306F\u308B\n    void add_edge(int a, int b, T c) {\n        G[a].emplace_back(b,\
    \ c, m);\n        G[b].emplace_back(a, c, m++);\n    }\n\n    // solve\n    //\
    \ \u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B.\n    // \u8A08\u7B97\
    \u91CF: O(|E|log|V|)\n    T solve() {\n        used_id.assign(m, 0);\n       \
    \ T ans = T(0);\n        vector<int> visited(n, 0);\n        priority_queue<edge,\
    \ vector<edge>, decltype(compare)> q{compare};\n        q.emplace(0, 0, -1);\n\
    \n        while (!q.empty()) {\n            edge e = q.top();\n            q.pop();\n\
    \            if (visited[e.to]) continue;\n            if (e.id >= 0) used_id[e.id]\
    \ = 1;\n            ans += e.cost;\n            visited[e.to] = 1;\n         \
    \   for (const edge &e2 : G[e.to]) {\n                if (visited[e2.to]) continue;\n\
    \                q.push(e2);\n            }\n        }\n        return ans;\n\
    \    }\n};\n#line 2 \"template/const.hpp\"\nconstexpr int INF        = 1000'000'000;\n\
    constexpr long long HINF = 4000'000'000'000'000'000;\nconstexpr long long MOD\
    \  = 998244353;\nconstexpr double EPS     = 1e-6;\nconstexpr double PI      =\
    \ 3.14159265358979;\n#line 7 \"test/prim.test.cpp\"\n\nint main() {\n    int n,\
    \ m;\n    cin >> n >> m;\n    Prim<int, INF> prim(n);\n    for (int i = 0; i <\
    \ m; i++) {\n        int a, b, c;\n        cin >> a >> b >> c;\n        prim.add_edge(a,\
    \ b, c);\n    }\n    cout << prim.solve() << '\\n';\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n#include \"../graph/prim.cpp\"\n#include \"../template/const.hpp\"\n\nint main()\
    \ {\n    int n, m;\n    cin >> n >> m;\n    Prim<int, INF> prim(n);\n    for (int\
    \ i = 0; i < m; i++) {\n        int a, b, c;\n        cin >> a >> b >> c;\n  \
    \      prim.add_edge(a, b, c);\n    }\n    cout << prim.solve() << '\\n';\n\n\
    \    return 0;\n}"
  dependsOn:
  - graph/prim.cpp
  isVerificationFile: true
  path: test/prim.test.cpp
  requiredBy: []
  timestamp: '2022-10-23 13:46:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/prim.test.cpp
layout: document
redirect_from:
- /verify/test/prim.test.cpp
- /verify/test/prim.test.cpp.html
title: test/prim.test.cpp
---
