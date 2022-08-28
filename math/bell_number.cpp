#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../math/stirling_number2.cpp"

// BellNumber
// n個の区別できるものをk個の区別できない箱に0個以上に分割する方法が何通りあるか求める.
// これをB(n,k)としてベル数という.
template <typename T>
struct BellNumber {
    int n, k;
    vector<vector<T>> dp;

    BellNumber(int n, int k) : n(n), k(k) {
        dp.assign(n + 1, vector<T>(k + 1, T(0)));
    }

    // solve
    // 0 <= i <= n,0 <= j <= kについてB(i,j)を求める.
    // 計算量: O(nk)
    T solve() {
        StirlingNumber2<T> s2(n, k);
        s2.solve();
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i][j - 1] + s2(i, j);
            }
        }
        return dp[n][k];
    }

    // B(i,j)を返す.
    // 制約: 0 <= i <= n, 0 <= j <= k
    T operator()(int i, int j) {
        return dp[i][j];
    }
};