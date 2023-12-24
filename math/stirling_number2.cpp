#pragma once
#include <bits/stdc++.h>
using namespace std;

// StirlingNumber2
// n個の区別できるものをk個の区別できない箱に1個以上に分割する方法が何通りあるか求める.
// これをS(n,k)とする. 第二種スターリング数
template <typename T> struct StirlingNumber2 {
    int n, k;
    vector<vector<T>> dp;

    StirlingNumber2(int n, int k) : n(n), k(k) {
        dp.assign(n + 1, vector<T>(k + 1, T(0)));
    }

    // solve
    // S(i,j) (0 <= i <= n, 0 <= j <= k)を求める.
    // 計算量: O(nk)
    T solve() {
        dp[0][0] = T(1);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = T(j) * dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[n][k];
    }

    // S(i,j)を返す.
    // 制約: 0 <= i <= n, 0 <= j <= k
    T operator()(int i, int j) { return dp[i][j]; }
};