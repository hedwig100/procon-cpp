#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "euclid.cpp"

// pow_mod
// x^k mod mを計算する.
// 計算量: O(logk)
template <typename T> T pow_mod(T x, long long k, int m) {
    T ret = T(1);
    while (k > 0) {
        if (k & 1) {
            ret *= x;
            ret %= m;
        }
        k >>= 1;
        x *= x;
        x %= m;
    }
    return ret;
}

// inv_mod
// ax = 1 (mod m) なるx (0 <= x < m)が存在するならば
// それを返し, 存在しなければ-1を返す.
// 計算量: O(log|max(a,m)|)
template <typename T> T inv_mod(T a, T m) {
    auto [x, y] = ext_gcd(a, m);
    T g         = a * x + m * y;
    if (g != 1) return -1;
    return (m + x % m) % m;
}

// linear_congruence
// forall i,A_i x = B_i mod M_i <=> x = b mod m
// とかけるときに(b,m)の組を返す. ただし(0 <= b < m)をみたす.
// このように書けない時は(-1,-1)を返す. 計算量: O(nlogmax|M_i|),nは式の数
template <typename T>
pair<T, T> linear_congruence(const vector<T> &A, const vector<T> &B,
                             const vector<T> &M) {
    T x = 0, m = 1;
    for (int i = 0; i < (int)A.size(); i++) {
        T a = A[i] * m, b = B[i] - A[i] * x, d = gcd(M[i], a);
        if (b % d != 0) return make_pair(-1, -1);
        T t = b / d * inv_mod(a / d, M[i] / d) % (M[i] / d);
        x += m * t;
        m *= M[i] / d;
    }
    return make_pair((m + x % m) % m, m);
}

// garner
// forall i, x = R_i mod M_i <=> x = b mod m
// とかけるときに(b,m)の組を返す. ただし(0 <= b < m)をみたす.
// このように書けない時は(-1,-1)を返す. 計算量: O(nlogmax|M_i|),nは式の数
template <typename T>
pair<T, T> garner(const vector<T> &R, const vector<T> &M) {
    vector<T> A(R.size(), 1);
    return linear_congruence(A, R, M);
}

// aのk乗根を求める
long long root_int(long long a, int k) {
    if (k == 0) return 0;
    long long x = pow(a, (double)1.0 / k);
    while (pow(x, k) > a)
        x--;
    while (pow(x + 1, k) <= a)
        x++;
    return x;
}
