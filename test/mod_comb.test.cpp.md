---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mint.cpp
    title: math/mint.cpp
  - icon: ':heavy_check_mark:'
    path: math/mod_comb.cpp
    title: math/mod_comb.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D&lang=ja
  bundledCode: "#line 1 \"test/mod_comb.test.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D&lang=ja\"\
    \n#line 3 \"math/mod_comb.cpp\"\nusing namespace std;\n#line 2 \"template/const.hpp\"\
    \nconstexpr int INF        = 1000'000'000;\nconstexpr long long HINF = 4000'000'000'000'000'000;\n\
    constexpr long long MOD  = 998244353;\nconstexpr double EPS     = 1e-6;\nconstexpr\
    \ double PI      = 3.14159265358979;\n#line 3 \"math/mint.cpp\"\nusing namespace\
    \ std;\n\ntemplate <int MOD>\nstruct ModInt {\n  public:\n    long long x;\n \
    \   ModInt(long long x = 0) : x((x % MOD + MOD) % MOD) {}\n    constexpr ModInt\
    \ &operator+=(const ModInt a) noexcept {\n        if ((x += a.x) >= MOD) x -=\
    \ MOD;\n        return *this;\n    }\n    constexpr ModInt &operator-=(const ModInt\
    \ a) noexcept {\n        if ((x += MOD - a.x) >= MOD) x -= MOD;\n        return\
    \ *this;\n    }\n    constexpr ModInt &operator*=(const ModInt a) noexcept {\n\
    \        (x *= a.x) %= MOD;\n        return *this;\n    }\n    constexpr ModInt\
    \ &operator/=(const ModInt a) noexcept { return *this *= a.inverse(); }\n\n  \
    \  constexpr ModInt operator+(const ModInt a) const noexcept { return ModInt(*this)\
    \ += a.x; }\n    constexpr ModInt operator-(const ModInt a) const noexcept { return\
    \ ModInt(*this) -= a.x; }\n    constexpr ModInt operator*(const ModInt a) const\
    \ noexcept { return ModInt(*this) *= a.x; }\n    constexpr ModInt operator/(const\
    \ ModInt a) const noexcept { return ModInt(*this) /= a.x; }\n\n    friend constexpr\
    \ std::ostream &operator<<(std::ostream &os, const ModInt<MOD> a) noexcept { return\
    \ os << a.x; }\n    friend constexpr std::istream &operator>>(std::istream &is,\
    \ ModInt<MOD> &a) noexcept {\n        is >> a.x;\n        a.x = (a.x % MOD + MOD)\
    \ % MOD;\n        return is;\n    }\n\n    ModInt inverse() const noexcept { //\
    \ x ^ (-1)\n        long long a = x, b = MOD, p = 1, q = 0;\n        while (b)\
    \ {\n            long long d = a / b;\n            a -= d * b;\n            swap(a,\
    \ b);\n            p -= d * q;\n            swap(p, q);\n        }\n        return\
    \ ModInt(p);\n    }\n    ModInt pow(long long N) const noexcept { // x ^ N\n \
    \       ModInt a = 1;\n        ModInt y = this->x;\n        while (N) {\n    \
    \        if (N & 1) a *= y;\n            y *= y;\n            N >>= 1;\n     \
    \   }\n        return a;\n    }\n};\n\ntemplate <typename U, int MOD>\ninline\
    \ ModInt<MOD> operator*(const U &c, const ModInt<MOD> &a) { return {c * a.x};\
    \ }\n\nusing mint = ModInt<998244353>;\n#line 6 \"math/mod_comb.cpp\"\n\n// Combination\n\
    // mod MOD\u3067\u968E\u4E57\u3092\u8A08\u7B97\u3057\u3066\u304A\u304F\u3053\u3068\
    \u3067comb(n,k)\u306A\u3069\u3092O(1)\n// \u3067\u8A08\u7B97\u3059\u308B. MOD\u306F\
    const\u306A\u7D20\u6570\ntemplate <const int MOD>\nstruct Combination {\n    using\
    \ mint = ModInt<MOD>;\n    int n;\n    vector<mint> fact, ifact, invs;\n\n   \
    \ Combination(int n) : n(n) {\n        fact.resize(n + 1);\n        ifact.resize(n\
    \ + 1);\n        fact[0] = fact[1] = 1;\n        ifact[0] = ifact[1] = 1;\n  \
    \      for (int i = 2; i <= n; ++i) {\n            fact[i] = fact[i - 1] * i;\n\
    \        }\n        ifact[n] = fact[n].inverse();\n        for (int i = n; i >=\
    \ 1; --i) {\n            ifact[i - 1] = ifact[i] * i;\n        }\n    }\n\n  \
    \  // invs_build\n    // ax = 1 mod MOD\u3092\u307F\u305F\u3059x\u3092a=1,...,n\u306B\
    \u3064\u3044\u3066\u8A08\u7B97\u3059\u308B.\n    // \u8A08\u7B97\u91CF: O(n)\n\
    \    void invs_build() {\n        invs.resize(n + 1);\n        invs[1] = 1;\n\
    \        for (int i = 2; i <= n; ++i)\n            invs[i] = fact[i] * ifact[i\
    \ - 1];\n    }\n\n    // (n,k)\n    // 0 <= k <= n\u306A\u3089 nCk \u3092\u8FD4\
    \u3057, \u305D\u3046\u3067\u306A\u3044\u306A\u30890\u3092\u8FD4\u3059.\n    //\
    \ \u5236\u7D04: k,n\u6574\u6570\n    mint operator()(int n, int k) {\n       \
    \ if (k < 0 || k > n) return 0;\n        return fact[n] * ifact[k] * ifact[n -\
    \ k];\n    }\n\n    // npk\n    // 0 <= k <= n\u306A\u3089 nPk \u3092\u8FD4\u3057\
    , \u305D\u3046\u3067\u306A\u3044\u306A\u30890\u3092\u8FD4\u3059.\n    // \u5236\
    \u7D04: k,n\u6574\u6570\n    mint npk(int n, int k) {\n        if (k < 0 || k\
    \ > n) return 0;\n        return fact[n] * ifact[n - k];\n    }\n};\n\n// nck_nbig\n\
    // n\u304C\u5927\u304D\u3044\u6642\u306BnCk\u3092\u8A08\u7B97\u3059\u308B\n//\
    \ \u8A08\u7B97\u91CF: O(k)\ntemplate <const int MOD>\nModInt<MOD> nck_nbig(long\
    \ long n, int k) {\n    using mint = ModInt<MOD>;\n    mint ans   = 1;\n    for\
    \ (int i = 0; i < k; ++i)\n        ans *= mint(n - i);\n    for (int i = 1; i\
    \ < k + 1; ++i)\n        ans *= mint(i).inverse();\n    return ans;\n}\n\n// modpow\n\
    // x^y mod m\u3092\u8A08\u7B97\u3059\u308B\n// \u8A08\u7B97\u91CF: O(logy)\nlong\
    \ long modpow(long long x, long long y, long long m) {\n    long long ans = 1,\
    \ tmp = x;\n    while (y > 0) {\n        if (y & 1) {\n            ans = (ans\
    \ * tmp) % m;\n        }\n        y >>= 1;\n        tmp = (tmp * tmp) % m;\n \
    \   }\n    return ans;\n}\n#line 6 \"test/mod_comb.test.cpp\"\n\nint main() {\n\
    \    int n, k;\n    cin >> n >> k;\n    Combination<1000000007> comb(n + k);\n\
    \    cout << comb(n + k - 1, n) << '\\n';\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D&lang=ja\"\
    \n#include \"../math/mod_comb.cpp\"\n\nint main() {\n    int n, k;\n    cin >>\
    \ n >> k;\n    Combination<1000000007> comb(n + k);\n    cout << comb(n + k -\
    \ 1, n) << '\\n';\n    return 0;\n}"
  dependsOn:
  - math/mod_comb.cpp
  - math/mint.cpp
  isVerificationFile: true
  path: test/mod_comb.test.cpp
  requiredBy: []
  timestamp: '2023-01-28 20:23:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mod_comb.test.cpp
layout: document
redirect_from:
- /verify/test/mod_comb.test.cpp
- /verify/test/mod_comb.test.cpp.html
title: test/mod_comb.test.cpp
---
