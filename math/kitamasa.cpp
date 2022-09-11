#pragma once
#include <bits/stdc++.h>
using namespace std;

// Kitamasa
// 初期値: A_0,A_1,...A_{k-1}
// 線形漸化式: A_n = D_0A_{n-k} + ... D_{k-1}A_{n-1}
// が与えられたときに
// A_nをO(k^2logn)で求める.
template <typename T>
struct Kitamasa {
    int k;
    vector<T> init, coef;

    Kitamasa(vector<T> &init, vector<T> &coef) : init(init), coef(coef) {
        k = (int)coef.size();
    }

    // solve
    // 制約: n >= 0
    // 計算量: O(k^2logn)
    T solve(long long n) {
        if (n == 0) return init[0];
        vector<T> ret(k, 0);
        ret[1] = 1;

        int msb = get_msb(n);
        for (int i = msb - 1; i >= 0; i--) {
            ret = mul2(ret);
            if ((n >> i) & 1) {
                ret = add1(ret);
            }
        }
        T ans = T(0);
        for (int i = 0; i < k; i++)
            ans += init[i] * ret[i];
        return ans;
    }

    int get_msb(long long n) {
        for (int i = 63; i >= 0; i--) {
            if ((n >> i) & 1) return i;
        }
        return -1;
    }

    vector<T> add1(vector<T> &ret) {
        vector<T> ans(k, 0);
        for (int i = 0; i < k; i++) {
            if (i == 0)
                ans[i] = coef[0] * ret[k - 1];
            else
                ans[i] = ret[i - 1] + coef[i] * ret[k - 1];
        }
        return ans;
    }

    vector<T> mul2(vector<T> &ret) {
        vector<T> ans(k, 0), k0 = ret;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                ans[j] += k0[i] * ret[j];
            }
            ret = add1(ret);
        }
        return ans;
    }
};