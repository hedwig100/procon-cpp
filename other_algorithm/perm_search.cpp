#pragma once
#include <bits/stdc++.h>
using namespace std;

// PermSearch
// 順列を全探索する.
// 0~n-1までの数字からなる順列を探索する. fはある順列をvectorで受け取って処理をする関数
struct PermSearch {
    int n;
    vector<int> A;
    function<void(vector<int> &)> f;

    PermSearch(int n, function<void(vector<int> &)> f) : n(n), f(f) {
        A.resize(n);
    }

    // solve
    // 計算量はO(n!)
    void solve() {
        iota(A.begin(), A.end(), 0);
        do {
            f(A);
        } while (next_permutation(A.begin(), A.end()));
    }
};