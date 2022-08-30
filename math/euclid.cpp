#pragma once
#include <bits/stdc++.h>
using namespace std;

// gcd
// 非負整数a,bの最大公約数を求める.
// 制約: a,b >= 0
// 計算量: O(logmax(a,b))
template <typename T>
T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }

// lcm
// 非負整数a,bの最小公倍数を求める.
// 制約: a,b >= 0
// 計算量: O(logmax(a,b))
template <typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

// ext_gcd
// 拡張Euclidの互除法で非負整数a,bに対してax + by = gcd(a,b)を満たす整数x,yを求める.
// 出力される値は xy != 0 ならば |x| <= b,|y| <= a を満たす.
// 制約: a,b >= 0
// 計算量: O(logmax(a,b))
template <typename T>
pair<T, T> ext_gcd(T a, T b) {
    if (b == 0) {
        return make_pair(1, 0);
    }
    auto [x, y] = ext_gcd(b, a % b);
    return make_pair(y, x - a / b * y);
}