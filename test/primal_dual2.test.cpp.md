---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/primal_dual2.cpp
    title: graph/primal_dual2.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=ja
  bundledCode: "#line 1 \"test/primal_dual2.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=ja\"\
    \n#line 3 \"graph/primal_dual2.cpp\"\nusing namespace std;\n\n// PrimalDual2\n\
    // berumanford\u6CD5\u3092\u7528\u3044\u3066\u6700\u5C0F\u8CBB\u7528\u6D41\u3092\
    \u6C42\u3081\u308B.\n// \u6700\u521D\u306E\u30B0\u30E9\u30D5\u306B\u306F\u8CA0\
    \u9589\u8DEF\u304C\u542B\u307E\u308C\u3066\u306F\u3044\u3051\u306A\u3044.\ntemplate\
    \ <typename Cap, typename Cost, const Cost INF>\nstruct PrimalDual2 {\n    struct\
    \ edge {\n        int to;\n        Cap cap;\n        Cost cost;\n        int rev;\n\
    \    };\n\n    int n;\n    vector<vector<edge>> G;\n    vector<Cost> dist;\n \
    \   vector<int> prevv, preve;\n\n    PrimalDual2(int n) : n(n) {\n        G.resize(n);\n\
    \        dist.resize(n);\n        prevv.resize(n);\n        preve.resize(n);\n\
    \    }\n\n    // add_edge\n    // from\u304B\u3089to\u3078\u5BB9\u91CFcap, \u30B3\
    \u30B9\u30C8cost\u306E\u8FBA\u3092\u5F35\u308B.\n    // \u5236\u7D04: 0 <= from,to\
    \ < n,cap >= 0,\n    void add_edge(int from, int to, Cap cap, Cost cost) {\n \
    \       G[from].push_back((edge){to, cap, cost, (int)G[to].size()});\n       \
    \ G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});\n    }\n\n\
    \    // beruman\n    int beruman(int s, int t) {\n        fill(dist.begin(), dist.end(),\
    \ INF);\n        dist[s]     = 0;\n        bool update = true;\n        while\
    \ (update) {\n            update = false;\n            for (int v = 0; v < n;\
    \ v++) {\n                if (dist[v] == INF) continue;\n                for (int\
    \ i = 0; i < (int)G[v].size(); i++) {\n                    edge &e = G[v][i];\n\
    \                    if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {\n     \
    \                   dist[e.to]  = dist[v] + e.cost;\n                        prevv[e.to]\
    \ = v;\n                        preve[e.to] = i;\n                        update\
    \      = true;\n                    }\n                }\n            }\n    \
    \    }\n        return dist[t] < INF;\n    }\n\n    // solve\n    // s\u304B\u3089\
    t\u3078f\u3060\u3051\u6D41\u3059\u305F\u3081\u306E\u6700\u5C0F\u8CBB\u7528\u3092\
    \u6C42\u3081\u308B.\n    // \u5236\u7D04: 0 <= s,t < n,f >= 0\n    // \u8A08\u7B97\
    \u91CF: O(f|V||E|)\n    pair<Cap, Cost> solve(int s, int t, Cap f) {\n       \
    \ Cost ret_cost = 0;\n        Cap ret_flow  = 0;\n        while (ret_flow < f)\
    \ {\n            if (!beruman(s, t))\n                break;\n            Cap\
    \ d = f - ret_flow;\n            for (int v = t; v != s; v = prevv[v]) {\n   \
    \             d = min(d, G[prevv[v]][preve[v]].cap);\n            }\n        \
    \    ret_flow += d;\n            ret_cost += d * dist[t];\n            for (int\
    \ v = t; v != s; v = prevv[v]) {\n                edge &e = G[prevv[v]][preve[v]];\n\
    \                e.cap -= d;\n                G[v][e.rev].cap += d;\n        \
    \    }\n        }\n        return {ret_flow, ret_cost};\n    }\n};\n#line 2 \"\
    template/const.hpp\"\nconstexpr int INF        = 1000'000'000;\nconstexpr long\
    \ long HINF = 4000'000'000'000'000'000;\nconstexpr long long MOD  = 998244353;\n\
    constexpr double EPS     = 1e-6;\nconstexpr double PI      = 3.14159265358979;\n\
    #line 7 \"test/primal_dual2.test.cpp\"\n\nint main() {\n    int n, m, f;\n   \
    \ cin >> n >> m >> f;\n    PrimalDual2<int, int, INF> pd(n);\n    int u, v, c,\
    \ d;\n    for (int i = 0; i < m; i++) {\n        cin >> u >> v >> c >> d;\n  \
    \      pd.add_edge(u, v, c, d);\n    }\n\n    auto [actual_f, cost] = pd.solve(0,\
    \ n - 1, f);\n    if (actual_f < f)\n        cout << -1 << '\\n';\n    else\n\
    \        cout << cost << '\\n';\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=ja\"\
    \n#include \"../graph/primal_dual2.cpp\"\n#include \"../template/const.hpp\"\n\
    \nint main() {\n    int n, m, f;\n    cin >> n >> m >> f;\n    PrimalDual2<int,\
    \ int, INF> pd(n);\n    int u, v, c, d;\n    for (int i = 0; i < m; i++) {\n \
    \       cin >> u >> v >> c >> d;\n        pd.add_edge(u, v, c, d);\n    }\n\n\
    \    auto [actual_f, cost] = pd.solve(0, n - 1, f);\n    if (actual_f < f)\n \
    \       cout << -1 << '\\n';\n    else\n        cout << cost << '\\n';\n    return\
    \ 0;\n}"
  dependsOn:
  - graph/primal_dual2.cpp
  isVerificationFile: true
  path: test/primal_dual2.test.cpp
  requiredBy: []
  timestamp: '2022-10-23 13:46:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/primal_dual2.test.cpp
layout: document
redirect_from:
- /verify/test/primal_dual2.test.cpp
- /verify/test/primal_dual2.test.cpp.html
title: test/primal_dual2.test.cpp
---
