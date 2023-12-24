#pragma once
#include <bits/stdc++.h>
using namespace std;

// BinaryIndexedTree
// 可換群Tについて以下の二つの操作が可能
//
// 1. A[0] + A[1] + ... + A[k] を求める.
// 2. A[k] += x と更新.
//
template <typename T> struct BinaryIndexedTree {
    int n, size;
    int power;
    vector<T> data;

    BinaryIndexedTree(int n) : n(n) {
        size = 1;
        while (size < n)
            size <<= 1;
        data.assign(size + 1, 0);
    }

    // build
    // Aで初期化
    void build(const vector<T> &A) {
        for (int i = 0; i < n; ++i)
            add(i, A[i]);
    }

    // add
    // A[k]にxを加える.
    // 制約: 0 <= k < n
    // 計算量: O(logn)
    void add(int k, T x) {
        for (int i = ++k; i <= n; i += (i & -i)) {
            data[i] += x;
        }
    }

    // sum
    // Σ_{0 <= i <= k} A[i]を求める.
    // 制約: 0 <= k < n (それ以外は0を返す)
    // 計算量: O(logn)
    T sum(int k) {
        if (k < 0) return 0;
        k = min(k, n - 1);

        T ret = 0;
        for (int i = ++k; i > 0; i -= (i & -i)) {
            ret += data[i];
        }
        return ret;
    }

    // sum
    // Σ_{l <= i < r} A[i]を求める.
    // 制約: 0 <= l <= r <= N
    // 計算量: O(logN)
    T sum(int l, int r) { return sum(r - 1) - sum(l - 1); }

    // lower_bound
    // Σ_{0 <= i <= k} >= x を満たす最小のインデックスkを返す.
    // そのようなものが存在しなければnを返す. 制約: A[i] >= 0 計算量: O(logN)
    int lower_bound(T x) {
        int k = 0;
        for (int r = size; r > 0; r >>= 1) {
            if (k + r <= size && data[k + r] < x) {
                x -= data[k + r];
                k += r;
            }
        }
        return min(k, n);
    }
};