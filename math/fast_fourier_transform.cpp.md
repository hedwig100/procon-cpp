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
  bundledCode: "#line 2 \"math/fast_fourier_transform.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"template/const.hpp\"\nconstexpr int INF      \
    \  = 1000'000'000;\nconstexpr long long HINF = 4000'000'000'000'000'000;\nconstexpr\
    \ long long MOD  = 998244353;\nconstexpr double EPS     = 1e-6;\nconstexpr double\
    \ PI      = 3.14159265358979;\n#line 3 \"math/mint.cpp\"\nusing namespace std;\n\
    \ntemplate <int MOD>\nstruct ModInt {\n  public:\n    long long x;\n    ModInt(long\
    \ long x = 0) : x((x % MOD + MOD) % MOD) {}\n    constexpr ModInt &operator+=(const\
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
    #line 6 \"math/fast_fourier_transform.cpp\"\n\nclass FastFourierTransform {\n\
    \  private:\n    inline static void fft(vector<complex<double>> &F) {\n      \
    \  int degree = F.size();\n        if (degree == 1) return;\n        vector<complex<double>>\
    \ even, odd;\n        for (int i = 0; i < degree / 2; i++) {\n            even.push_back(F[i\
    \ << 1]);\n            odd.push_back(F[i << 1 | 1]);\n        }\n        fft(even);\n\
    \        fft(odd);\n        complex<double> x = 1, zeta = polar(1.0, 2 * PI /\
    \ degree);\n        for (int i = 0; i < degree; i++) {\n            F[i] = even[i\
    \ % (degree / 2)] + x * odd[i % (degree / 2)];\n            x *= zeta;\n     \
    \   }\n    }\n\n    inline static void ifft(vector<complex<double>> &F) {\n  \
    \      int degree = F.size();\n        if (degree == 1) return;\n        vector<complex<double>>\
    \ even, odd;\n        for (int i = 0; i < degree / 2; i++) {\n            even.push_back(F[i\
    \ << 1]);\n            odd.push_back(F[i << 1 | 1]);\n        }\n        ifft(even);\n\
    \        ifft(odd);\n        complex<double> x = 1, zeta = polar(1.0, -2 * PI\
    \ / degree);\n        for (int i = 0; i < degree; i++) {\n            F[i] = even[i\
    \ % (degree / 2)] + x * odd[i % (degree / 2)];\n            x *= zeta;\n     \
    \   }\n    }\n\n  public:\n    template <class T>\n    inline static vector<double>\
    \ multiply(vector<T> F, vector<T> G) {\n        int degree = 1;\n        while\
    \ (degree < F.size() + G.size() - 1)\n            degree *= 2;\n        vector<complex<double>>\
    \ nF(degree, 0), nG(degree, 0);\n        for (int i = 0; i < F.size(); i++)\n\
    \            nF[i] = F[i];\n        for (int i = 0; i < G.size(); i++)\n     \
    \       nG[i] = G[i];\n        fft(nF);\n        fft(nG);\n        for (int i\
    \ = 0; i < degree; i++) {\n            nF[i] *= nG[i];\n        }\n        ifft(nF);\n\
    \        vector<double> ret(degree);\n        for (int i = 0; i < degree; i++)\
    \ {\n            ret[i] = nF[i].real() / degree;\n        }\n        return ret;\n\
    \    }\n};\n\n//\u975E\u518D\u5E30\u3067\u304D\u305F\u306F\u3084\u3044\n\nclass\
    \ FastFourierTransform {\n  private:\n    inline static void fft(vector<complex<double>>\
    \ &F, bool inverse, int bit_len) {\n        int degree = F.size();\n        for\
    \ (int i = 0; i < degree; i++) {\n            int j = 0;\n            for (int\
    \ k = 0; k < bit_len; k++)\n                j |= (i >> k & 1) << (bit_len - k\
    \ - 1);\n            if (i < j) swap(F[i], F[j]);\n        }\n        for (int\
    \ b = 1; b < degree; b <<= 1) {\n            complex<double> x = 1, zeta = polar(1.0,\
    \ PI / b * (inverse ? 1 : -1));\n            for (int j = 0; j < b; j++) {\n \
    \               for (int k = 0; k < degree; k += (b << 1)) {\n               \
    \     complex<double> s = F[j + k], t = F[j + k + b] * x;\n                  \
    \  F[j + k]     = s + t;\n                    F[j + k + b] = s - t;\n        \
    \        }\n                x *= zeta;\n            }\n        }\n        if (inverse)\
    \ {\n            for (int i = 0; i < degree; i++)\n                F[i] /= degree;\n\
    \        }\n    }\n\n  public:\n    template <class T>\n    inline static vector<long\
    \ long> multiply(vector<T> &F, vector<T> &G) {\n        int s      = F.size()\
    \ + G.size() - 1;\n        int degree = 1, bit_len = 0;\n        while (degree\
    \ < s)\n            degree <<= 1, bit_len++;\n        vector<complex<double>>\
    \ nF(degree, 0), nG(degree, 0);\n        for (int i = 0; i < F.size(); i++)\n\
    \            nF[i] = F[i];\n        for (int i = 0; i < G.size(); i++)\n     \
    \       nG[i] = G[i];\n        fft(nF, false, bit_len);\n        fft(nG, false,\
    \ bit_len);\n        for (int i = 0; i < degree; i++)\n            nF[i] *= nG[i];\n\
    \        fft(nF, true, bit_len);\n        vector<long long> ret(s);\n        for\
    \ (int i = 0; i < s; i++)\n            ret[i] = (long long)(nF[i].real() + 0.5);\n\
    \        return ret;\n    }\n};\n\nstruct NumberTheoreticalTransform {\n    const\
    \ int premitive_root = 3; // primitive root of 998244353\n    const int MOD  \
    \          = 998244353;\n    NumberTheoreticalTransform() {}\n    inline void\
    \ ntt(vector<mint> &F, bool inverse, int bit_len) {\n        int degree = F.size();\n\
    \        for (int i = 0; i < degree; i++) {\n            int j = 0;\n        \
    \    for (int k = 0; k < bit_len; k++)\n                j |= (i >> k & 1) << (bit_len\
    \ - k - 1);\n            if (i < j) swap(F[i], F[j]);\n        }\n        for\
    \ (int b = 1; b < degree; b <<= 1) {\n            mint x = 1, zeta = mint(premitive_root).pow((MOD\
    \ - 1) / (b << 1));\n            if (inverse) zeta = zeta.inverse();\n       \
    \     for (int j = 0; j < b; ++j) {\n                for (int k = 0; k < degree;\
    \ k += (b << 1)) {\n                    mint s = F[j + k], t = F[j + k + b] *\
    \ x;\n                    F[j + k]     = s + t;\n                    F[j + k +\
    \ b] = s - t;\n                }\n                x *= zeta;\n            }\n\
    \        }\n        if (inverse) {\n            mint inv = mint(degree).inverse();\n\
    \            for (int i = 0; i < degree; i++)\n                F[i] *= inv;\n\
    \        }\n    }\n    inline vector<mint> multiply(vector<mint> &F, vector<mint>\
    \ &G) {\n        int s      = F.size() + G.size() - 1;\n        int degree = 1,\
    \ bit_len = 0;\n        while (degree < s)\n            degree <<= 1, bit_len++;\n\
    \        vector<mint> nF(degree, 0), nG(degree, 0);\n        for (int i = 0; i\
    \ < F.size(); i++)\n            nF[i] = F[i];\n        for (int i = 0; i < G.size();\
    \ i++)\n            nG[i] = G[i];\n        ntt(nF, false, bit_len);\n        ntt(nG,\
    \ false, bit_len);\n        for (int i = 0; i < degree; i++)\n            nF[i]\
    \ *= nG[i];\n        ntt(nF, true, bit_len);\n        return nF;\n    }\n} ntt;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n#include \"\
    ../template/const.hpp\"\n#include \"./mint.cpp\"\n\nclass FastFourierTransform\
    \ {\n  private:\n    inline static void fft(vector<complex<double>> &F) {\n  \
    \      int degree = F.size();\n        if (degree == 1) return;\n        vector<complex<double>>\
    \ even, odd;\n        for (int i = 0; i < degree / 2; i++) {\n            even.push_back(F[i\
    \ << 1]);\n            odd.push_back(F[i << 1 | 1]);\n        }\n        fft(even);\n\
    \        fft(odd);\n        complex<double> x = 1, zeta = polar(1.0, 2 * PI /\
    \ degree);\n        for (int i = 0; i < degree; i++) {\n            F[i] = even[i\
    \ % (degree / 2)] + x * odd[i % (degree / 2)];\n            x *= zeta;\n     \
    \   }\n    }\n\n    inline static void ifft(vector<complex<double>> &F) {\n  \
    \      int degree = F.size();\n        if (degree == 1) return;\n        vector<complex<double>>\
    \ even, odd;\n        for (int i = 0; i < degree / 2; i++) {\n            even.push_back(F[i\
    \ << 1]);\n            odd.push_back(F[i << 1 | 1]);\n        }\n        ifft(even);\n\
    \        ifft(odd);\n        complex<double> x = 1, zeta = polar(1.0, -2 * PI\
    \ / degree);\n        for (int i = 0; i < degree; i++) {\n            F[i] = even[i\
    \ % (degree / 2)] + x * odd[i % (degree / 2)];\n            x *= zeta;\n     \
    \   }\n    }\n\n  public:\n    template <class T>\n    inline static vector<double>\
    \ multiply(vector<T> F, vector<T> G) {\n        int degree = 1;\n        while\
    \ (degree < F.size() + G.size() - 1)\n            degree *= 2;\n        vector<complex<double>>\
    \ nF(degree, 0), nG(degree, 0);\n        for (int i = 0; i < F.size(); i++)\n\
    \            nF[i] = F[i];\n        for (int i = 0; i < G.size(); i++)\n     \
    \       nG[i] = G[i];\n        fft(nF);\n        fft(nG);\n        for (int i\
    \ = 0; i < degree; i++) {\n            nF[i] *= nG[i];\n        }\n        ifft(nF);\n\
    \        vector<double> ret(degree);\n        for (int i = 0; i < degree; i++)\
    \ {\n            ret[i] = nF[i].real() / degree;\n        }\n        return ret;\n\
    \    }\n};\n\n//\u975E\u518D\u5E30\u3067\u304D\u305F\u306F\u3084\u3044\n\nclass\
    \ FastFourierTransform {\n  private:\n    inline static void fft(vector<complex<double>>\
    \ &F, bool inverse, int bit_len) {\n        int degree = F.size();\n        for\
    \ (int i = 0; i < degree; i++) {\n            int j = 0;\n            for (int\
    \ k = 0; k < bit_len; k++)\n                j |= (i >> k & 1) << (bit_len - k\
    \ - 1);\n            if (i < j) swap(F[i], F[j]);\n        }\n        for (int\
    \ b = 1; b < degree; b <<= 1) {\n            complex<double> x = 1, zeta = polar(1.0,\
    \ PI / b * (inverse ? 1 : -1));\n            for (int j = 0; j < b; j++) {\n \
    \               for (int k = 0; k < degree; k += (b << 1)) {\n               \
    \     complex<double> s = F[j + k], t = F[j + k + b] * x;\n                  \
    \  F[j + k]     = s + t;\n                    F[j + k + b] = s - t;\n        \
    \        }\n                x *= zeta;\n            }\n        }\n        if (inverse)\
    \ {\n            for (int i = 0; i < degree; i++)\n                F[i] /= degree;\n\
    \        }\n    }\n\n  public:\n    template <class T>\n    inline static vector<long\
    \ long> multiply(vector<T> &F, vector<T> &G) {\n        int s      = F.size()\
    \ + G.size() - 1;\n        int degree = 1, bit_len = 0;\n        while (degree\
    \ < s)\n            degree <<= 1, bit_len++;\n        vector<complex<double>>\
    \ nF(degree, 0), nG(degree, 0);\n        for (int i = 0; i < F.size(); i++)\n\
    \            nF[i] = F[i];\n        for (int i = 0; i < G.size(); i++)\n     \
    \       nG[i] = G[i];\n        fft(nF, false, bit_len);\n        fft(nG, false,\
    \ bit_len);\n        for (int i = 0; i < degree; i++)\n            nF[i] *= nG[i];\n\
    \        fft(nF, true, bit_len);\n        vector<long long> ret(s);\n        for\
    \ (int i = 0; i < s; i++)\n            ret[i] = (long long)(nF[i].real() + 0.5);\n\
    \        return ret;\n    }\n};\n\nstruct NumberTheoreticalTransform {\n    const\
    \ int premitive_root = 3; // primitive root of 998244353\n    const int MOD  \
    \          = 998244353;\n    NumberTheoreticalTransform() {}\n    inline void\
    \ ntt(vector<mint> &F, bool inverse, int bit_len) {\n        int degree = F.size();\n\
    \        for (int i = 0; i < degree; i++) {\n            int j = 0;\n        \
    \    for (int k = 0; k < bit_len; k++)\n                j |= (i >> k & 1) << (bit_len\
    \ - k - 1);\n            if (i < j) swap(F[i], F[j]);\n        }\n        for\
    \ (int b = 1; b < degree; b <<= 1) {\n            mint x = 1, zeta = mint(premitive_root).pow((MOD\
    \ - 1) / (b << 1));\n            if (inverse) zeta = zeta.inverse();\n       \
    \     for (int j = 0; j < b; ++j) {\n                for (int k = 0; k < degree;\
    \ k += (b << 1)) {\n                    mint s = F[j + k], t = F[j + k + b] *\
    \ x;\n                    F[j + k]     = s + t;\n                    F[j + k +\
    \ b] = s - t;\n                }\n                x *= zeta;\n            }\n\
    \        }\n        if (inverse) {\n            mint inv = mint(degree).inverse();\n\
    \            for (int i = 0; i < degree; i++)\n                F[i] *= inv;\n\
    \        }\n    }\n    inline vector<mint> multiply(vector<mint> &F, vector<mint>\
    \ &G) {\n        int s      = F.size() + G.size() - 1;\n        int degree = 1,\
    \ bit_len = 0;\n        while (degree < s)\n            degree <<= 1, bit_len++;\n\
    \        vector<mint> nF(degree, 0), nG(degree, 0);\n        for (int i = 0; i\
    \ < F.size(); i++)\n            nF[i] = F[i];\n        for (int i = 0; i < G.size();\
    \ i++)\n            nG[i] = G[i];\n        ntt(nF, false, bit_len);\n        ntt(nG,\
    \ false, bit_len);\n        for (int i = 0; i < degree; i++)\n            nF[i]\
    \ *= nG[i];\n        ntt(nF, true, bit_len);\n        return nF;\n    }\n} ntt;\n"
  dependsOn:
  - math/mint.cpp
  isVerificationFile: false
  path: math/fast_fourier_transform.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fast_fourier_transform.cpp
layout: document
redirect_from:
- /library/math/fast_fourier_transform.cpp
- /library/math/fast_fourier_transform.cpp.html
title: math/fast_fourier_transform.cpp
---
