---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/trie.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <int char_size, int base>\nstruct Trie {\n    struct Node {\n\
    \        vector<int> child, accept;\n        int c, common;\n        Node(int\
    \ c) : c(c), common(0) {\n            child.assign(char_size, -1);\n        }\n\
    \    };\n    vector<Node> tree;\n    int root;\n    Trie() : root(0) {\n     \
    \   tree.push_back(Node(root));\n    }\n    void insert(const string &s, int id)\
    \ {\n        int node_id = 0;\n        for (int i = 0; i < (int)s.size(); ++i)\
    \ {\n            int c        = (int)(s[i] - base);\n            int &next_id\
    \ = tree[node_id].child[c];\n            if (next_id < 0) {\n                next_id\
    \ = (int)tree.size();\n                tree.push_back(Node(c));\n            }\n\
    \            ++tree[node_id].common;\n            node_id = next_id;\n       \
    \ }\n        ++tree[node_id].common;\n        tree[node_id].accept.push_back(id);\n\
    \    }\n    // insert s to Trie\n    void insert(const string &s) {\n        insert(s,\
    \ tree[0].common);\n    }\n    // return the number of s in Trie\n    int search(const\
    \ string &s, bool prefix = false) {\n        int node_id = 0;\n        for (int\
    \ i = 0; i < (int)s.size(); ++i) {\n            int c        = (int)(s[i] - base);\n\
    \            int &next_id = tree[node_id].child[c];\n            if (next_id <\
    \ 0) return 0;\n            node_id = next_id;\n        }\n        return prefix\
    \ ? 1 : (int)tree[node_id].accept.size();\n    }\n    // if prefix of s in Trie\n\
    \    bool prefix(const string &s) {\n        return search(s, true) > 0;\n   \
    \ }\n};\n\n// Trie<26,'a'> tr\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <int char_size, int base>\nstruct Trie {\n    struct Node {\n        vector<int>\
    \ child, accept;\n        int c, common;\n        Node(int c) : c(c), common(0)\
    \ {\n            child.assign(char_size, -1);\n        }\n    };\n    vector<Node>\
    \ tree;\n    int root;\n    Trie() : root(0) {\n        tree.push_back(Node(root));\n\
    \    }\n    void insert(const string &s, int id) {\n        int node_id = 0;\n\
    \        for (int i = 0; i < (int)s.size(); ++i) {\n            int c        =\
    \ (int)(s[i] - base);\n            int &next_id = tree[node_id].child[c];\n  \
    \          if (next_id < 0) {\n                next_id = (int)tree.size();\n \
    \               tree.push_back(Node(c));\n            }\n            ++tree[node_id].common;\n\
    \            node_id = next_id;\n        }\n        ++tree[node_id].common;\n\
    \        tree[node_id].accept.push_back(id);\n    }\n    // insert s to Trie\n\
    \    void insert(const string &s) {\n        insert(s, tree[0].common);\n    }\n\
    \    // return the number of s in Trie\n    int search(const string &s, bool prefix\
    \ = false) {\n        int node_id = 0;\n        for (int i = 0; i < (int)s.size();\
    \ ++i) {\n            int c        = (int)(s[i] - base);\n            int &next_id\
    \ = tree[node_id].child[c];\n            if (next_id < 0) return 0;\n        \
    \    node_id = next_id;\n        }\n        return prefix ? 1 : (int)tree[node_id].accept.size();\n\
    \    }\n    // if prefix of s in Trie\n    bool prefix(const string &s) {\n  \
    \      return search(s, true) > 0;\n    }\n};\n\n// Trie<26,'a'> tr"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.cpp
  requiredBy: []
  timestamp: '2022-08-27 12:40:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.cpp
layout: document
redirect_from:
- /library/string/trie.cpp
- /library/string/trie.cpp.html
title: string/trie.cpp
---
