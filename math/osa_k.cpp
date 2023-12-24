#pragma once
#include <bits/stdc++.h>
using namespace std;

// OsaK
// n以下の整数の素因数分解を高速に行う.
// 制約: n >= 1
struct OsaK {
    int n;
    vector<int> smallest_prime_factor;

    OsaK(int n) : n(n) { smallest_prime_factor.assign(n + 1, -1); }

    // build
    // spf配列を用意する.
    // 計算量: O(nloglogn)
    void build() {
        long long i = 2;
        for (; i * i <= n; ++i) {
            if (smallest_prime_factor[i] < 0) {
                smallest_prime_factor[i] = i;
                for (long long p = i * i; p <= n; p += i) {
                    if (smallest_prime_factor[p] < 0)
                        smallest_prime_factor[p] = i;
                }
            }
        }
        for (int j = i; j <= n; ++j) {
            if (smallest_prime_factor[j] < 0) smallest_prime_factor[j] = j;
        }
    }

    // factorize
    // 整数mを素因数分解する
    // 制約: 1 <= m <= n
    // 計算量: O(logm)
    template <typename T> vector<pair<T, int>> factorize(T m) {
        vector<pair<T, int>> ans;
        while (m > 1) {
            int p = smallest_prime_factor[m], e = 1;
            m /= p;
            while (p == smallest_prime_factor[m]) {
                ++e;
                m /= p;
            }
            ans.emplace_back(p, e);
        }
        return ans;
    }

    // count_factor
    // 整数mの約数の数を数える.
    // 制約: 1 <= m <= n
    // 計算量: O(logm)
    template <typename T> long long count_factor(T m) {
        auto ret      = factorize(m);
        long long ans = 1;
        for (const auto &p : ret) {
            ans *= (p.second + 1);
        }
        return ans;
    }
};