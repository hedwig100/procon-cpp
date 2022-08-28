#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct PartitionNumber {
    int n, k;
    vector<vector<T>> dp;

    // PartionNumber
    // n個の区別できないものをk個の区別できない箱に0個以上に分割する方法が何通りあるか求める.
    // これをP(n,k)とするとP(n,0) = 0 (n > 0)
    PartitionNumber(int n, int k) : n(n), k(k) {
        dp.assign(n + 1, vector<T>(k + 1, T(0)));
    }

    // solve
    // 0 <= i <= n,0 <= j <= kの分割数を求める.
    // 計算量: O(nk)
    void solve() {
        dp[0][0] = T(1);
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i][j - 1];
                if (i - j >= 0) dp[i][j] += dp[i - j][j];
            }
        }
    }

    // P(i,j)を返す.
    // 制約: 0 <= i <= n,0 <= j <= k
    T operator()(int i, int j) {
        return dp[i][j];
    }
};