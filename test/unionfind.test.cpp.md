---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structures/unionfind.cpp
    title: data_structures/unionfind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#line 2 \"data_structures/unionfind.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// UnionFind\n// \u30B0\u30EB\u30FC\u30D7\u3092\u7BA1\u7406\
    \u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\nstruct UnionFind {\n    int n;\n \
    \   vector<int> parents;\n\n    UnionFind(int n) : n(n) {\n        parents.assign(n,\
    \ -1);\n    }\n\n    // find\n    // x\u306E\u89AA\u3092\u8FD4\u3059.\n    //\
    \ \u5236\u7D04: 0 <= x < n\n    int find(int x) {\n        if (parents[x] < 0)\
    \ return x;\n        return parents[x] = find(parents[x]);\n    }\n\n    // unite\n\
    \    // x\u3068y\u3092\u542B\u3080\u30B0\u30EB\u30FC\u30D7\u3092\u4F75\u5408\n\
    \    // \u5236\u7D04: 0 <= x,y < n\n    void unite(int x, int y) { // x\u3068\
    y\u306E\u542B\u3080\u30B0\u30EB\u30FC\u30D7\u3092\u4F75\u5408\n        int px\
    \ = find(x);\n        int py = find(y);\n        if (parents[px] > parents[py])\
    \ swap(px, py);\n        if (px != py) {\n            parents[px] += parents[py];\n\
    \            parents[py] = px;\n        }\n    }\n\n    // same\n    // x\u3068\
    y\u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u3044\u308B\u304B\u5224\u5B9A\
    \n    // \u5236\u7D04: 0 <= x,y < n\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n\n    // size\n    // x\u3068\u540C\u3058\u30B0\u30EB\
    \u30FC\u30D7\u306E\u30E1\u30F3\u30D0\u30FC\u306E\u500B\u6570\n    // \u5236\u7D04\
    : 0 <= x < n\n    int size(int x) {\n        return -parents[find(x)];\n    }\n\
    \n    // root\n    // \u6839\u3092\u5168\u3066\u5217\u6319\u3059\u308B\n    vector<int>\
    \ root() {\n        vector<int> res;\n        for (int i = 0; i < n; i++) {\n\
    \            if (parents[i] < 0) res.push_back(i);\n        }\n        return\
    \ res;\n    }\n\n    // group_count\n    // \u30B0\u30EB\u30FC\u30D7\u306E\u6570\
    \u3092\u8FD4\u3059.\n    int group_count() { // uf\u306E\u30B0\u30EB\u30FC\u30D7\
    \u306E\u6570\u3092\u6570\u3048\u308B\n        return (int)root().size();\n   \
    \ }\n};\n#line 5 \"test/unionfind.test.cpp\"\nusing namespace std;\n\nint main()\
    \ {\n\n    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n    for (int i\
    \ = 0; i < q; i++) {\n        int t, u, v;\n        cin >> t >> u >> v;\n    \
    \    if (t == 0)\n            uf.unite(u, v);\n        else if (uf.same(u, v))\
    \ {\n            cout << 1 << '\\n';\n        } else {\n            cout << 0\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../data_structures/unionfind.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n\n    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n\
    \    for (int i = 0; i < q; i++) {\n        int t, u, v;\n        cin >> t >>\
    \ u >> v;\n        if (t == 0)\n            uf.unite(u, v);\n        else if (uf.same(u,\
    \ v)) {\n            cout << 1 << '\\n';\n        } else {\n            cout <<\
    \ 0 << '\\n';\n        }\n    }\n}"
  dependsOn:
  - data_structures/unionfind.cpp
  isVerificationFile: true
  path: test/unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-08-28 18:43:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/unionfind.test.cpp
- /verify/test/unionfind.test.cpp.html
title: test/unionfind.test.cpp
---
