---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/mint.cpp
    title: math/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 3 \"math/mint.cpp\"\nusing namespace std;\n\ntemplate <int MOD>\n\
    struct ModInt {\n  public:\n    long long x;\n    ModInt(long long x = 0) : x((x\
    \ % MOD + MOD) % MOD) {}\n    constexpr ModInt &operator+=(const ModInt a) noexcept\
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
    \ &a) { return {c * a.x}; }\n\nusing mint = ModInt<998244353>;\n#line 6 \"math/matrix.cpp\"\
    \n\ntemplate <typename T>\nusing Matrix = vector<vector<T>>;\n\ntemplate <typename\
    \ T>\nMatrix<T> mul(const Matrix<T> &a, const Matrix<T> &b) {\n    assert(a[0].size()\
    \ == b.size());\n    Matrix<T> c(a.size(), vector<T>(b[0].size()));\n    for (int\
    \ i = 0; i < (int)a.size(); i++) {\n        for (int j = 0; j < (int)a[0].size();\
    \ j++) {\n            for (int k = 0; k < (int)b[0].size(); k++) {\n         \
    \       c[i][k] += a[i][j] * b[j][k];\n            }\n        }\n    }\n    return\
    \ c;\n}\n\ntemplate <typename T>\nvector<T> mul(const Matrix<T> &a, const vector<T>\
    \ &b) {\n    assert(a[0].size() == b.size());\n    vector<T> ans(a.size(), 0);\n\
    \    for (int i = 0; i < (int)a.size(); i++) {\n        for (int j = 0; j < (int)a[0].size();\
    \ j++) {\n            ans[i] += a[i][j] * b[j];\n        }\n    }\n    return\
    \ ans;\n}\n\ntemplate <typename T, typename U>\nMatrix<T> pow(Matrix<T> a, U n)\
    \ {\n    assert(a.size() == a[0].size());\n    int m = (int)a.size();\n    Matrix<T>\
    \ ans(m, vector<T>(m, 0));\n    for (int i = 0; i < m; i++)\n        ans[i][i]\
    \ = 1;\n    while (n > 0) {\n        if (n & 1) {\n            ans = mul(ans,\
    \ a);\n        }\n        a = mul(a, a);\n        n >>= 1;\n    }\n    return\
    \ ans;\n}\n\ntemplate <int MOD>\nint _find_pivot(const Matrix<ModInt<MOD>> &a,\
    \ int i) {\n    for (int j = i; j < (int)a[i].size(); j++) {\n        if (a[j][i].x\
    \ != 0) return j;\n    }\n    return -1;\n}\n\ntemplate <typename T>\nint _find_pivot(const\
    \ Matrix<T> &a, int i) {\n    int pivot = -1;\n    T val     = T(0);\n    for\
    \ (int j = i; j < (int)a[i].size(); j++) {\n        if (abs(a[j][i]) > val) {\n\
    \            val   = abs(a[j][i]);\n            pivot = j;\n        }\n    }\n\
    \    return pivot;\n}\n\n// lu_decomposition\n// PA = LU\u306A\u308B\u5206\u89E3\
    \u3092\u3059\u308B. \u305F\u3060\u3057, P\u306F\u7F6E\u63DB\u884C\u5217, L\u306F\
    \u5BFE\u89D2\u6210\u5206\u304C1\u306E\u4E0B\u4E09\u89D2\u884C\u5217, U\u306F\u4E0A\
    \u4E09\u89D2\u884C\u5217.\n// \u7F6E\u63DBP\u3068L,U\u3092\u8A70\u3081\u305F\u884C\
    \u5217\u3092\u8FD4\u3059. A\u304C\u6B63\u5247\u3067\u306F\u306A\u3044\u5834\u5408\
    , U\u306E\u5BFE\u89D2\u6210\u5206\u306B0\u304C\u542B\u307E\u308C\u308B.\n// \u8A08\
    \u7B97\u91CF: O(n^3)\ntemplate <typename T>\npair<vector<int>, Matrix<T>> lu_decomposition(Matrix<T>\
    \ a) {\n    assert(a.size() == a[0].size());\n    int n = (int)a.size();\n   \
    \ vector<int> pinv(n);\n    iota(pinv.begin(), pinv.end(), 0);\n    for (int i\
    \ = 0; i < n; i++) {\n        int pivot = _find_pivot(a, i);\n        if (pivot\
    \ < 0) continue;\n        swap(a[i], a[pivot]), swap(pinv[i], pinv[pivot]);\n\
    \        for (int j = i + 1; j < n; j++) {\n            a[j][i] /= a[i][i];\n\
    \            for (int k = i + 1; k < n; k++) {\n                a[j][k] -= a[i][k]\
    \ * a[j][i];\n            }\n        }\n    }\n    vector<int> p(n);\n    iota(p.begin(),\
    \ p.end(), 0);\n    for (int i = 0; i < n; i++) {\n        if (i == pinv[i]) continue;\n\
    \        int k = -1;\n        for (int j = i + 1; j < n; j++) {\n            if\
    \ (pinv[j] == i) k = j;\n        }\n        swap(p[i], p[k]);\n        swap(pinv[i],\
    \ pinv[k]);\n    }\n    return make_pair(p, a);\n}\n\nconstexpr inline bool _is_zero(long\
    \ double x) { return abs(x) < 1e-8; }\nconstexpr inline bool _is_zero(double x)\
    \ { return abs(x) < 1e-8; }\ntemplate <int MOD>\nconstexpr inline bool _is_zero(const\
    \ ModInt<MOD> &x) { return x.x == 0; }\ntemplate <typename T>\nconstexpr inline\
    \ bool _is_zero(T x) { return x == T(0); }\n\n// solve\n// PA = LU\u3092\u7528\
    \u3044\u3066Ax = b\u306A\u308B\u9023\u7ACB\u65B9\u7A0B\u5F0F\u3092\u3068\u304F\
    .\n// \u3082\u3057\u89E3\u304C\u5B58\u5728\u3057\u306A\u3051\u308C\u3070{}\u3092\
    \u8FD4\u3059. \u89E3\u304C\u5C11\u306A\u304F\u3068\u3082\u4E00\u3064\u5B58\u5728\
    \u3059\u308C\u3070\u305D\u306E\u4E00\u3064\u3092\u8FD4\u3059.\n// \u8A08\u7B97\
    \u91CF: O(n^2)\ntemplate <typename T>\nvector<T> solve(vector<int> p, const Matrix<T>\
    \ &lu, vector<T> b) {\n    int n = (int)lu.size();\n    for (int i = 0; i < n;\
    \ i++) {\n        if (i == p[i]) continue;\n        int k = -1;\n        for (int\
    \ j = i + 1; j < n; j++) {\n            if (p[j] == i) k = j;\n        }\n   \
    \     swap(p[i], p[k]);\n        swap(b[i], b[k]);\n    }\n    for (int i = 0;\
    \ i < n; i++)\n        for (int j = 0; j < i; j++)\n            b[i] -= b[j] *\
    \ lu[i][j];\n    for (int i = n - 1; i >= 0; i--) {\n        for (int j = i +\
    \ 1; j < n; j++)\n            b[i] -= b[j] * lu[i][j];\n        if (_is_zero(lu[i][i])\
    \ && !_is_zero(b[i]))\n            return {}; // \u89E3\u306A\u3057\n        else\
    \ if (!_is_zero(lu[i][i]))\n            b[i] /= lu[i][i];\n    }\n    return b;\n\
    }\n\n// solve\n// Ax = b\u306A\u308B\u9023\u7ACB\u65B9\u7A0B\u5F0F\u3092\u3068\
    \u304F.\n// \u3082\u3057\u89E3\u304C\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\
    {}\u3092\u8FD4\u3059. \u89E3\u304C\u5C11\u306A\u304F\u3068\u3082\u4E00\u3064\u5B58\
    \u5728\u3059\u308C\u3070\u305D\u306E\u4E00\u3064\u3092\u8FD4\u3059.\n// \u8A08\
    \u7B97\u91CF: O(n^3)\ntemplate <typename T>\nvector<T> solve(Matrix<T> A, vector<T>\
    \ b) {\n    assert(A.size() == A[0].size());\n    auto [p, lu] = lu_decomposition(A);\n\
    \    return solve(p, lu, b);\n}\n\n// _det\n// lu\u5206\u89E3\u3055\u308C\u305F\
    \u884C\u5217\u306E\u884C\u5217\u5F0F\u3092\u6C42\u3081\u308B.\n// \u8A08\u7B97\
    \u91CF: O(n)\ntemplate <typename T>\nT _det(const Matrix<T> &lu) {\n    T ans\
    \ = T(1);\n    for (int i = 0; i < (int)lu.size(); i++)\n        ans *= lu[i][i];\n\
    \    return ans;\n}\n\n// det\n// \u884C\u5217\u306E\u884C\u5217\u5F0F\u3092\u6C42\
    \u3081\u308B.\n// \u8A08\u7B97\u91CF: O(n^3)\ntemplate <typename T>\nT det(Matrix<T>\
    \ A) {\n    auto [_, lu] = lu_decomposition(A);\n    return _det(lu);\n}\n\n//\
    \ _rank\n// lu\u5206\u89E3\u3055\u308C\u305F\u884C\u5217\u306E\u30E9\u30F3\u30AF\
    \u3092\u6C42\u3081\u308B.\n// \u8A08\u7B97\u91CF: O(n)\ntemplate <typename T>\n\
    int _rank(const Matrix<T> &lu) {\n    int ans = (int)lu.size();\n    for (int\
    \ i = 0; i < (int)lu.size(); i++)\n        if (_is_zero(lu[i][i])) ans--;\n  \
    \  return ans;\n}\n\n// rank\n// \u884C\u5217\u306E\u30E9\u30F3\u30AF\u3092\u6C42\
    \u3081\u308B.\n// \u8A08\u7B97\u91CF: O(n^3)\ntemplate <typename T>\nint rank(Matrix<T>\
    \ A) {\n    auto [_, lu] = lu_decomposition(A);\n    return _rank(lu);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"mint.cpp\"\n\ntemplate <typename T>\nusing Matrix = vector<vector<T>>;\n\n\
    template <typename T>\nMatrix<T> mul(const Matrix<T> &a, const Matrix<T> &b) {\n\
    \    assert(a[0].size() == b.size());\n    Matrix<T> c(a.size(), vector<T>(b[0].size()));\n\
    \    for (int i = 0; i < (int)a.size(); i++) {\n        for (int j = 0; j < (int)a[0].size();\
    \ j++) {\n            for (int k = 0; k < (int)b[0].size(); k++) {\n         \
    \       c[i][k] += a[i][j] * b[j][k];\n            }\n        }\n    }\n    return\
    \ c;\n}\n\ntemplate <typename T>\nvector<T> mul(const Matrix<T> &a, const vector<T>\
    \ &b) {\n    assert(a[0].size() == b.size());\n    vector<T> ans(a.size(), 0);\n\
    \    for (int i = 0; i < (int)a.size(); i++) {\n        for (int j = 0; j < (int)a[0].size();\
    \ j++) {\n            ans[i] += a[i][j] * b[j];\n        }\n    }\n    return\
    \ ans;\n}\n\ntemplate <typename T, typename U>\nMatrix<T> pow(Matrix<T> a, U n)\
    \ {\n    assert(a.size() == a[0].size());\n    int m = (int)a.size();\n    Matrix<T>\
    \ ans(m, vector<T>(m, 0));\n    for (int i = 0; i < m; i++)\n        ans[i][i]\
    \ = 1;\n    while (n > 0) {\n        if (n & 1) {\n            ans = mul(ans,\
    \ a);\n        }\n        a = mul(a, a);\n        n >>= 1;\n    }\n    return\
    \ ans;\n}\n\ntemplate <int MOD>\nint _find_pivot(const Matrix<ModInt<MOD>> &a,\
    \ int i) {\n    for (int j = i; j < (int)a[i].size(); j++) {\n        if (a[j][i].x\
    \ != 0) return j;\n    }\n    return -1;\n}\n\ntemplate <typename T>\nint _find_pivot(const\
    \ Matrix<T> &a, int i) {\n    int pivot = -1;\n    T val     = T(0);\n    for\
    \ (int j = i; j < (int)a[i].size(); j++) {\n        if (abs(a[j][i]) > val) {\n\
    \            val   = abs(a[j][i]);\n            pivot = j;\n        }\n    }\n\
    \    return pivot;\n}\n\n// lu_decomposition\n// PA = LU\u306A\u308B\u5206\u89E3\
    \u3092\u3059\u308B. \u305F\u3060\u3057, P\u306F\u7F6E\u63DB\u884C\u5217, L\u306F\
    \u5BFE\u89D2\u6210\u5206\u304C1\u306E\u4E0B\u4E09\u89D2\u884C\u5217, U\u306F\u4E0A\
    \u4E09\u89D2\u884C\u5217.\n// \u7F6E\u63DBP\u3068L,U\u3092\u8A70\u3081\u305F\u884C\
    \u5217\u3092\u8FD4\u3059. A\u304C\u6B63\u5247\u3067\u306F\u306A\u3044\u5834\u5408\
    , U\u306E\u5BFE\u89D2\u6210\u5206\u306B0\u304C\u542B\u307E\u308C\u308B.\n// \u8A08\
    \u7B97\u91CF: O(n^3)\ntemplate <typename T>\npair<vector<int>, Matrix<T>> lu_decomposition(Matrix<T>\
    \ a) {\n    assert(a.size() == a[0].size());\n    int n = (int)a.size();\n   \
    \ vector<int> pinv(n);\n    iota(pinv.begin(), pinv.end(), 0);\n    for (int i\
    \ = 0; i < n; i++) {\n        int pivot = _find_pivot(a, i);\n        if (pivot\
    \ < 0) continue;\n        swap(a[i], a[pivot]), swap(pinv[i], pinv[pivot]);\n\
    \        for (int j = i + 1; j < n; j++) {\n            a[j][i] /= a[i][i];\n\
    \            for (int k = i + 1; k < n; k++) {\n                a[j][k] -= a[i][k]\
    \ * a[j][i];\n            }\n        }\n    }\n    vector<int> p(n);\n    iota(p.begin(),\
    \ p.end(), 0);\n    for (int i = 0; i < n; i++) {\n        if (i == pinv[i]) continue;\n\
    \        int k = -1;\n        for (int j = i + 1; j < n; j++) {\n            if\
    \ (pinv[j] == i) k = j;\n        }\n        swap(p[i], p[k]);\n        swap(pinv[i],\
    \ pinv[k]);\n    }\n    return make_pair(p, a);\n}\n\nconstexpr inline bool _is_zero(long\
    \ double x) { return abs(x) < 1e-8; }\nconstexpr inline bool _is_zero(double x)\
    \ { return abs(x) < 1e-8; }\ntemplate <int MOD>\nconstexpr inline bool _is_zero(const\
    \ ModInt<MOD> &x) { return x.x == 0; }\ntemplate <typename T>\nconstexpr inline\
    \ bool _is_zero(T x) { return x == T(0); }\n\n// solve\n// PA = LU\u3092\u7528\
    \u3044\u3066Ax = b\u306A\u308B\u9023\u7ACB\u65B9\u7A0B\u5F0F\u3092\u3068\u304F\
    .\n// \u3082\u3057\u89E3\u304C\u5B58\u5728\u3057\u306A\u3051\u308C\u3070{}\u3092\
    \u8FD4\u3059. \u89E3\u304C\u5C11\u306A\u304F\u3068\u3082\u4E00\u3064\u5B58\u5728\
    \u3059\u308C\u3070\u305D\u306E\u4E00\u3064\u3092\u8FD4\u3059.\n// \u8A08\u7B97\
    \u91CF: O(n^2)\ntemplate <typename T>\nvector<T> solve(vector<int> p, const Matrix<T>\
    \ &lu, vector<T> b) {\n    int n = (int)lu.size();\n    for (int i = 0; i < n;\
    \ i++) {\n        if (i == p[i]) continue;\n        int k = -1;\n        for (int\
    \ j = i + 1; j < n; j++) {\n            if (p[j] == i) k = j;\n        }\n   \
    \     swap(p[i], p[k]);\n        swap(b[i], b[k]);\n    }\n    for (int i = 0;\
    \ i < n; i++)\n        for (int j = 0; j < i; j++)\n            b[i] -= b[j] *\
    \ lu[i][j];\n    for (int i = n - 1; i >= 0; i--) {\n        for (int j = i +\
    \ 1; j < n; j++)\n            b[i] -= b[j] * lu[i][j];\n        if (_is_zero(lu[i][i])\
    \ && !_is_zero(b[i]))\n            return {}; // \u89E3\u306A\u3057\n        else\
    \ if (!_is_zero(lu[i][i]))\n            b[i] /= lu[i][i];\n    }\n    return b;\n\
    }\n\n// solve\n// Ax = b\u306A\u308B\u9023\u7ACB\u65B9\u7A0B\u5F0F\u3092\u3068\
    \u304F.\n// \u3082\u3057\u89E3\u304C\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\
    {}\u3092\u8FD4\u3059. \u89E3\u304C\u5C11\u306A\u304F\u3068\u3082\u4E00\u3064\u5B58\
    \u5728\u3059\u308C\u3070\u305D\u306E\u4E00\u3064\u3092\u8FD4\u3059.\n// \u8A08\
    \u7B97\u91CF: O(n^3)\ntemplate <typename T>\nvector<T> solve(Matrix<T> A, vector<T>\
    \ b) {\n    assert(A.size() == A[0].size());\n    auto [p, lu] = lu_decomposition(A);\n\
    \    return solve(p, lu, b);\n}\n\n// _det\n// lu\u5206\u89E3\u3055\u308C\u305F\
    \u884C\u5217\u306E\u884C\u5217\u5F0F\u3092\u6C42\u3081\u308B.\n// \u8A08\u7B97\
    \u91CF: O(n)\ntemplate <typename T>\nT _det(const Matrix<T> &lu) {\n    T ans\
    \ = T(1);\n    for (int i = 0; i < (int)lu.size(); i++)\n        ans *= lu[i][i];\n\
    \    return ans;\n}\n\n// det\n// \u884C\u5217\u306E\u884C\u5217\u5F0F\u3092\u6C42\
    \u3081\u308B.\n// \u8A08\u7B97\u91CF: O(n^3)\ntemplate <typename T>\nT det(Matrix<T>\
    \ A) {\n    auto [_, lu] = lu_decomposition(A);\n    return _det(lu);\n}\n\n//\
    \ _rank\n// lu\u5206\u89E3\u3055\u308C\u305F\u884C\u5217\u306E\u30E9\u30F3\u30AF\
    \u3092\u6C42\u3081\u308B.\n// \u8A08\u7B97\u91CF: O(n)\ntemplate <typename T>\n\
    int _rank(const Matrix<T> &lu) {\n    int ans = (int)lu.size();\n    for (int\
    \ i = 0; i < (int)lu.size(); i++)\n        if (_is_zero(lu[i][i])) ans--;\n  \
    \  return ans;\n}\n\n// rank\n// \u884C\u5217\u306E\u30E9\u30F3\u30AF\u3092\u6C42\
    \u3081\u308B.\n// \u8A08\u7B97\u91CF: O(n^3)\ntemplate <typename T>\nint rank(Matrix<T>\
    \ A) {\n    auto [_, lu] = lu_decomposition(A);\n    return _rank(lu);\n}"
  dependsOn:
  - math/mint.cpp
  isVerificationFile: false
  path: math/matrix.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.cpp
layout: document
redirect_from:
- /library/math/matrix.cpp
- /library/math/matrix.cpp.html
title: math/matrix.cpp
---
