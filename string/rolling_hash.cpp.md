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
  bundledCode: "#line 2 \"string/rolling_hash.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nusing u64                 = unsigned long long;\nconstexpr\
    \ u64 M           = 2305843009213693951; // 2^61 - 1\nconstexpr u64 MASK31   \
    \   = 2147483647;          // 2^31 - 1\nconstexpr u64 MASK30      = 1073741823;\
    \          // 2^30 - 1\nconstexpr u64 POSITIVIZER = 4 * M;\n\nu64 CalcMod(u64\
    \ x) {\n    u64 res = (x >> 61) + (x & M);\n    if (res >= M) res -= M;\n    return\
    \ res;\n}\nu64 mul(u64 x, u64 y) {\n    u64 au = (x >> 31), ad = (x & MASK31),\
    \ bu = (y >> 31), bd = (y & MASK31);\n    u64 m  = au * bd + ad * bu;\n    u64\
    \ mu = (m >> 30), md = (m & MASK30);\n    u64 ans = ((au * bu) << 1) + mu + (md\
    \ << 31) + ad * bd;\n    return CalcMod(ans);\n}\n\nstruct RollingHash {\n   \
    \ static u64 B;\n    int N;\n    vector<u64> hash, power;\n    RollingHash(const\
    \ string &s) {\n        N = (int)s.size();\n        hash.resize(N + 1, 0);\n \
    \       power.resize(N + 1, 0);\n        hash[0]  = 0;\n        power[0] = 1;\n\
    \        for (int i = 0; i < (int)s.size(); ++i) {\n            hash[i + 1]  =\
    \ CalcMod(mul(hash[i], B) + s[i]);\n            power[i + 1] = mul(power[i], B);\n\
    \        }\n    }\n    u64 get() { return hash[N]; }\n    u64 get(int k) { return\
    \ hash[k]; }\n    u64 get(int l, int r) { return CalcMod(hash[r] + POSITIVIZER\
    \ - mul(hash[l], power[r - l])); }\n};\n\nmt19937_64 mt;\nuniform_int_distribution<unsigned\
    \ long long> rng(2, M - 2);\nunsigned long long RollingHash::B = rng(mt);\n\n\
    /*\n\n// two 32bit MOD version\nstruct RollingHash {\n    using u64 = unsigned\
    \ long long;\n    static const u64 M1 = 2147483647,M2 = 1000000007;\n    static\
    \ u64 B1,B2;\n    int N;\n    vector<u64> hash1,hash2,power1,power2;\n\n    RollingHash(string\
    \ &s) {\n        N = s.size();\n        power1.resize(N + 1); power2.resize(N\
    \ + 1); hash1.resize(N + 1); hash2.resize(N + 1);\n        power1[0] = 1;    \
    \    power2[0] = 1;        hash1[0] = 0;        hash2[0] = 0;\n        for (int\
    \ i = 0;i < N; ++i) {\n            power1[i + 1] = power1[i] * B1 % M1;\n    \
    \        power2[i + 1] = power2[i] * B2 % M2;\n            hash1[i + 1] = (hash1[i]\
    \ * B1 + s[i]) % M1;\n            hash2[i + 1] = (hash2[i] * B2 + s[i]) % M2;\n\
    \        }\n    }\n    // return hash of S\n    pair<u64,u64> get() {\n      \
    \  return make_pair(hash1[N],hash2[N]);\n    }\n    // return hash of S[0,k)\n\
    \    pair<u64,u64> get(int k) {\n        return make_pair(hash1[k],hash2[k]);\n\
    \    }\n    // return hash of S[l,r)\n    pair<u64,u64> get(int l,int r) {\n \
    \       u64 x = (hash1[r] - (hash1[l] * power1[r - l]) % M1 + M1) % M1;\n    \
    \    u64 y = (hash2[r] - (hash2[l] * power2[r - l]) % M2 + M2) % M2;\n       \
    \ return make_pair(x,y);\n    }\n    //return if S[l1,r1) == S[l2,r2)\n    bool\
    \ equal(int l1,int r1,int l2,int r2) {\n        return get(l1,r1) == get(l2,r2);\n\
    \    }\n};\n\nmt19937_64 mt;\nuniform_int_distribution<unsigned long long> rand1(2,RollingHash::M1\
    \ - 2);\nuniform_int_distribution<unsigned long long> rand2(2,RollingHash::M2\
    \ - 2);\nunsigned long long RollingHash::B1 = rand1(mt);\nunsigned long long RollingHash::B2\
    \ = rand2(mt);\n\nusing u64 = unsigned long long;\nusing Pu = pair<u64,u64>;\n\
    \n*/\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing u64\
    \                 = unsigned long long;\nconstexpr u64 M           = 2305843009213693951;\
    \ // 2^61 - 1\nconstexpr u64 MASK31      = 2147483647;          // 2^31 - 1\n\
    constexpr u64 MASK30      = 1073741823;          // 2^30 - 1\nconstexpr u64 POSITIVIZER\
    \ = 4 * M;\n\nu64 CalcMod(u64 x) {\n    u64 res = (x >> 61) + (x & M);\n    if\
    \ (res >= M) res -= M;\n    return res;\n}\nu64 mul(u64 x, u64 y) {\n    u64 au\
    \ = (x >> 31), ad = (x & MASK31), bu = (y >> 31), bd = (y & MASK31);\n    u64\
    \ m  = au * bd + ad * bu;\n    u64 mu = (m >> 30), md = (m & MASK30);\n    u64\
    \ ans = ((au * bu) << 1) + mu + (md << 31) + ad * bd;\n    return CalcMod(ans);\n\
    }\n\nstruct RollingHash {\n    static u64 B;\n    int N;\n    vector<u64> hash,\
    \ power;\n    RollingHash(const string &s) {\n        N = (int)s.size();\n   \
    \     hash.resize(N + 1, 0);\n        power.resize(N + 1, 0);\n        hash[0]\
    \  = 0;\n        power[0] = 1;\n        for (int i = 0; i < (int)s.size(); ++i)\
    \ {\n            hash[i + 1]  = CalcMod(mul(hash[i], B) + s[i]);\n           \
    \ power[i + 1] = mul(power[i], B);\n        }\n    }\n    u64 get() { return hash[N];\
    \ }\n    u64 get(int k) { return hash[k]; }\n    u64 get(int l, int r) { return\
    \ CalcMod(hash[r] + POSITIVIZER - mul(hash[l], power[r - l])); }\n};\n\nmt19937_64\
    \ mt;\nuniform_int_distribution<unsigned long long> rng(2, M - 2);\nunsigned long\
    \ long RollingHash::B = rng(mt);\n\n/*\n\n// two 32bit MOD version\nstruct RollingHash\
    \ {\n    using u64 = unsigned long long;\n    static const u64 M1 = 2147483647,M2\
    \ = 1000000007;\n    static u64 B1,B2;\n    int N;\n    vector<u64> hash1,hash2,power1,power2;\n\
    \n    RollingHash(string &s) {\n        N = s.size();\n        power1.resize(N\
    \ + 1); power2.resize(N + 1); hash1.resize(N + 1); hash2.resize(N + 1);\n    \
    \    power1[0] = 1;        power2[0] = 1;        hash1[0] = 0;        hash2[0]\
    \ = 0;\n        for (int i = 0;i < N; ++i) {\n            power1[i + 1] = power1[i]\
    \ * B1 % M1;\n            power2[i + 1] = power2[i] * B2 % M2;\n            hash1[i\
    \ + 1] = (hash1[i] * B1 + s[i]) % M1;\n            hash2[i + 1] = (hash2[i] *\
    \ B2 + s[i]) % M2;\n        }\n    }\n    // return hash of S\n    pair<u64,u64>\
    \ get() {\n        return make_pair(hash1[N],hash2[N]);\n    }\n    // return\
    \ hash of S[0,k)\n    pair<u64,u64> get(int k) {\n        return make_pair(hash1[k],hash2[k]);\n\
    \    }\n    // return hash of S[l,r)\n    pair<u64,u64> get(int l,int r) {\n \
    \       u64 x = (hash1[r] - (hash1[l] * power1[r - l]) % M1 + M1) % M1;\n    \
    \    u64 y = (hash2[r] - (hash2[l] * power2[r - l]) % M2 + M2) % M2;\n       \
    \ return make_pair(x,y);\n    }\n    //return if S[l1,r1) == S[l2,r2)\n    bool\
    \ equal(int l1,int r1,int l2,int r2) {\n        return get(l1,r1) == get(l2,r2);\n\
    \    }\n};\n\nmt19937_64 mt;\nuniform_int_distribution<unsigned long long> rand1(2,RollingHash::M1\
    \ - 2);\nuniform_int_distribution<unsigned long long> rand2(2,RollingHash::M2\
    \ - 2);\nunsigned long long RollingHash::B1 = rand1(mt);\nunsigned long long RollingHash::B2\
    \ = rand2(mt);\n\nusing u64 = unsigned long long;\nusing Pu = pair<u64,u64>;\n\
    \n*/"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash.cpp
layout: document
redirect_from:
- /library/string/rolling_hash.cpp
- /library/string/rolling_hash.cpp.html
title: string/rolling_hash.cpp
---
