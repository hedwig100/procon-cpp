#pragma once
#include <bits/stdc++.h>
using namespace std;

// LazySegmentTree
// *: Mon × Mon -> Monはモノイドであり, eをMonの単位元
// ×: OpMon × OpMon -> OpMonはモノイドであり, idをOpMonの単位元 とする.
// ^: Mon × OpMon -> Mon なるMonへの右作用は次の性質を満たすとする.
//
// 1. x^id = x
// 2. (x * y)^a = x^a * y^a
// 3. (x^a)^b = x^(a × b)
//
// このとき, 以下の操作が可能
// 1. A[l]*...*A[r-1]を求める
// 2. A[i] = A[i]^a (l <= i < r)と更新する
template <typename Mon, typename OpMon>
struct LazySegmentTree {
    using Fx  = function<Mon(Mon, Mon)>;
    using Fop = function<Mon(Mon, OpMon)>;
    using Fy  = function<OpMon(OpMon, OpMon)>;

    int n, size, log;
    vector<Mon> data;
    vector<OpMon> lazy; // lazy[i] = i自身とiの子孫にこれから伝播しなければならない値

    Fx op;
    Mon e;
    Fy composition;
    OpMon id;
    Fop mapping;

    LazySegmentTree(int n, Fx op, Mon e, Fy composition, OpMon id, Fop mapping)
        : n(n), op(op), e(e), composition(composition), id(id), mapping(mapping) {
        size = 1, log = 0;
        while (size < n)
            size <<= 1, log++;
        data.assign(2 * size, e);
        lazy.assign(2 * size, id);
    }

    // build
    // 長さnの配列Aで初期化する.
    // 計算量: O(n)
    void build(vector<Mon> &A) {
        for (int i = size; i < size + n; i++)
            data[i] = A[i - size];
        for (int i = size - 1; i >= 1; i--)
            data[i] = op(data[i << 1], data[i << 1 | 1]);
    }

    // apply
    // A[i] = A[i] * x (l <= i < r)とする.
    // 制約: 0 <= l <= r <= n
    // 計算量: O(logn)
    void apply(int l, int r, OpMon x) {
        l += size;
        r += size;
        int tmp_l = l, tmp_r = r;
        propagate_above(l);
        propagate_above(r - 1);
        while (l < r) {
            if (l & 1) {
                lazy[l] = composition(lazy[l], x);
                l++;
            }
            if (r & 1) {
                r--;
                lazy[r] = composition(lazy[r], x);
            }
            l >>= 1;
            r >>= 1;
        }
        recalc_above(tmp_l);
        recalc_above(tmp_r - 1);
    }

    // prod
    // A[l]*...*A[r-1]を返す. l = rならeを返す.
    // 制約: 0 <= l <= r <= n
    // 計算量; O(logn)
    Mon prod(int l, int r) {
        l += size;
        r += size;
        propagate_above(l);
        propagate_above(r - 1);
        Mon vl = e, vr = e;
        while (l < r) {
            if (l & 1) {
                vl = op(vl, propagate(l));
                l++;
            }
            if (r & 1) {
                r--;
                vr = op(propagate(r), vr);
            }
            l >>= 1;
            r >>= 1;
        }
        return op(vl, vr);
    }

  private:
    // propagate
    // lazy[i]をdata[i]に反映させ, iの子があればそのlazyの更新をする.
    // 更新したdata[i]を返す.
    Mon propagate(int i) {
        data[i] = mapping(data[i], lazy[i]);
        if (i < size) {
            lazy[i << 1]     = composition(lazy[i << 1], lazy[i]);
            lazy[i << 1 | 1] = composition(lazy[i << 1 | 1], lazy[i]);
        }
        lazy[i] = id;
        return data[i];
    }
    // propagate_above
    // iを含むiより上の区間のdataを以前のデータを伝播することで正しい状態にする.
    void propagate_above(int i) {
        for (int k = log; k >= 0; k--)
            if ((i >> k) >= 1) propagate(i >> k);
    }
    // recalc_above
    // iを含まないiより上の区間のdataをいま更新されたdataを用いて正しい状態に保つ.
    void recalc_above(int i) {
        while (i > 1) {
            i >>= 1;
            data[i] = op(propagate(i << 1), propagate(i << 1 | 1));
        }
    }
};