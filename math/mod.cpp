#include <bits/stdc++.h>
using namespace std;
#include "../template/const.hpp"
#include "./mint.cpp"

struct Combination {
    int N;
    // using mint = ModInt<1000000007>;
    // using mint = ModInt<998244353>;
    vector<mint> fact, ifact, invs;
    Combination(int N) : N(N) {
        fact.resize(N + 1);
        ifact.resize(N + 1);
        fact[0] = fact[1] = 1;
        ifact[0] = ifact[1] = 1;
        for (int i = 2; i < N + 1; ++i) {
            fact[i] = fact[i - 1] * i;
        }
        ifact[N] = fact[N].inverse();
        for (int i = N; i >= 1; --i) {
            ifact[i - 1] = ifact[i] * i;
        }
    }
    void invs_build() {
        invs.resize(N + 1);
        invs[1] = 1;
        for (int i = 2; i < N + 1; ++i)
            invs[i] = fact[i] * ifact[i - 1];
    }
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
    mint npk(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[n - k];
    }
};

mint nck_nbig(long long n, int k) {
    mint ans = 1;
    for (int i = 0; i < k; ++i)
        ans *= mint(n - i);
    for (int i = 1; i < k + 1; ++i)
        ans *= mint(i).inverse();
    return ans;
}

long long modpow(long long N, long long K, long long mod = MOD) {
    long long ret = 1;
    while (K > 0) {
        if (K & 1) {
            ret *= N;
            ret %= mod;
        }
        K >>= 1;
        N *= N;
        N %= mod;
    }
    return ret;
}

long long inverse(long long N, long long mod = MOD) {
    long long a = N, b = mod, p = 1, q = 0;
    while (b) {
        long long d = a / b;
        a -= d * b;
        swap(a, b);
        p -= d * q;
        swap(p, q);
    }
    return p;
}