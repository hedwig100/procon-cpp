---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/mint.cpp
    title: math/mint.cpp
  - icon: ':heavy_check_mark:'
    path: math/number_theoretic_transform.cpp
    title: math/number_theoretic_transform.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/ntt_recursive.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\
    \n\n#line 2 \"math/number_theoretic_transform.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"math/mint.cpp\"\nusing namespace std;\n\ntemplate\
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
    \ U &c, const ModInt<MOD> &a) { return {c * a.x}; }\n\nusing mint = ModInt<998244353>;\n\
    #line 5 \"math/number_theoretic_transform.cpp\"\n\n// NumberTheoreticTransform\
    \ supports only F_998244353 as coefficient.\n// recursive version\nstruct NumberTheoreticTransform\
    \ {\n  private:\n    const mint ROOT = 3;\n    const int MOD   = 998244353;\n\n\
    \  public:\n    NumberTheoreticTransform() {}\n\n    // ntt calculates y[i] =\
    \ \\sum_{j=0}^{n-1} x[j]r^{ij} where n is length of x and r is n-th root of 1\
    \ (mod n)\n    // n must be power of two (n = 2^m)\n    void ntt(int m, mint nth_root,\
    \ std::vector<mint> &x) {\n        if (m == 0) return;\n        int n = (int)x.size();\n\
    \        assert(n == (1 << m));\n\n        int n_half = n / 2;\n        std::vector<mint>\
    \ x_e(n_half), x_o(n_half);\n        for (int i = 0; i < n_half; i++) {\n    \
    \        x_e[i] = x[i << 1];\n            x_o[i] = x[i << 1 | 1];\n        }\n\
    \        ntt(m - 1, nth_root * nth_root, x_e);\n        ntt(m - 1, nth_root *\
    \ nth_root, x_o);\n\n        mint root_pow = 1;\n        int mask      = n_half\
    \ - 1;\n        for (int i = 0; i < n; i++) {\n            x[i] = x_e[i & mask]\
    \ + root_pow * x_o[i & mask];\n            root_pow *= nth_root;\n        }\n\
    \    }\n\n    // multiply calculates f*g, when f[i] is coefficients of x^i (0-indexed)\
    \ and g[i] is coefficients of x^i (0-indexed)\n    std::vector<mint> multiply(std::vector<mint>\
    \ f, std::vector<mint> g) {\n        int min_sz = (int)f.size() + (int)g.size()\
    \ + 1;\n        int m      = 0;\n        while ((1 << m) < min_sz) {\n       \
    \     ++m;\n        }\n        int sz = 1 << m;\n        f.resize(sz, (mint)0);\n\
    \        g.resize(sz, (mint)0);\n        assert((MOD - 1) % sz == 0);\n\n    \
    \    const mint nth_root = ROOT.pow((long long)(MOD - 1) / sz);\n        ntt(m,\
    \ nth_root, f);\n        ntt(m, nth_root, g);\n\n        std::vector<mint> h(sz);\n\
    \        for (int i = 0; i < sz; i++) {\n            h[i] = f[i] * g[i];\n   \
    \     }\n\n        ntt(m, nth_root.inverse(), h);\n        mint n_inv = mint(sz).inverse();\n\
    \        for (int i = 0; i < sz; i++) {\n            h[i] *= n_inv;\n        }\n\
    \        return h;\n    }\n};\n#line 5 \"test/ntt_recursive.test.cpp\"\nusing\
    \ namespace std;\n\nint main() {\n    int n, m;\n    std::cin >> n >> m;\n   \
    \ std::vector<mint> A(n), B(m);\n    for (int i = 0; i < n; i++)\n        std::cin\
    \ >> A[i];\n    for (int i = 0; i < m; i++)\n        std::cin >> B[i];\n\n   \
    \ NumberTheoreticTransform ntt;\n    std::vector<mint> C = ntt.multiply(A, B);\n\
    \    for (int i = 0; i < n + m - 1; i++) {\n        std::cout << C[i] << ' ';\n\
    \    }\n    std::cout << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"../math/number_theoretic_transform.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    int n, m;\n    std::cin >> n >> m;\n   \
    \ std::vector<mint> A(n), B(m);\n    for (int i = 0; i < n; i++)\n        std::cin\
    \ >> A[i];\n    for (int i = 0; i < m; i++)\n        std::cin >> B[i];\n\n   \
    \ NumberTheoreticTransform ntt;\n    std::vector<mint> C = ntt.multiply(A, B);\n\
    \    for (int i = 0; i < n + m - 1; i++) {\n        std::cout << C[i] << ' ';\n\
    \    }\n    std::cout << '\\n';\n    return 0;\n}"
  dependsOn:
  - math/number_theoretic_transform.cpp
  - math/mint.cpp
  isVerificationFile: true
  path: test/ntt_recursive.test.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ntt_recursive.test.cpp
layout: document
redirect_from:
- /verify/test/ntt_recursive.test.cpp
- /verify/test/ntt_recursive.test.cpp.html
title: test/ntt_recursive.test.cpp
---
