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
    friend constexpr std::istream &operator>>(std::istream &is, ModInt<MOD> &a) noexcept { return is >> a.x; }

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

//  verified:
//     https://atcoder.jp/contests/abc246/tasks/abc246_f

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);

    int n, l;
    std::cin >> n >> l;
    std::vector<std::string> tw(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tw[i];
    }

    mint ans = 0;
    for (int s = 0; s < (1 << n); s++) {
        if (s == 0) continue;
        std::vector<int> alpha(26, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((s >> i) & 1) {
                cnt++;
                for (int j = 0; j < (int)tw[i].size(); j++)
                    alpha[tw[i][j] - 'a'] += 1;
            }
        }
        mint ret = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt == alpha[i])
                ret += 1;
        }
        if (cnt % 2 == 1)
            ans += ret.pow(l);
        else
            ans -= ret.pow(l);
    }
    std::cout << ans << '\n';
    return 0;
}