---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/fast_fourier_transform.cpp
    title: math/fast_fourier_transform.cpp
  - icon: ':warning:'
    path: math/matrix.cpp
    title: math/matrix.cpp
  - icon: ':heavy_check_mark:'
    path: math/mod_comb.cpp
    title: math/mod_comb.cpp
  - icon: ':heavy_check_mark:'
    path: math/number_theoretic_transform.cpp
    title: math/number_theoretic_transform.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bell_number.test.cpp
    title: test/bell_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/gcd_convolutiion.test.cpp
    title: test/gcd_convolutiion.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mod_comb.test.cpp
    title: test/mod_comb.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ntt_recursive.test.cpp
    title: test/ntt_recursive.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/partition_number.test.cpp
    title: test/partition_number.test.cpp
  - icon: ':x:'
    path: test/stirling_number2.test.cpp
    title: test/stirling_number2.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mint.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
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
    \ }\n\nusing mint = ModInt<998244353>;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <int MOD>\nstruct ModInt {\n  public:\n    long long x;\n    ModInt(long long\
    \ x = 0) : x((x % MOD + MOD) % MOD) {}\n    constexpr ModInt &operator+=(const\
    \ ModInt a) noexcept {\n        if ((x += a.x) >= MOD) x -= MOD;\n        return\
    \ *this;\n    }\n    constexpr ModInt &operator-=(const ModInt a) noexcept {\n\
    \        if ((x += MOD - a.x) >= MOD) x -= MOD;\n        return *this;\n    }\n\
    \    constexpr ModInt &operator*=(const ModInt a) noexcept {\n        (x *= a.x)\
    \ %= MOD;\n        return *this;\n    }\n    constexpr ModInt &operator/=(const\
    \ ModInt a) noexcept { return *this *= a.inverse(); }\n\n    constexpr ModInt\
    \ operator+(const ModInt a) const noexcept { return ModInt(*this) += a.x; }\n\
    \    constexpr ModInt operator-(const ModInt a) const noexcept { return ModInt(*this)\
    \ -= a.x; }\n    constexpr ModInt operator*(const ModInt a) const noexcept { return\
    \ ModInt(*this) *= a.x; }\n    constexpr ModInt operator/(const ModInt a) const\
    \ noexcept { return ModInt(*this) /= a.x; }\n\n    friend constexpr std::ostream\
    \ &operator<<(std::ostream &os, const ModInt<MOD> a) noexcept { return os << a.x;\
    \ }\n    friend constexpr std::istream &operator>>(std::istream &is, ModInt<MOD>\
    \ &a) noexcept {\n        is >> a.x;\n        a.x = (a.x % MOD + MOD) % MOD;\n\
    \        return is;\n    }\n\n    ModInt inverse() const noexcept { // x ^ (-1)\n\
    \        long long a = x, b = MOD, p = 1, q = 0;\n        while (b) {\n      \
    \      long long d = a / b;\n            a -= d * b;\n            swap(a, b);\n\
    \            p -= d * q;\n            swap(p, q);\n        }\n        return ModInt(p);\n\
    \    }\n    ModInt pow(long long N) const noexcept { // x ^ N\n        ModInt\
    \ a = 1;\n        ModInt y = this->x;\n        while (N) {\n            if (N\
    \ & 1) a *= y;\n            y *= y;\n            N >>= 1;\n        }\n       \
    \ return a;\n    }\n};\n\ntemplate <typename U, int MOD>\ninline ModInt<MOD> operator*(const\
    \ U &c, const ModInt<MOD> &a) { return {c * a.x}; }\n\nusing mint = ModInt<998244353>;"
  dependsOn: []
  isVerificationFile: false
  path: math/mint.cpp
  requiredBy:
  - math/matrix.cpp
  - math/fast_fourier_transform.cpp
  - math/mod_comb.cpp
  - math/number_theoretic_transform.cpp
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/stirling_number2.test.cpp
  - test/gcd_convolutiion.test.cpp
  - test/ntt_recursive.test.cpp
  - test/mod_comb.test.cpp
  - test/partition_number.test.cpp
  - test/bell_number.test.cpp
documentation_of: math/mint.cpp
layout: document
redirect_from:
- /library/math/mint.cpp
- /library/math/mint.cpp.html
title: math/mint.cpp
---
