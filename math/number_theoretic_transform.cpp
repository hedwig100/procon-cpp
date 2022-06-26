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

    friend std::ostream &operator<<(std::ostream &os, const ModInt<MOD> a) noexcept { return os << a.x; }
    friend std::istream &operator>>(std::istream &is, ModInt<MOD> &a) noexcept { return is >> a.x; }

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

using mint = ModInt<998244353>;

// NumberTheoreticTransform supports only F_998244353 as coefficient.
// recursive version
struct NumberTheoreticTransform {
  private:
    const mint ROOT = 3;
    const int MOD   = 998244353;

  public:
    NumberTheoreticTransform() {}

    // ntt caluculates y[i] = \sum_{j=0}^{n-1} x[j]r^{ij} where n is length of x and r is n-th root of 1 (mod n)
    // n must be power of two (n = 2^m)
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

    // multiply calculates f*g, when f[i] is coefficients of x^i (0-indexed) and g[i] is coefficients of x^i (0-indexed)
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

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<mint> A(n), B(m);
    for (int i = 0; i < n; i++)
        std::cin >> A[i];
    for (int i = 0; i < m; i++)
        std::cin >> B[i];

    NumberTheoreticTransform ntt;
    std::vector<mint> C = ntt.multiply(A, B);
    for (int i = 0; i < n + m - 1; i++) {
        std::cout << C[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}