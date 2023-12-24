#pragma once
#include <bits/stdc++.h>
using namespace std;

struct FullyIndexableDictionary {
    int bit_size, block_size;
    vector<unsigned int> bit;
    vector<int> block;

    FullyIndexableDictionary(int bit_size = 0)
        : bit_size(bit_size), block_size((bit_size + 32 - 1) >> 5) {
        bit.resize(bit_size, 0);
        block.resize(block_size, 0);
    }

    // set(k) set the k-th bit
    // constraint: 0 <= k < bit_size
    // time complexity: O(1)
    void set(int k) { bit[k >> 5] |= 1U << (k & 31); }

    void build() {
        block[0] = 0;
        for (int i = 1; i < block_size; ++i) {
            block[i] = block[i - 1] + __builtin_popcount(bit[i - 1]);
        }
    }

    // op[k] returns k-th bit
    // constraint: 0 <= k < bit_size
    // time complexity: O(1)
    bool operator[](int k) { return bool((bit[k >> 5] >> (k & 31)) & 1U); }

    // _rank(k) returns the number of 1 in [0,k)
    // constraint: 0 <= k <= bit_size
    // time complexity: O(1)
    int _rank(int k) {
        return block[k >> 5] +
               __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1));
    }

    // rank(v,k) returns the number of v in [0,k)
    // constraint: 0 <= k <= bit_size,(v = 0 or v = 1)
    // time complexity: O(1)
    int rank(bool v, int k) { return (v ? _rank(k) : k - _rank(k)); }

    // select(v,k) returns the k-th position of v
    // constraint: k >= 0, (v = 0 or v = 1)
    // time complexity: O(logN),N = bit_size
    int select(bool v, int k) {
        if (k < 0 || rank(v, bit_size) <= k) return -1;
        int l = 0, r = bit_size;
        while (r - l > 1) {
            int mid = (r + l) >> 1;
            if (rank(v, mid) >= k + 1)
                r = mid;
            else
                l = mid;
        }
        return r - 1;
    }

    int select(bool v, int i, int l) { return select(v, i + rank(v, l)); }
};

template <class T, int MAXLOG> struct WaveletMatrix {
    int len;
    FullyIndexableDictionary mat[MAXLOG];
    int zeros[MAXLOG], buff1[MAXLOG], buff2[MAXLOG];

    WaveletMatrix(vector<T> data) {
        len = data.size();
        vector<T> l(len), r(len);
        for (int dep = 0; dep < MAXLOG; ++dep) {
            mat[dep] = FullyIndexableDictionary(len + 1);
            int p = 0, q = 0;
            for (int i = 0; i < len; ++i) {
                bool k = (data[i] >> (MAXLOG - (dep + 1))) & 1;
                if (k)
                    r[q++] = data[i], mat[dep].set(i);
                else
                    l[p++] = data[i];
            }
            zeros[dep] = p;
            mat[dep].build();
            swap(l, data);
            for (int i = 0; i < q; ++i)
                data[p + i] = r[i];
        }
    }
    T access(int k) {
        T res    = 0;
        bool bit = 0;
        for (int dep = 0; dep < MAXLOG; ++dep) {
            bit = mat[dep][k];
            res = (res << 1) | bit;
            k   = mat[dep].rank(bit, k) + zeros[dep] * bit;
        }
        return res;
    }
    // return the number of v in [0,k)
    int rank(T v, int k) {
        int l = 0, r = k;
        for (int dep = 0; dep < MAXLOG; ++dep) {
            buff1[dep] = l, buff2[dep] = r;
            bool bit = (v >> (MAXLOG - (dep + 1))) & 1;
            l        = mat[dep].rank(bit, l) + zeros[dep] * bit;
            r        = mat[dep].rank(bit, r) + zeros[dep] * bit;
        }
        return r - l;
    }
    // return the position of k-th v
    int select(T v, int k) {
        rank(v, len);
        for (int dep = MAXLOG - 1; dep >= 0; --dep) {
            bool bit = (v >> (MAXLOG - (dep + 1))) & 1;
            k        = mat[dep].select(bit, k, buff1[dep]);
            if (k >= buff2[dep] || k < 0) return -1;
            k -= buff1[dep];
        }
        return k;
    }
    // return k-th largest value in [l,r)
    T quantile(int l, int r, int k) {
        if (r - l <= k || k < 0) return -1;
        T res = 0;
        for (int dep = 0; dep < MAXLOG; ++dep) {
            int p = mat[dep].rank(1, l);
            int q = mat[dep].rank(1, r);
            if (q - p < k) {
                l = p + zeros[dep];
                r = q + zeros[dep];
                res |= (T(1) << (MAXLOG - (dep + 1)));
            } else {
                k -= (q - p);
                l -= p;
                r -= q;
            }
        }
        return res;
    }
};