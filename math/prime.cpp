#pragma once
#include <bits/stdc++.h>
using namespace std;

// is_prime
// 整数nが素数かどうか判定する.
// 制約: n >= 1,
// 計算量: O(√n)
template <typename T> bool is_prime(T n) {
    for (T i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

// divisor
// 整数nの因数を列挙する.
// 制約: n >= 1
// 計算量: O(√nlogn)
template <typename T> vector<T> divisor(T n) {
    vector<T> ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != n / i) ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// prime_factor
// 整数nを素因数分解した結果を返す.
// 制約: n >= 1
// 計算量: O(√n)
template <typename T> vector<pair<T, int>> prime_factor(T n) {
    vector<pair<T, int>> ans;
    for (T i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        if (cnt > 0) ans.emplace_back(i, cnt);
    }
    if (n != 1) ans.emplace_back(n, 1);
    return ans;
}

// Eratosthenes
// n以下の整数が素数かどうか判定する
// 制約: n >= 1
struct Eratosthenes {

  private:
    int n;
    vector<int> is_primes, primes;

  public:
    Eratosthenes(int n) : n(n) { is_primes.assign(n + 1, 1); }

    // build
    // n以下の素数を全て返す
    // 計算量: O(nloglogn)
    vector<int> build() {
        is_primes[0] = is_primes[1] = 0;
        for (long long i = 2; i <= n; i++) {
            if (!is_primes[i]) continue;
            primes.push_back(i);
            for (long long j = i * i; j <= n; j += i) {
                is_primes[j] = 0;
            }
        }
        return primes;
    }

    // is_prime
    // 整数pが素数かどうか判定する
    // 制約: 1 <= p <= n
    bool is_prime(int p) { return is_primes[p]; }

    // factorize
    // 整数mを素因数分解する
    // 制約: 1 <= m <= n*n
    // 計算量: O(min{n,√m})
    template <typename T> vector<pair<T, int>> factorize(T m) {
        vector<pair<T, int>> ans;
        for (const int &p : primes) {
            if (p > m) break;
            int count = 0;
            while (m % p == 0) {
                count++;
                m /= p;
            }
            if (count > 0) ans.emplace_back(p, count);
        }
        if (m != 1) ans.emplace_back(m, 1);
        return ans;
    }
};