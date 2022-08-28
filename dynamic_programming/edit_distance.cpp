#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../template/const.hpp"

// edit_distance
// 文字列s,文字列tの編集距離, すなわち以下の操作をしてsをtに等しくするために必要な操作回数の最小値
// 1. sから文字を一つ取り除く
// 2. sに文字を一つ挿入する
// 3. sの文字を一つ変換する
// 計算量: O(|S||T|)
int edit_distance(string s, string t) {
    int n = (int)s.size(), m = (int)t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j];
            dp[i + 1][j + 1] = min({dp[i + 1][j + 1], dp[i][j + 1] + 1, dp[i + 1][j] + 1, dp[i][j] + 1});
        }
    }
    return dp[n][m];
}