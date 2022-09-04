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
    int size;
    vector<Mon> tree;
    Fx op;
    Mon e;

    SegmentTree(int n, Fx op, Mon e) : n(n), op(op), e(e) {
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, e);
    }

    // build
    // arrayで初期化する.
    void build(vector<Mon> &array) {
        for (int i = size; i < size + n; i++)
            tree[i] = array[i - size];
        for (int i = size - 1; i > 0; i--)
            tree[i] = op(tree[i << 1], tree[i << 1 | 1]);
    }

    // update
    // A[k] = A[k] * x と更新する
    // 制約: 0 <= k < n
    // 計算量: O(logn)
    void update(int k, Mon x) {
        k += size;
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
        k += size;
        tree[k] = x;
        while (k > 1) {
            k >>= 1;
            tree[k] = op(tree[k << 1], tree[k << 1 | 1]);
        }
    }

    // get
    // A[k]を返す.
    // 制約: 0 <= k < n
    // 計算量: O(1)
    Mon get(int k) {
        return tree[k + size];
    }

    // prod
    // A[l]*...*A[r-1] を計算する. l = rのときはeを返す.
    // 制約: 0 <= l <= r <= n
    // 計算量: O(logn)
    Mon prod(int l, int r) {
        l += size;
        r += size;
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

    // max_right
    // l < r <= nでf(A[l]*...*A[r-1]) = trueなる最大のr, そのようなrが存在しない場合はlを返す.
    // 制約: 0 <= l <= n,f(e) = true
    // 計算量: O(logn)
    int max_right(int l, function<bool(Mon)> f) {
        if (l == n) return n;
        int r = l + size;
        Mon x = e;
        do {
            while (r % 2 == 0)
                r >>= 1;
            if (f(op(x, tree[r]))) {
                x = op(x, tree[r]);
                r++;
            } else {
                while (r < size) {
                    r <<= 1;
                    if (f(op(x, tree[r]))) {
                        x = op(x, tree[r]);
                        r++;
                    }
                }
                return r - size;
            }
        } while ((r & -r) != r);
        return n;
    }
};