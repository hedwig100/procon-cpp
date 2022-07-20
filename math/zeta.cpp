#include <bits/stdc++.h>
using namespace std;

// a <= b <=> a <= b
// g[x] = \\sum_{ i <= x } f[i]
template <class R>
struct ZetaOrder {
    // TODO:verify
  public:
    ZetaOrder() {}

    void zeta(std::vector<R> &f) {
        int sz = (int)f.size();
        for (int x = 1; x < sz; x++) {
            f[x] += f[x - 1];
        }
    }

    void mebius(std::vector<R> &f) {
        int sz = (int)f.size();
        for (int x = sz - 1; x >= 1; x--) {
            f[x] -= f[x - 1];
        }
    }

    std::vector<R> convolve(std::vector<R> f, std::vector<R> g) {
        int sz = std::max((int)f.size(), (int)g.size());
        f.resize(sz, 0);
        g.resize(sz, 0);
        zeta(f);
        zeta(g);
        std::vector<R> h(sz);
        for (int i = 0; i < sz; i++) {
            h[i] = f[i] * g[i];
        }
        mebius(h);
        return h;
    }
};

// min_pow2 returns minimum power of 2 larger than x (x <= 2^i)
// and i (pair{i,2^i}).
// x must be more than 0
template <class T>
std::pair<int, T> min_pow2(T x) {
    int i = 0;
    T ret = 1;
    while (x > ret) {
        i++;
        ret <<= 1;
    }
    return std::make_pair(i, ret);
}

// S <= T <=> S \subset T
// g[T] = \sum_{ S \subset T } f[S]
template <class R>
struct ZetaSubset {
    // TODO:verify
  private:
    // min_pow2 returns minimum power of 2 larger than x (x <= 2^i)
    // and i (pair{i,2^i}).
    // x must be more than 0
    std::pair<int, int> min_pow2(int x) {
        int i   = 0;
        int ret = 1;
        while (x > ret) {
            i++;
            ret <<= 1;
        }
        return std::make_pair(i, ret);
    }

  public:
    ZetaSubset() {}

    void zeta(std::vector<R> &f) {
        auto [d, sz] = min_pow2((int)f.size());
        f.resize(sz, (R)0);
        for (int i = 0; i < d; i++) {
            for (int T = 0; T < sz; T++) {
                if (T & (1 << i))
                    f[T] += f[T ^ (1 << i)];
            }
        }
    }

    void mebius(std::vector<R> &f) {
        auto [d, sz] = min_pow2((int)f.size());
        f.resize(sz, (R)0);
        for (int i = 0; i < d; i++) {
            for (int T = 0; T < sz; T++) {
                if (T & (1 << i))
                    f[T] -= f[T ^ (1 << i)];
            }
        }
    }

    std::vector<R> convolve(std::vector<R> f, std::vector<R> g) {
        int sz = std::max((int)f.size(), (int)g.size());
        f.resize(sz, 0);
        g.resize(sz, 0);
        zeta(f);
        zeta(g);
        std::vector<R> h(sz);
        for (int i = 0; i < sz; i++) {
            h[i] = f[i] * g[i];
        }
        mebius(h);
        return h;
    }
};

// a <= b <=> b | a
// g[x] = \sum_{ x | i } f[i]
template <class R>
struct ZetaDiv {
    // TODO: O(nloglogn) zeta transform
  private:
    // min_pow2 returns minimum power of 2 larger than x (x <= 2^i)
    // and i (pair{i,2^i}).
    // x must be more than 0
    std::pair<int, int> min_pow2(int x) {
        int i   = 0;
        int ret = 1;
        while (x > ret) {
            i++;
            ret <<= 1;
        }
        return std::make_pair(i, ret);
    }

  public:
    ZetaDiv() {}

    void zeta(std::vector<R> &f) {
        int sz = (int)f.size();
        for (int x = 1; x < sz; x++) {
            for (int i = 2 * x; i < sz; i += x) {
                f[x] += f[i];
            }
        }
    }

    void mebius(std::vector<R> &f) {
        int sz = (int)f.size();
        for (int x = sz - 1; x >= 1; x--) {
            for (int i = 2 * x; i < sz; i += x) {
                f[x] -= f[i];
            }
        }
    }

    std::vector<R> convolve(std::vector<R> f, std::vector<R> g) {
        int sz = std::min((int)f.size(), (int)g.size());
        zeta(f);
        zeta(g);
        std::vector<R> h(sz);
        for (int i = 0; i < sz; i++) {
            h[i] = f[i] * g[i];
        }
        mebius(h);
        return h;
    }
};