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

int sample() {
    std::vector<int> f = {0, 1, 3, 24, 4, 2, 4, 4, 2, 1};

    // a <= b
    ZetaOrder<int> zt1;
    printf("before\n");
    for (int i = 0; i < (int)f.size(); i++) {
        printf("%d ", f[i]);
    }
    printf("\n");

    zt1.zeta(f);
    printf("transform\n");
    for (int i = 0; i < (int)f.size(); i++) {
        printf("%d ", f[i]);
    }
    printf("\n");

    zt1.mebius(f);
    printf("return\n");
    for (int i = 0; i < (int)f.size(); i++) {
        printf("%d ", f[i]);
    }
    printf("\n");

    // S \subset T
    ZetaSubset<int> zt2;
    printf("before\n");
    for (int i = 0; i < (int)f.size(); i++) {
        printf("%d ", f[i]);
    }
    printf("\n");

    zt2.zeta(f);
    printf("transform\n");
    for (int i = 0; i < (int)f.size(); i++) {
        printf("%d ", f[i]);
    }
    printf("\n");

    zt2.mebius(f);
    printf("return\n");
    for (int i = 0; i < (int)f.size(); i++) {
        printf("%d ", f[i]);
    }
    printf("\n");

    // b | a
    ZetaDiv<int> zt3;
    printf("before\n");
    for (int i = 0; i < (int)f.size(); i++) {
        printf("%d ", f[i]);
    }
    printf("\n");

    zt3.zeta(f);
    printf("transform\n");
    for (int i = 0; i < (int)f.size(); i++) {
        printf("%d ", f[i]);
    }
    printf("\n");

    zt3.mebius(f);
    printf("return\n");
    for (int i = 0; i < (int)f.size(); i++) {
        printf("%d ", f[i]);
    }
    printf("\n");
    return 0;
}

/*
    https://yukicoder.me/problems/no/886
*/

template <int Modulus>
struct ModInt {
    long long x;
    ModInt(long long x = 0) : x((x % Modulus + Modulus) % Modulus) {}
    constexpr ModInt &operator+=(const ModInt a) {
        if ((x += a.x) >= Modulus) x -= Modulus;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt a) {
        if ((x += Modulus - a.x) >= Modulus) x -= Modulus;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt a) {
        (x *= a.x) %= Modulus;
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt a) { return *this *= a.inverse(); }

    constexpr ModInt operator+(const ModInt a) const { return ModInt(*this) += a.x; }
    constexpr ModInt operator-(const ModInt a) const { return ModInt(*this) -= a.x; }
    constexpr ModInt operator*(const ModInt a) const { return ModInt(*this) *= a.x; }
    constexpr ModInt operator/(const ModInt a) const { return ModInt(*this) /= a.x; }

    friend constexpr std::ostream &operator<<(std::ostream &os, const ModInt<Modulus> &a) { return os << a.x; }
    friend constexpr std::istream &operator>>(std::istream &is, ModInt<Modulus> &a) { return is >> a.x; }

    ModInt inverse() const { // x ^ (-1)
        long long a = x, b = Modulus, p = 1, q = 0;
        while (b) {
            long long d = a / b;
            a -= d * b;
            std::swap(a, b);
            p -= d * q;
            std::swap(p, q);
        }
        return ModInt(p);
    }
    ModInt pow(long long N) { // x ^ N
        ModInt a = 1;
        while (N) {
            if (N & 1) a *= *this;
            *this *= *this;
            N >>= 1;
        }
        return a;
    }
};

using mint = ModInt<1000'000'007>;

int main() {
    int H, W;
    std::cin >> H >> W;

    mint ans = mint(H) * mint(W - 1) + mint(W) * mint(H - 1);

    std::vector<mint> f(H + 1, 0), g(W + 1, 0);
    for (int i = 1; i <= H; i++) {
        f[i] = H - i;
    }
    for (int i = 1; i <= W; i++) {
        g[i] = W - i;
    }

    ZetaDiv<mint> zt;
    auto h = zt.convolve(f, g);
    ans += h[1] * 2;
    std::cout << ans << '\n';
}