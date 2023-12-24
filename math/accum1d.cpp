#pragma once
#include <bits/stdc++.h>
using namespace std;

// Accum1D
// 1次元累積和を計算する構造体
// n: 配列の長さ
// m: インデックスの mod m ごとの累積和を計算する. m = 1で通常の累積和
template <typename T> struct Accum1D {
    int n, m;
    vector<T> A, cum;

    Accum1D(int n, int m = 1) : n(n), m(m) {
        A.assign(n, T(0));
        cum.assign(n + 1, T(0));
    }

    // build
    // dataをもとに累積和を計算する.
    // 計算量: O(n)
    // 制約: n = data.size()
    void build(const vector<T> &data) {
        A = data;
        for (int i = 0; i < n; i++) {
            cum[i + 1] = cum[max(i + 1 - m, 0)] + A[i];
        }
    }

    // sum
    // \sum_{(l <= i < r) and ( i ≡ k mod m )} A[i] を計算する.
    // 計算量: O(1)
    // 制約: 0 <= l <= r <= n,0 <= k < m
    T sum(int l, int r, int k = 0) {
        l = _calc_ind(l, k), r = _calc_ind(r, k);
        return cum[r + 1] - cum[l + 1];
    }

  private:
    // _calc_ind
    // 0 <= i < x かつ i ≡ k mod m を満たすiを返す.
    // そのようなiが存在しない場合は-1を返す.
    // 制約: 0 <= x,0 <= k < m
    int _calc_ind(int x, int k) {
        if (x <= k) return -1;
        return m * ((x - k) / m - int((x - k) % m == 0)) + k;
    }
};