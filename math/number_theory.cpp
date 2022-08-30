#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "../template/const.hpp"
#include "euclid.cpp"

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

// inverse
template <typename T>
T modinv(T a, T MOD = MOD) {
    auto [x, y] = ext_gcd(a, MOD);

    T g = a * x + b * y;
    if (g != 1) return -1;
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}

// garner
long long garner(vector<long long> &R, vector<long long> &M) {
    long long x    = R[0] % M[0];
    long long prod = M[0];
    for (int i = 1; i < R.size(); i++) {
        long long t = ((R[i] - x) * modinv(prod, M[i])) % M[i];
        if (t < 0) t += M[i];
        x += t * prod;
        prod *= M[i];
    }
    return x;
}