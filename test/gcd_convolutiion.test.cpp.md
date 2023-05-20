---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/mint.cpp
    title: math/mint.cpp
  - icon: ':heavy_check_mark:'
    path: math/zeta.cpp
    title: math/zeta.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "#line 1 \"test/gcd_convolutiion.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"math/mint.cpp\"\n\
    using namespace std;\n\ntemplate <int MOD>\nstruct ModInt {\n  public:\n    long\
    \ long x;\n    ModInt(long long x = 0) : x((x % MOD + MOD) % MOD) {}\n    constexpr\
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
    \ }\n\nusing mint = ModInt<998244353>;\n#line 3 \"math/zeta.cpp\"\nusing namespace\
    \ std;\n\n// a <= b <=> a <= b\n// g[x] = \\\\sum_{ i <= x } f[i]\ntemplate <class\
    \ R>\nstruct ZetaOrder {\n    // TODO:verify\n  public:\n    ZetaOrder() {}\n\n\
    \    void zeta(std::vector<R> &f) {\n        int sz = (int)f.size();\n       \
    \ for (int x = 1; x < sz; x++) {\n            f[x] += f[x - 1];\n        }\n \
    \   }\n\n    void mebius(std::vector<R> &f) {\n        int sz = (int)f.size();\n\
    \        for (int x = sz - 1; x >= 1; x--) {\n            f[x] -= f[x - 1];\n\
    \        }\n    }\n\n    std::vector<R> convolve(std::vector<R> f, std::vector<R>\
    \ g) {\n        int sz = std::max((int)f.size(), (int)g.size());\n        f.resize(sz,\
    \ 0);\n        g.resize(sz, 0);\n        zeta(f);\n        zeta(g);\n        std::vector<R>\
    \ h(sz);\n        for (int i = 0; i < sz; i++) {\n            h[i] = f[i] * g[i];\n\
    \        }\n        mebius(h);\n        return h;\n    }\n};\n\n// min_pow2 returns\
    \ minimum power of 2 larger than x (x <= 2^i)\n// and i (pair{i,2^i}).\n// x must\
    \ be more than 0\ntemplate <class T>\nstd::pair<int, T> min_pow2(T x) {\n    int\
    \ i = 0;\n    T ret = 1;\n    while (x > ret) {\n        i++;\n        ret <<=\
    \ 1;\n    }\n    return std::make_pair(i, ret);\n}\n\n// S <= T <=> S \\subset\
    \ T\n// g[T] = \\sum_{ S \\subset T } f[S]\ntemplate <class R>\nstruct ZetaSubset\
    \ {\n    // TODO:verify\n  private:\n    // min_pow2 returns minimum power of\
    \ 2 larger than x (x <= 2^i)\n    // and i (pair{i,2^i}).\n    // x must be more\
    \ than 0\n    std::pair<int, int> min_pow2(int x) {\n        int i   = 0;\n  \
    \      int ret = 1;\n        while (x > ret) {\n            i++;\n           \
    \ ret <<= 1;\n        }\n        return std::make_pair(i, ret);\n    }\n\n  public:\n\
    \    ZetaSubset() {}\n\n    void zeta(std::vector<R> &f) {\n        auto [d, sz]\
    \ = min_pow2((int)f.size());\n        f.resize(sz, (R)0);\n        for (int i\
    \ = 0; i < d; i++) {\n            for (int T = 0; T < sz; T++) {\n           \
    \     if (T & (1 << i))\n                    f[T] += f[T ^ (1 << i)];\n      \
    \      }\n        }\n    }\n\n    void mebius(std::vector<R> &f) {\n        auto\
    \ [d, sz] = min_pow2((int)f.size());\n        f.resize(sz, (R)0);\n        for\
    \ (int i = 0; i < d; i++) {\n            for (int T = 0; T < sz; T++) {\n    \
    \            if (T & (1 << i))\n                    f[T] -= f[T ^ (1 << i)];\n\
    \            }\n        }\n    }\n\n    std::vector<R> convolve(std::vector<R>\
    \ f, std::vector<R> g) {\n        int sz = std::max((int)f.size(), (int)g.size());\n\
    \        f.resize(sz, 0);\n        g.resize(sz, 0);\n        zeta(f);\n      \
    \  zeta(g);\n        std::vector<R> h(sz);\n        for (int i = 0; i < sz; i++)\
    \ {\n            h[i] = f[i] * g[i];\n        }\n        mebius(h);\n        return\
    \ h;\n    }\n};\n\n// a <= b <=> b | a\n// g[x] = \\sum_{ x | i } f[i]\ntemplate\
    \ <class R>\nstruct ZetaDiv {\n    // TODO: O(nloglogn) zeta transform\n  private:\n\
    \    // min_pow2 returns minimum power of 2 larger than x (x <= 2^i)\n    // and\
    \ i (pair{i,2^i}).\n    // x must be more than 0\n    std::pair<int, int> min_pow2(int\
    \ x) {\n        int i   = 0;\n        int ret = 1;\n        while (x > ret) {\n\
    \            i++;\n            ret <<= 1;\n        }\n        return std::make_pair(i,\
    \ ret);\n    }\n\n  public:\n    ZetaDiv() {}\n\n    void zeta(std::vector<R>\
    \ &f) {\n        int sz = (int)f.size();\n        for (int x = 1; x < sz; x++)\
    \ {\n            for (int i = 2 * x; i < sz; i += x) {\n                f[x] +=\
    \ f[i];\n            }\n        }\n    }\n\n    void mebius(std::vector<R> &f)\
    \ {\n        int sz = (int)f.size();\n        for (int x = sz - 1; x >= 1; x--)\
    \ {\n            for (int i = 2 * x; i < sz; i += x) {\n                f[x] -=\
    \ f[i];\n            }\n        }\n    }\n\n    std::vector<R> convolve(std::vector<R>\
    \ f, std::vector<R> g) {\n        int sz = std::min((int)f.size(), (int)g.size());\n\
    \        zeta(f);\n        zeta(g);\n        std::vector<R> h(sz);\n        for\
    \ (int i = 0; i < sz; i++) {\n            h[i] = f[i] * g[i];\n        }\n   \
    \     mebius(h);\n        return h;\n    }\n};\n#line 7 \"test/gcd_convolutiion.test.cpp\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    vector<mint> A(n + 1), B(n +\
    \ 1);\n    for (int i = 1; i <= n; i++)\n        cin >> A[i];\n    for (int i\
    \ = 1; i <= n; i++)\n        cin >> B[i];\n\n    ZetaDiv<mint> zeta;\n    auto\
    \ C = zeta.convolve(A, B);\n    for (int i = 1; i <= n; i++)\n        cout <<\
    \ C[i] << ' ';\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../math/mint.cpp\"\n#include\
    \ \"../math/zeta.cpp\"\n\nint main() {\n    int n;\n    cin >> n;\n    vector<mint>\
    \ A(n + 1), B(n + 1);\n    for (int i = 1; i <= n; i++)\n        cin >> A[i];\n\
    \    for (int i = 1; i <= n; i++)\n        cin >> B[i];\n\n    ZetaDiv<mint> zeta;\n\
    \    auto C = zeta.convolve(A, B);\n    for (int i = 1; i <= n; i++)\n       \
    \ cout << C[i] << ' ';\n    cout << '\\n';\n}"
  dependsOn:
  - math/mint.cpp
  - math/zeta.cpp
  isVerificationFile: true
  path: test/gcd_convolutiion.test.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/gcd_convolutiion.test.cpp
layout: document
redirect_from:
- /verify/test/gcd_convolutiion.test.cpp
- /verify/test/gcd_convolutiion.test.cpp.html
title: test/gcd_convolutiion.test.cpp
---
