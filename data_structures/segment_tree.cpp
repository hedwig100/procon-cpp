#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class Monoid>
struct SegmentTree {
    int N;
    vector<Monoid> tree;

    // depending on the problem
    Monoid unit;
    using FX = function<Monoid(Monoid, Monoid)>;
    FX func;
    //

    SegmentTree(int _N, Monoid _unit, FX _func) : N(_N), unit(_unit), func(_func) {
        tree.assign(2 * N, unit);
    }

    void build(vector<Monoid> &array) {
        for (int i = N; i < 2 * N; i++)
            tree[i] = array[i - N];
        for (int i = N - 1; i > 0; i--)
            tree[i] = func(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int k, Monoid x) {
        k += N;
        tree[k] = func(tree[k], x);
        while (k > 1) {
            k >>= 1;
            tree[k] = func(tree[k << 1], tree[k << 1 | 1]);
        }
    }

    Monoid query(int L, int R) {
        L += N;
        R += N;
        Monoid vL = unit, vR = unit;
        while (L < R) {
            if (L & 1) {
                vL = func(vL, tree[L]);
                L++;
            }
            if (R & 1) {
                R--;
                vR = func(tree[R], vR);
            }
            L >>= 1;
            R >>= 1;
        }
        return func(vL, vR);
    }

    void debug() {
        for (int i = 0; i < 2 * N; ++i)
            cout << "  st[" << i << "] : " << tree[i];
    }
};