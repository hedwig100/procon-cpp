---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/bell_number.cpp
    title: math/bell_number.cpp
  - icon: ':question:'
    path: math/mint.cpp
    title: math/mint.cpp
  - icon: ':question:'
    path: math/stirling_number2.cpp
    title: math/stirling_number2.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G
  bundledCode: "#line 1 \"test/bell_number.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G\"\
    \n#line 3 \"math/bell_number.cpp\"\nusing namespace std;\n\n#line 3 \"math/stirling_number2.cpp\"\
    \nusing namespace std;\n\n// StirlingNumber2\n// n\u500B\u306E\u533A\u5225\u3067\
    \u304D\u308B\u3082\u306E\u3092k\u500B\u306E\u533A\u5225\u3067\u304D\u306A\u3044\
    \u7BB1\u306B1\u500B\u4EE5\u4E0A\u306B\u5206\u5272\u3059\u308B\u65B9\u6CD5\u304C\
    \u4F55\u901A\u308A\u3042\u308B\u304B\u6C42\u3081\u308B.\n// \u3053\u308C\u3092\
    S(n,k)\u3068\u3059\u308B. \u7B2C\u4E8C\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\
    \u6570\ntemplate <typename T>\nstruct StirlingNumber2 {\n    int n, k;\n    vector<vector<T>>\
    \ dp;\n\n    StirlingNumber2(int n, int k) : n(n), k(k) {\n        dp.assign(n\
    \ + 1, vector<T>(k + 1, T(0)));\n    }\n\n    // solve\n    // S(i,j) (0 <= i\
    \ <= n, 0 <= j <= k)\u3092\u6C42\u3081\u308B.\n    // \u8A08\u7B97\u91CF: O(nk)\n\
    \    T solve() {\n        dp[0][0] = T(1);\n        for (int i = 1; i <= n; i++)\
    \ {\n            for (int j = 0; j <= k; j++) {\n                dp[i][j] = T(j)\
    \ * dp[i - 1][j];\n                if (j > 0) dp[i][j] += dp[i - 1][j - 1];\n\
    \            }\n        }\n        return dp[n][k];\n    }\n\n    // S(i,j)\u3092\
    \u8FD4\u3059.\n    // \u5236\u7D04: 0 <= i <= n, 0 <= j <= k\n    T operator()(int\
    \ i, int j) {\n        return dp[i][j];\n    }\n};\n#line 6 \"math/bell_number.cpp\"\
    \n\n/**\n * BellNumber\n * n\u500B\u306E\u533A\u5225\u3067\u304D\u308B\u3082\u306E\
    \u3092k\u500B\u306E\u533A\u5225\u3067\u304D\u306A\u3044\u7BB1\u306B0\u500B\u4EE5\
    \u4E0A\u306B\u5206\u5272\u3059\u308B\u65B9\u6CD5\u304C\u4F55\u901A\u308A\u3042\
    \u308B\u304B\u6C42\u3081\u308B.\n * \u3053\u308C\u3092B(n,k)\u3068\u3057\u3066\
    \u30D9\u30EB\u6570\u3068\u3044\u3046.\n */\ntemplate <typename T>\nstruct BellNumber\
    \ {\n    int n, k;\n    vector<vector<T>> dp;\n\n    BellNumber(int n, int k)\
    \ : n(n), k(k) {\n        dp.assign(n + 1, vector<T>(k + 1, T(0)));\n    }\n\n\
    \    /**\n     * solve\n     * 0 <= i <= n,0 <= j <= k\u306B\u3064\u3044\u3066\
    B(i,j)\u3092\u6C42\u3081\u308B.\n     * \u8A08\u7B97\u91CF: O(nk)\n     */\n \
    \   T solve() {\n        StirlingNumber2<T> s2(n, k);\n        s2.solve();\n \
    \       for (int i = 0; i <= n; i++) {\n            for (int j = 1; j <= k; j++)\
    \ {\n                dp[i][j] = dp[i][j - 1] + s2(i, j);\n            }\n    \
    \    }\n        return dp[n][k];\n    }\n\n    /**\n     * operator()\n     *\
    \ @param i int\n     * @param j int\n     * B(i,j) \u3092\u8FD4\u3059.\n     *\
    \ \u5236\u7D04: 0 <= i <= n,0 <= j <= k\n     */\n    T operator()(int i, int\
    \ j) {\n        return dp[i][j];\n    }\n};\n#line 3 \"math/mint.cpp\"\nusing\
    \ namespace std;\n\ntemplate <int MOD>\nstruct ModInt {\n  public:\n    long long\
    \ x;\n    ModInt(long long x = 0) : x((x % MOD + MOD) % MOD) {}\n    constexpr\
    \ ModInt &operator+=(const ModInt a) noexcept {\n        if ((x += a.x) >= MOD)\
    \ x -= MOD;\n        return *this;\n    }\n    constexpr ModInt &operator-=(const\
    \ ModInt a) noexcept {\n        if ((x += MOD - a.x) >= MOD) x -= MOD;\n     \
    \   return *this;\n    }\n    constexpr ModInt &operator*=(const ModInt a) noexcept\
    \ {\n        (x *= a.x) %= MOD;\n        return *this;\n    }\n    constexpr ModInt\
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
    \ }\n\nusing mint = ModInt<998244353>;\n#line 7 \"test/bell_number.test.cpp\"\n\
    \nusing mint2 = ModInt<1000000007>;\n\nint main() {\n    int n, k;\n    cin >>\
    \ n >> k;\n    BellNumber<mint2> bell(n, k);\n    cout << bell.solve() << '\\\
    n';\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G\"\
    \n#include \"../math/bell_number.cpp\"\n#include \"../math/mint.cpp\"\n\nusing\
    \ mint2 = ModInt<1000000007>;\n\nint main() {\n    int n, k;\n    cin >> n >>\
    \ k;\n    BellNumber<mint2> bell(n, k);\n    cout << bell.solve() << '\\n';\n\n\
    \    return 0;\n}"
  dependsOn:
  - math/bell_number.cpp
  - math/stirling_number2.cpp
  - math/mint.cpp
  isVerificationFile: true
  path: test/bell_number.test.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/bell_number.test.cpp
layout: document
redirect_from:
- /verify/test/bell_number.test.cpp
- /verify/test/bell_number.test.cpp.html
title: test/bell_number.test.cpp
---
