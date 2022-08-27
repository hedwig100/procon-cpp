#pragma once
#include <bits/stdc++.h>
using namespace std;

// https://yukicoder.me/submissions/470340
template <class Monoid1, class Monoid2>
struct LazySegmentTree {
    int N;
    vector<Monoid1> tree;
    vector<Monoid2> lazy;

    // depending on the problem
    Monoid1 unit_x;
    Monoid2 unit_m;
    using FX = function<Monoid1(Monoid1, Monoid1)>;
    FX fx;
    using FA = function<Monoid1(Monoid1, Monoid2)>;
    FA fa;
    using FM = function<Monoid2(Monoid2, Monoid2)>;
    FM fm;
    //

    LazySegmentTree(int _N, Monoid1 _unitx, Monoid2 _unitm, FX _fx, FA _fa, FM _fm) : N(_N), unit_x(_unitx), unit_m(_unitm), fx(_fx), fa(_fa), fm(_fm) {
        tree.assign(2 * N, unit_x);
        lazy.assign(2 * N, unit_m);
    }

    void build(vector<Monoid1> &array) {
        for (int i = N; i < 2 * N; i++)
            tree[i] = array[i - N];
        for (int i = N - 1; i > 0; i--)
            tree[i] = fx(tree[i << 1], tree[i << 1 | 1]);
    }

    Monoid1 eval_at(int i) {
        return fa(tree[i], lazy[i]);
    }

    void propagate_at(int i) {
        tree[i]          = eval_at(i);
        lazy[i << 1]     = fm(lazy[i << 1], lazy[i]);
        lazy[i << 1 | 1] = fm(lazy[i << 1 | 1], lazy[i]);
        lazy[i]          = unit_m;
    }

    void propagate_above(int i) {
        int H = 0;
        while ((1 << H) < i)
            ++H;
        for (int h = H - 1; h > 0; --h) {
            propagate_at(i >> h);
        }
    }

    void recalc_above(int i) {
        while (i > 1) {
            i >>= 1;
            tree[i] = fx(eval_at(i << 1), eval_at(i << 1 | 1));
        }
    }

    void set_val(int i, Monoid1 x) {
        i += N;
        propagate_above(i);
        tree[i] = x;
        lazy[i] = unit_m;
        recalc_above(i);
    }

    Monoid1 fold(int L, int R) {
        L += N;
        R += N;
        propagate_above(L / (L & -L));
        propagate_above(R / (R & -R) - 1);
        Monoid1 vL = unit_x, vR = unit_x;
        while (L < R) {
            if (L & 1) {
                vL = fx(vL, eval_at(L));
                ++L;
            }
            if (R & 1) {
                --R;
                vR = fx(eval_at(R), vR);
            }
            L >>= 1;
            R >>= 1;
        }
        return fx(vL, vR);
    }

    void operate_range(int L, int R, Monoid2 x) {
        L += N;
        R += N;
        int L0 = L / (L & -L), R0 = R / (R & -R) - 1;
        propagate_above(L0);
        propagate_above(R0);
        while (L < R) {
            if (L & 1) {
                lazy[L] = fm(lazy[L], x);
                ++L;
            }
            if (R & 1) {
                --R;
                lazy[R] = fm(lazy[R], x);
            }
            L >>= 1;
            R >>= 1;
        }
        recalc_above(L0);
        recalc_above(R0);
    }

    /*
    void debug() {
        for (int i = 0;i < 2*N;++i) {printf(" st[%d] : ",i); cout << tree[i];}
        cout << '\n';
        for (int i = 0;i < 2*N;++i) {printf(" lazy[%d] : ",i); cout << lazy[i];}
        cout << '\n';
    }
    */
};