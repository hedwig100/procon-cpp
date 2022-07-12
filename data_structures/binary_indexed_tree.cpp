#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct BinaryIndexedTree {
    int N;         // array length
    int power = 1; // minimum power of 2 larger than N (power = 2^i > N)
    vector<T> bit; // bit data array

    BinaryIndexedTree(int N = 0) : N(N) {
        bit.assign(N + 1, 0);
        while (power <= N)
            power <<= 1; // power > N
    }

    BinaryIndexedTree(const vector<T> &A) {
        N = (int)A.size();
        bit.assign(N + 1, 0);
        while (power <= N)
            power <<= 1; // power > N

        // build
        for (int i = 0; i < N; ++i)
            add(i, A[i]);
    }

    // add x to a[i]
    // constraint: 0 <= i < N
    void add(int i, T x) {
        for (int idx = ++i; idx <= N; idx += (idx & -idx)) {
            bit[idx] += x;
        }
    }

    // sum(k) returns \sum_{0 <= i <= k} a[i]
    // constraint: 0 <= k < N
    T sum(int k) {
        T ret = 0;
        for (int idx = ++k; idx > 0; idx -= (idx & -idx)) {
            ret += bit[idx];
        }
        return ret;
    }

    // sum(l,r) returns \sum_{l <= i < r} a[i]
    // constraint: 0 <= l < r <= N
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    // lower_bound returns mininum index k s.t. \sum_{0 <= i <= k} >= x
    // constraint: a[i] >= 0 for all i
    int lower_bound(T x) {
        int k = 0;
        for (int r = power >> 1; r > 0; r >>= 1) {
            if (k + r <= N && bit[k + r] < x) {
                x -= bit[k + r];
                k += r;
            }
        }
        return k;
    }
};