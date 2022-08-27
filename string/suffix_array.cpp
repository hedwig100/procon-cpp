#pragma once
#include <bits/stdc++.h>
using namespace std;

vector<int> suffix_array(string &s) {
    // O(Nlog^2N)
    int n = s.size();
    vector<int> sa(n + 1), rank(n + 1), tmp(n + 1);
    for (int i = 0; i <= n; ++i) {
        sa[i]   = i;
        rank[i] = (i < n ? s[i] : -1);
    }
    for (int k = 1; k <= n; k <<= 1) {
        auto cmp = [&](int i, int j) {
            if (rank[i] != rank[j])
                return rank[i] < rank[j];
            else {
                int ri = (i + k <= n ? rank[i + k] : -1);
                int rj = (j + k <= n ? rank[j + k] : -1);
                return ri < rj;
            }
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i <= n; ++i) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        for (int i = 0; i <= n; ++i) {
            rank[i] = tmp[i];
        }
    }
    return sa;
}

vector<int> lcp_array(string &s, vector<int> &sa) {
    int n = s.size();
    vector<int> rank(n);
    for (int i = 0; i < n; ++i) {
        rank[sa[i]] = i;
    }
}