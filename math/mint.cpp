#pragma once
#include <bits/stdc++.h>
using namespace std;

template <int MOD>
struct ModInt {
  public:
    long long x;
    ModInt(long long x = 0) : x((x % MOD + MOD) % MOD) {}
    constexpr ModInt &operator+=(const ModInt a) noexcept {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt a) noexcept {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt a) noexcept {
        (x *= a.x) %= MOD;
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt a) noexcept { return *this *= a.inverse(); }

    constexpr ModInt operator+(const ModInt a) const noexcept { return ModInt(*this) += a.x; }
    constexpr ModInt operator-(const ModInt a) const noexcept { return ModInt(*this) -= a.x; }
    constexpr ModInt operator*(const ModInt a) const noexcept { return ModInt(*this) *= a.x; }
    constexpr ModInt operator/(const ModInt a) const noexcept { return ModInt(*this) /= a.x; }

    friend constexpr std::ostream &operator<<(std::ostream &os, const ModInt<MOD> a) noexcept { return os << a.x; }
    friend constexpr std::istream &operator>>(std::istream &is, ModInt<MOD> &a) noexcept {
        is >> a.x;
        a.x = (a.x % MOD + MOD) % MOD;
        return is;
    }

    ModInt inverse() const noexcept { // x ^ (-1)
        long long a = x, b = MOD, p = 1, q = 0;
        while (b) {
            long long d = a / b;
            a -= d * b;
            swap(a, b);
            p -= d * q;
            swap(p, q);
        }
        return ModInt(p);
    }
    ModInt pow(long long N) const noexcept { // x ^ N
        ModInt a = 1;
        ModInt y = this->x;
        while (N) {
            if (N & 1) a *= y;
            y *= y;
            N >>= 1;
        }
        return a;
    }
};

template <typename U, int MOD>
inline ModInt<MOD> operator*(const U &c, const ModInt<MOD> &a) { return {c * a.x}; }

using mint = ModInt<998244353>;