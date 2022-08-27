#pragma once
#include <bits/stdc++.h>
using namespace std;

// TODO:refactor BinaryIndexedTree2D
// 1-indexed
template <class T>
struct BinaryIndexedTree2D {
    int H, W;
    std::vector<std::vector<T>> bit;
    BinaryIndexedTree2D(int H = 0, int W = 0) : H(H), W(W) {
        bit.assign(H + 1, std::vector<T>(W + 1, 0));
    }
    // add x to a[h][w]
    void add(int h, int w, T x) {
        for (int i = h; i <= H; i += (i & -i)) {
            for (int j = w; j <= W; j += (j & -j)) {
                bit[i][j] += x;
            }
        }
    }
    // return sum of a[i][j] s.t. (1 <= i <= h and 1 <= j <= w)
    T sum(int h, int w) {
        T ret = 0;
        for (int i = h; i > 0; i -= (i & -i)) {
            for (int j = w; j > 0; j -= (j & -j)) {
                ret += bit[i][j];
            }
        }
        return ret;
    }
    // return sum of a[i][j] s.t. (h1 <= i < h2 and w1 <= j < w2)
    T query(int h1, int h2, int w1, int w2) {
        return sum(h2 - 1, w2 - 1) - sum(h2 - 1, w1 - 1) - sum(h1 - 1, w2 - 1) + sum(h1 - 1, w1 - 1);
    }
};