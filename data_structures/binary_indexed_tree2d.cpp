#pragma once
#include <bits/stdc++.h>
using namespace std;

// BinaryIndexedTree2D
template <typename T>
struct BinaryIndexedTree2D {
    int h, w;
    vector<vector<T>> data;

    BinaryIndexedTree2D(int h, int w) : h(h), w(w) {
        data.assign(h + 1, std::vector<T>(w + 1, 0));
    }

    // add
    // A[k][l] += xとする.
    // 制約: 0 <= k < h,0 <= l < w
    // 計算量: O(loghlogw)
    void add(int k, int l, T x) {
        k++, l++;
        for (int i = k; i <= h; i += (i & -i)) {
            for (int j = l; j <= w; j += (j & -j)) {
                data[i][j] += x;
            }
        }
    }

    // _sum
    // Σ_{0 <= i <= k,0 <= j <= l} A[i][j]を求める.
    // 制約: 0 <= k < h,0 <= l < w
    // 計算量: O(loghlogw)
    T _sum(int k, int l) {
        if (k < 0 || l < 0) return 0;
        k = min(k, h - 1);
        l = min(l, w - 1);

        T ret = 0;
        k++, l++;
        for (int i = k; i > 0; i -= (i & -i)) {
            for (int j = l; j > 0; j -= (j & -j)) {
                ret += data[i][j];
            }
        }
        return ret;
    }

    // sum
    // Σ_{h1 <= i < h2 and w1 <= j < w2}A[i][j]を求める.
    // 制約: 0 <= h1 <= h2 <= h,0 <= w1 <= w2 <= w
    // 計算量: O(loghlogw)
    T sum(int h1, int h2, int w1, int w2) {
        return _sum(h2 - 1, w2 - 1) - _sum(h2 - 1, w1 - 1) - _sum(h1 - 1, w2 - 1) + _sum(h1 - 1, w1 - 1);
    }
};