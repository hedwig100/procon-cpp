---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mint.cpp
    title: math/mint.cpp
  - icon: ':heavy_check_mark:'
    path: math/partition_number.cpp
    title: math/partition_number.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_J
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_J
  bundledCode: "#line 1 \"test/partition_number.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_J\"\
    \n#line 3 \"math/mint.cpp\"\nusing namespace std;\n\ntemplate <int MOD>\nstruct\
    \ ModInt {\n  public:\n    long long x;\n    ModInt(long long x = 0) : x((x %\
    \ MOD + MOD) % MOD) {}\n    constexpr ModInt &operator+=(const ModInt a) noexcept\
    \ {\n        if ((x += a.x) >= MOD) x -= MOD;\n        return *this;\n    }\n\
    \    constexpr ModInt &operator-=(const ModInt a) noexcept {\n        if ((x +=\
    \ MOD - a.x) >= MOD) x -= MOD;\n        return *this;\n    }\n    constexpr ModInt\
    \ &operator*=(const ModInt a) noexcept {\n        (x *= a.x) %= MOD;\n       \
    \ return *this;\n    }\n    constexpr ModInt &operator/=(const ModInt a) noexcept\
    \ { return *this *= a.inverse(); }\n\n    constexpr ModInt operator+(const ModInt\
    \ a) const noexcept { return ModInt(*this) += a.x; }\n    constexpr ModInt operator-(const\
    \ ModInt a) const noexcept { return ModInt(*this) -= a.x; }\n    constexpr ModInt\
    \ operator*(const ModInt a) const noexcept { return ModInt(*this) *= a.x; }\n\
    \    constexpr ModInt operator/(const ModInt a) const noexcept { return ModInt(*this)\
    \ /= a.x; }\n\n    friend constexpr std::ostream &operator<<(std::ostream &os,\
    \ const ModInt<MOD> a) noexcept { return os << a.x; }\n    friend constexpr std::istream\
    \ &operator>>(std::istream &is, ModInt<MOD> &a) noexcept {\n        is >> a.x;\n\
    \        a.x = (a.x % MOD + MOD) % MOD;\n        return is;\n    }\n\n    ModInt\
    \ inverse() const noexcept { // x ^ (-1)\n        long long a = x, b = MOD, p\
    \ = 1, q = 0;\n        while (b) {\n            long long d = a / b;\n       \
    \     a -= d * b;\n            swap(a, b);\n            p -= d * q;\n        \
    \    swap(p, q);\n        }\n        return ModInt(p);\n    }\n    ModInt pow(long\
    \ long N) const noexcept { // x ^ N\n        ModInt a = 1;\n        ModInt y =\
    \ this->x;\n        while (N) {\n            if (N & 1) a *= y;\n            y\
    \ *= y;\n            N >>= 1;\n        }\n        return a;\n    }\n};\n\ntemplate\
    \ <typename U, int MOD>\ninline ModInt<MOD> operator*(const U &c, const ModInt<MOD>\
    \ &a) { return {c * a.x}; }\n\nusing mint = ModInt<998244353>;\n#line 3 \"math/partition_number.cpp\"\
    \nusing namespace std;\n\n// PartionNumber\n// n\u500B\u306E\u533A\u5225\u3067\
    \u304D\u306A\u3044\u3082\u306E\u3092k\u500B\u306E\u533A\u5225\u3067\u304D\u306A\
    \u3044\u7BB1\u306B0\u500B\u4EE5\u4E0A\u306B\u5206\u5272\u3059\u308B\u65B9\u6CD5\
    \u304C\u4F55\u901A\u308A\u3042\u308B\u304B\u6C42\u3081\u308B.\n// \u3053\u308C\
    \u3092P(n,k)\u3068\u3059\u308B\u3068P(n,0) = 0 (n > 0)\ntemplate <typename T>\n\
    struct PartitionNumber {\n    int n, k;\n    vector<vector<T>> dp;\n\n    PartitionNumber(int\
    \ n, int k) : n(n), k(k) {\n        dp.assign(n + 1, vector<T>(k + 1, T(0)));\n\
    \    }\n\n    // solve\n    // 0 <= i <= n,0 <= j <= k\u306E\u5206\u5272\u6570\
    \u3092\u6C42\u3081\u308B.\n    // \u8A08\u7B97\u91CF: O(nk)\n    void solve()\
    \ {\n        dp[0][0] = T(1);\n        for (int i = 0; i <= n; i++) {\n      \
    \      for (int j = 1; j <= k; j++) {\n                dp[i][j] = dp[i][j - 1];\n\
    \                if (i - j >= 0) dp[i][j] += dp[i - j][j];\n            }\n  \
    \      }\n    }\n\n    // P(i,j)\u3092\u8FD4\u3059.\n    // \u5236\u7D04: 0 <=\
    \ i <= n,0 <= j <= k\n    T operator()(int i, int j) {\n        return dp[i][j];\n\
    \    }\n};\n#line 7 \"test/partition_number.test.cpp\"\n\nusing mint2 = ModInt<1000000007>;\n\
    \nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout\
    \ << fixed << setprecision(20);\n\n    int n, k;\n    cin >> n >> k;\n    PartitionNumber<mint2>\
    \ pn(n, k);\n    pn.solve();\n    cout << pn(n, k) << '\\n';\n\n    return 0;\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_J\"\
    \n#include \"../math/mint.cpp\"\n#include \"../math/partition_number.cpp\"\n\n\
    using mint2 = ModInt<1000000007>;\n\nint main() {\n    cin.tie(nullptr);\n   \
    \ ios::sync_with_stdio(false);\n    cout << fixed << setprecision(20);\n\n   \
    \ int n, k;\n    cin >> n >> k;\n    PartitionNumber<mint2> pn(n, k);\n    pn.solve();\n\
    \    cout << pn(n, k) << '\\n';\n\n    return 0;\n}"
  dependsOn:
  - math/mint.cpp
  - math/partition_number.cpp
  isVerificationFile: true
  path: test/partition_number.test.cpp
  requiredBy: []
  timestamp: '2023-01-28 20:23:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/partition_number.test.cpp
layout: document
redirect_from:
- /verify/test/partition_number.test.cpp
- /verify/test/partition_number.test.cpp.html
title: test/partition_number.test.cpp
---
