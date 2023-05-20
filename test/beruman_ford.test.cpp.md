---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/beruman_ford.cpp
    title: graph/beruman_ford.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp
  bundledCode: "#line 1 \"test/beruman_ford.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp\"\
    \n#line 3 \"graph/beruman_ford.cpp\"\nusing namespace std;\n\n// beruman_ford\n\
    // \u8CA0\u8FBA\u3092\u542B\u3080\u30B0\u30E9\u30D5\u3092\u53D7\u3051\u53D6\u308A\
    , s\u304B\u3089\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\u8A08\u7B97\u3059\u308B.\n\
    template <typename T, const T INF>\nstruct BerumanFord {\n    struct edge {\n\
    \        int a, b;\n        T c;\n        edge() {}\n        edge(int a, int b,\
    \ T c) : a(a), b(b), c(c) {}\n    };\n\n  private:\n    int n;\n    vector<edge>\
    \ edges;\n    vector<T> dist;\n    bool find_negative_from_s = false;\n    vector<int>\
    \ negative_loop_from_s, prev;\n\n  public:\n    BerumanFord(int n) : n(n) {\n\
    \        dist.assign(n, INF);\n        negative_loop_from_s.assign(n, 0);\n  \
    \      prev.assign(n, -1);\n    }\n\n    // add_edge\n    // a\u304B\u3089b\u3078\
    \u8FBA\u91CD\u307Fc\u306E\u8FBA\u3092\u306F\u308B\n    void add_edge(int a, int\
    \ b, T c) {\n        edges.push_back(edge{a, b, c});\n    }\n\n    // solve\n\
    \    // s\u304B\u3089\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B. \u3082\
    \u3057s\u304B\u3089\u5230\u9054\u53EF\u80FD\u306A\u8CA0\u9589\u8DEF\u304C\u5B58\
    \u5728\u3059\u308C\u3070\n    // find_negative = true\u3068\u306A\u308B. s\u304B\
    \u3089\u306E\u6700\u77ED\u7D4C\u8DEF\u9577\u3092\u8FD4\u3059.\n    // \u8A08\u7B97\
    \u91CF: O(|V||E|)\n    vector<T> solve(int s = 0) {\n        fill(dist.begin(),\
    \ dist.end(), INF);\n        fill(negative_loop_from_s.begin(), negative_loop_from_s.end(),\
    \ 0);\n        dist[s] = 0;\n\n        for (int i = 0; i < n; ++i) {\n       \
    \     bool update = false;\n            for (const edge &e : edges) {\n      \
    \          if (dist[e.a] != INF && dist[e.b] > dist[e.a] + e.c) {\n          \
    \          dist[e.b] = dist[e.a] + e.c;\n                    prev[e.b] = e.a;\n\
    \                    update    = true;\n                    if (i == n - 1) negative_loop_from_s[e.b]\
    \ = 1;\n                }\n            }\n            if (!update) break;\n  \
    \          if (i == n - 1) find_negative_from_s = true;\n        }\n        return\
    \ dist;\n    }\n\n    // find_negloop_from_s\n    // s\u304B\u3089\u5230\u9054\
    \u53EF\u80FD\u306A\u8CA0\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308C\u3070true,\
    \ \u305D\u3046\u3067\u306A\u3051\u308C\u3070false\u3092\u8FD4\u3059kaesu.\n  \
    \  // \u5236\u7D04: solve()\u3092\u547C\u3093\u3067\u3044\u308B\u3053\u3068\n\
    \    bool find_negloop_from_s() {\n        return find_negative_from_s;\n    }\n\
    \n    // negloop_from_s\n    // s\u304B\u3089v\u307E\u3067\u306E\u7D4C\u8DEF\u306B\
    \u8CA0\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\u306A\u3089a[v]=1,\u305D\u3046\
    \u3067\u306A\u3044\u3068\u304DA[v]=0\u3067\u3042\u308B\u3088\u3046\u306A\n   \
    \ // \u914D\u5217A\u3092\u8FD4\u3059.\n    // \u5236\u7D04: \u4EE5\u524D\u306B\
    solve()\u3092\u547C\u3093\u3067\u3044\u308B\u3053\u3068\n    // \u8A08\u7B97\u91CF\
    : O(|V||E|) (dfs\u3068\u304B\u3067\u3082\u3063\u3068\u65E9\u304F\u3067\u304D\u308B\
    \u3051\u3069\u3042\u3093\u307E\u610F\u5473\u306A\u3044\u306E\u3067ok)\n    vector<int>\
    \ negloop_from_s() {\n        for (int i = 0; i < n; ++i) {\n            for (const\
    \ edge &e : edges) {\n                if (negative_loop_from_s[e.a]) negative_loop_from_s[e.b]\
    \ = 1;\n            }\n        }\n        return negative_loop_from_s;\n    }\n\
    \n    // find_neg_loop\n    // (s\u304B\u3089\u306F\u5230\u9054\u3067\u304D\u306A\
    \u3044\u3082\u306E\u3082\u542B\u3081\u3066)\u30B0\u30E9\u30D5\u306E\u8CA0\u9589\
    \u8DEF\u304C\u3042\u308B\u304B\u3092\u691C\u51FA\u3059\u308B\n    // \u8A08\u7B97\
    \u91CF: O(|V||E|)\n    bool find_neg_loop() {\n        bool neg_loop = false;\n\
    \        vector<T> dist(n, 0);\n        for (int i = 0; i < n; ++i) {\n      \
    \      for (const edge &e : edges) {\n                if (dist[e.a] != INF &&\
    \ dist[e.b] > dist[e.a] + e.c) {\n                    dist[e.b] = dist[e.a] +\
    \ e.c;\n                    if (i == n - 1) neg_loop = true;\n               \
    \ }\n            }\n        }\n        return neg_loop;\n    }\n\n    // restore_path\n\
    \    // \u9802\u70B9s\u304B\u3089t\u307E\u3067\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\
    \u6C42\u3081\u308B\u3002\n    // \u6700\u77ED\u7D4C\u8DEF\u304C\u5B58\u5728\u3059\
    \u308B\u5834\u5408, \u8FD4\u308A\u5024\u306F\u5148\u982D\u306Bs,t\u3092\u542B\u3080\
    . \u5B58\u5728\u3057\u306A\u3044\u3068\u304D\u7A7A\u3092\u8FD4\u3059.\n    //\
    \ \u5236\u7D04: s\u306F\u4EE5\u524D\u306Bsolve(s)\u304C\u547C\u3070\u308C\u3066\
    \u3044\u308B. 0 <= t < n\n    vector<int> restore_path(int s, int t) {\n     \
    \   if (dist[t] == INF) return {};\n\n        vector<int> ret;\n        int now_v\
    \ = t;\n        ret.push_back(now_v);\n        while (now_v != s) {\n        \
    \    now_v = prev[now_v];\n            ret.push_back(now_v);\n        }\n    \
    \    reverse(ret.begin(), ret.end());\n        return ret;\n    }\n};\n#line 2\
    \ \"template/const.hpp\"\nconstexpr int INF        = 1000'000'000;\nconstexpr\
    \ long long HINF = 4000'000'000'000'000'000;\nconstexpr long long MOD  = 998244353;\n\
    constexpr double EPS     = 1e-6;\nconstexpr double PI      = 3.14159265358979;\n\
    #line 7 \"test/beruman_ford.test.cpp\"\n\nint main() {\n    int n, m, s;\n   \
    \ cin >> n >> m >> s;\n    BerumanFord<int, INF> bf(n);\n    for (int i = 0; i\
    \ < m; i++) {\n        int a, b, c;\n        cin >> a >> b >> c;\n        bf.add_edge(a,\
    \ b, c);\n    }\n\n    auto dist = bf.solve(s);\n    if (bf.find_negloop_from_s())\n\
    \        cout << \"NEGATIVE CYCLE\\n\";\n    else {\n        for (auto &a : dist)\
    \ {\n            if (a == INF)\n                cout << \"INF\\n\";\n        \
    \    else\n                cout << a << '\\n';\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp\"\
    \n#include \"../graph/beruman_ford.cpp\"\n#include \"../template/const.hpp\"\n\
    \nint main() {\n    int n, m, s;\n    cin >> n >> m >> s;\n    BerumanFord<int,\
    \ INF> bf(n);\n    for (int i = 0; i < m; i++) {\n        int a, b, c;\n     \
    \   cin >> a >> b >> c;\n        bf.add_edge(a, b, c);\n    }\n\n    auto dist\
    \ = bf.solve(s);\n    if (bf.find_negloop_from_s())\n        cout << \"NEGATIVE\
    \ CYCLE\\n\";\n    else {\n        for (auto &a : dist) {\n            if (a ==\
    \ INF)\n                cout << \"INF\\n\";\n            else\n              \
    \  cout << a << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - graph/beruman_ford.cpp
  isVerificationFile: true
  path: test/beruman_ford.test.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/beruman_ford.test.cpp
layout: document
redirect_from:
- /verify/test/beruman_ford.test.cpp
- /verify/test/beruman_ford.test.cpp.html
title: test/beruman_ford.test.cpp
---
