---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/strongly_connected_components.cpp
    title: graph/strongly_connected_components.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/strongly_connected_components.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/scc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#line 3 \"graph/strongly_connected_components.cpp\"\nusing namespace std;\n\
    \nstruct StronglyConnectedComponents {\n  private:\n    std::vector<int> visited;\n\
    \    std::vector<int> memo;\n\n    void _dfs(int v) {\n        group[v] = -1;\n\
    \        for (const int &u : G[v]) {\n            if (group[u] > 0) _dfs(u);\n\
    \        }\n        order.push_back(v);\n    }\n\n    void rdfs(int v, int cnt)\
    \ {\n        group[v] = cnt;\n        scc_group[cnt].push_back(v);\n        for\
    \ (const int &u : rG[v]) {\n            if (group[u] < 0) rdfs(u, cnt);\n    \
    \    }\n    }\n\n    int _dp(int v) {\n        if (visited[v] >= 0) return memo[v];\n\
    \        int ret = 0;\n        for (const int &u : sccG[v]) {\n            ret\
    \ |= _dp(u);\n        }\n        visited[v]     = 1;\n        return memo[v] =\
    \ ret;\n    }\n\n  public:\n    int N, N_scc;\n    std::vector<std::vector<int>>\
    \ G, rG;\n    std::vector<int> group, order;\n    std::vector<std::vector<int>>\
    \ scc_group, sccG;\n\n    // StronglyConnectedComponents receives N as the number\
    \ of vertex of graph G.\n    StronglyConnectedComponents(int N) : N(N) {\n   \
    \     G.resize(N);\n        rG.resize(N);\n        group.assign(N, 1);\n    }\n\
    \n    // add_edge receives a,b and creates edge a -> b.\n    // contraint: 0 <=\
    \ a,b < N\n    void add_edge(int a, int b) {\n        G[a].push_back(b);\n   \
    \     rG[b].push_back(a);\n    }\n\n    // build bulids strongly connected components.\n\
    \    // when build_scc is true, build scc_G\n    void build(bool build_scc) {\n\
    \        for (int i = 0; i < N; i++) {\n            if (group[i] > 0) _dfs(i);\n\
    \        }\n        std::reverse(order.begin(), order.end());\n        N_scc =\
    \ 0;\n        for (const int &v : order) {\n            if (group[v] < 0) {\n\
    \                scc_group.push_back({});\n                rdfs(v, N_scc);\n \
    \               N_scc++;\n            }\n        }\n\n        if (!build_scc)\n\
    \            return;\n\n        sccG.resize(N_scc);\n        for (int i = 0; i\
    \ < N_scc; i++) {\n            std::set<int> st;\n            for (const int &v\
    \ : scc_group[i]) {\n                for (const int &u : G[v]) {\n           \
    \         st.insert(group[u]);\n                }\n            }\n           \
    \ for (auto itr = st.begin(); itr != st.end(); itr++) {\n                sccG[i].push_back(*itr);\n\
    \            }\n        }\n    }\n\n    // DP MUST BE IMPLEMENTED DEPENDING ON\
    \ THE PROBLEM TO BE SOLVED.\n    // build must be called before dp is called.\n\
    \    int dp() {\n        visited.assign(N_scc, -1);\n        memo.resize(N_scc,\
    \ 0);\n        for (int i = 0; i < N_scc; i++) {\n            if ((int)scc_group[i].size()\
    \ > 1) {\n                memo[i]    = 1;\n                visited[i] = 1;\n \
    \           }\n        }\n\n        int ans = 0;\n        for (int i = 0; i <\
    \ N_scc; i++) {\n            if (_dp(i)) ans += (int)scc_group[i].size();\n  \
    \      }\n        return ans;\n    }\n\n    // scc[i] returns a group which vertex\
    \ i belongs to.\n    // this function is valid after build () is called.\n   \
    \ int operator[](int i) {\n        return group[i];\n    }\n};\n#line 5 \"test/strongly_connected_components.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    StronglyConnectedComponents\
    \ scc(n);\n    int a, b;\n    for (int i = 0; i < m; i++) {\n        cin >> a\
    \ >> b;\n        scc.add_edge(a, b);\n    }\n    scc.build(false);\n\n    cout\
    \ << scc.N_scc << '\\n';\n    for (int i = 0; i < scc.N_scc; i++) {\n        cout\
    \ << (int)(scc.scc_group[i].size()) << ' ';\n        for (int &u : scc.scc_group[i])\
    \ {\n            cout << u << \" \";\n        }\n        cout << '\\n';\n    }\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#include \"../graph/strongly_connected_components.cpp\"\n\
    \nint main() {\n    int n, m;\n    cin >> n >> m;\n    StronglyConnectedComponents\
    \ scc(n);\n    int a, b;\n    for (int i = 0; i < m; i++) {\n        cin >> a\
    \ >> b;\n        scc.add_edge(a, b);\n    }\n    scc.build(false);\n\n    cout\
    \ << scc.N_scc << '\\n';\n    for (int i = 0; i < scc.N_scc; i++) {\n        cout\
    \ << (int)(scc.scc_group[i].size()) << ' ';\n        for (int &u : scc.scc_group[i])\
    \ {\n            cout << u << \" \";\n        }\n        cout << '\\n';\n    }\n\
    \    return 0;\n}"
  dependsOn:
  - graph/strongly_connected_components.cpp
  isVerificationFile: true
  path: test/strongly_connected_components.test.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/strongly_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/strongly_connected_components.test.cpp
- /verify/test/strongly_connected_components.test.cpp.html
title: test/strongly_connected_components.test.cpp
---
