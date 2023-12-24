#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "./mint.cpp"

// NumberTheoreticTransform supports only F_998244353 as coefficient.
// recursive version
struct NumberTheoreticTransform {
  private:
    const mint ROOT = 3;
    const int MOD   = 998244353;

  public:
    NumberTheoreticTransform() {}

    // ntt calculates y[i] = \sum_{j=0}^{n-1} x[j]r^{ij} where n is length of x
    // and r is n-th root of 1 (mod n) n must be power of two (n = 2^m)
    void ntt(int m, mint nth_root, std::vector<mint> &x) {
        if (m == 0) return;
        int n = (int)x.size();
        assert(n == (1 << m));

        int n_half = n / 2;
        std::vector<mint> x_e(n_half), x_o(n_half);
        for (int i = 0; i < n_half; i++) {
            x_e[i] = x[i << 1];
            x_o[i] = x[i << 1 | 1];
        }
        ntt(m - 1, nth_root * nth_root, x_e);
        ntt(m - 1, nth_root * nth_root, x_o);

        mint root_pow = 1;
        int mask      = n_half - 1;
        for (int i = 0; i < n; i++) {
            x[i] = x_e[i & mask] + root_pow * x_o[i & mask];
            root_pow *= nth_root;
        }
    }

    // multiply calculates f*g, when f[i] is coefficients of x^i (0-indexed) and
    // g[i] is coefficients of x^i (0-indexed)
    std::vector<mint> multiply(std::vector<mint> f, std::vector<mint> g) {
        int min_sz = (int)f.size() + (int)g.size() + 1;
        int m      = 0;
        while ((1 << m) < min_sz) {
            ++m;
        }
        int sz = 1 << m;
        f.resize(sz, (mint)0);
        g.resize(sz, (mint)0);
        assert((MOD - 1) % sz == 0);

        const mint nth_root = ROOT.pow((long long)(MOD - 1) / sz);
        ntt(m, nth_root, f);
        ntt(m, nth_root, g);

        std::vector<mint> h(sz);
        for (int i = 0; i < sz; i++) {
            h[i] = f[i] * g[i];
        }

        ntt(m, nth_root.inverse(), h);
        mint n_inv = mint(sz).inverse();
        for (int i = 0; i < sz; i++) {
            h[i] *= n_inv;
        }
        return h;
    }
};