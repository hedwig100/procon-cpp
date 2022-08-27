#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Mo {
    int N, Q, width, l, r;
    vector<int> L, R, idx;
    using T = int;
    T ret;
    vector<T> ans;

    Mo(int N, int Q) : N(N), Q(Q) {
        int width = sqrt(N);
        L.resize(Q);
        R.resize(Q);
        idx.resize(Q);
        ans.resize(Q);
    }
    void add_query(int i, int l, int r) { // ith query is [l,r)
        idx[i] = i;
        L[i]   = l;
        R[i]   = r;
    }
    void build() {
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return L[a] / width == L[b] / width ? R[a] < R[b] : L[a] < L[b];
        });
        l = 0;
        r = 0;
    }
    void del(int i) { //区間を縮める
    }
    void add(int i) { //区間を広げる
    }
    T process(int i) { //[l,r)
        i = idx[i];
        while (l > L[i])
            add(--l);
        while (r < R[i])
            add(r++);
        while (l < L[i])
            del(l++);
        while (r > R[i])
            del(--r);
        return ans[i] = ret;
    }
};