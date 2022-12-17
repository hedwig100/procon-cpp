#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "../template/const.hpp"
#include "./mint.cpp"

// Combination
// mod MODで階乗を計算しておくことでcomb(n,k)などをO(1)
// で計算する. MODはconstな素数
template <const int MOD>
struct Combination {
    using mint = ModInt<MOD>;
    int n;
    vector<mint> fact, ifact, invs;

    Combination(int n) : n(n) {
        fact.resize(n + 1);
        ifact.resize(n + 1);
        fact[0] = fact[1] = 1;
        ifact[0] = ifact[1] = 1;
        for (int i = 2; i <= n; ++i) {
            fact[i] = fact[i - 1] * i;
        }
        ifact[n] = fact[n].inverse();
        for (int i = n; i >= 1; --i) {
            ifact[i - 1] = ifact[i] * i;
        }
    }

    // invs_build
    // ax = 1 mod MODをみたすxをa=1,...,nについて計算する.
    // 計算量: O(n)
    void invs_build() {
        invs.resize(n + 1);
        invs[1] = 1;
        for (int i = 2; i <= n; ++i)
            invs[i] = fact[i] * ifact[i - 1];
    }

    // (n,k)
    // 0 <= k <= nなら nCk を返し, そうでないなら0を返す.
    // 制約: k,n整数
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }

    // npk
    // 0 <= k <= nなら nPk を返し, そうでないなら0を返す.
    // 制約: k,n整数
    mint npk(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[n - k];
    }
};

// nck_nbig
// nが大きい時にnCkを計算する
// 計算量: O(k)
template <const int MOD>
ModInt<MOD> nck_nbig(long long n, int k) {
    using mint = ModInt<MOD>;
    mint ans   = 1;
    for (int i = 0; i < k; ++i)
        ans *= mint(n - i);
    for (int i = 1; i < k + 1; ++i)
        ans *= mint(i).inverse();
    return ans;
}

// modpow
// x^y mod mを計算する
// 計算量: O(logy)
long long modpow(long long x, long long y, long long m) {
    long long ans = 1, tmp = x;
    while (y > 0) {
        if (y & 1) {
            ans = (ans * tmp) % m;
        }
        y >>= 1;
        tmp = (tmp * tmp) % m;
    }
    return ans;
}