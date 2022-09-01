#pragma once
#include <bits/stdc++.h>
using namespace std;

// SegmentTree
// Monはモノイド, すなわち *: Mon × Mon -> Monなる演算とe(単位元)があって,
// 以下を満たすもの.
// - e * a = a * e = a
// - a * (b * c) = (a * b) * c
//
// 以下の二つの操作ができる.
// 1. A[x]を更新する
// 2. A[l]*...*A[r-1] を計算する
template <typename Mon>
struct SegmentTree {
    using Fx = function<Mon(Mon, Mon)>;

    int n;
    vector<Mon> tree;
    Fx op;
    Mon e;

    SegmentTree(int n, Fx op, Mon e) : n(n), op(op), e(e) {
        tree.assign(2 * n, e);
    }

    // build
    // arrayで初期化する.
    void build(vector<Mon> &array) {
        for (int i = n; i < 2 * n; i++)
            tree[i] = array[i - n];
        for (int i = n - 1; i > 0; i--)
            tree[i] = op(tree[i << 1], tree[i << 1 | 1]);
    }

    // update
    // A[k] = A[k] * x と更新する
    // 制約: 0 <= k < n
    // 計算量: O(logn)
    void update(int k, Mon x) {
        k += n;
        tree[k] = op(tree[k], x);
        while (k > 1) {
            k >>= 1;
            tree[k] = op(tree[k << 1], tree[k << 1 | 1]);
        }
    }

    // set
    // A[k] = x と更新する
    // 制約: 0 <= k < n
    // 計算量: O(logn)
    void set(int k, Mon x) {
        k += n;
        tree[k] = x;
        while (k > 1) {
            k >>= 1;
            tree[k] = op(tree[k << 1], tree[k << 1 | 1]);
        }
    }

    // prod
    // A[l]*...*A[r-1] を計算する. l = rのときはeを返す.
    // 制約: 0 <= l <= r <= n
    // 計算量: O(logn)
    Mon prod(int l, int r) {
        l += n;
        r += n;
        Mon vl = e, vr = e;
        while (l < r) {
            if (l & 1) {
                vl = op(vl, tree[l]);
                l++;
            }
            if (r & 1) {
                r--;
                vr = op(tree[r], vr);
            }
            l >>= 1;
            r >>= 1;
        }
        return op(vl, vr);
    }
};