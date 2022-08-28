#pragma once
#include <bits/stdc++.h>
using namespace std;

struct LongestCommonSequence {
    int n, m;
    string s, t, ret;
    vector<vector<int>> dp;

    LongestCommonSequence(string s, string t) : s(s), t(t) {
        n = (int)s.size();
        m = (int)t.size();
        dp.assign(n + 1, vector<int>(m + 1, 0));
    }

    // solve
    // 最長共通部分列問題を解いてその長さを返す。
    // 計算量: O(nm)
    int solve() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i] == t[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[n][m];
    }

    // restore_common_string
    // 最長共通部分列(文字列)を返す
    // 計算量: O(l),lは最長共通部分列の長さ
    string restore_common_string() {
        vector<char> ret;
        int ni = n, nj = m;
        while (ni != 0 && nj != 0) {
            if (s[ni - 1] == t[nj - 1]) {
                ret.push_back(s[ni - 1]);
                ni--;
                nj--;
            } else {
                if (dp[ni][nj] == dp[ni - 1][nj])
                    ni--;
                else
                    nj--;
            }
        }
        reverse(ret.begin(), ret.end());
        string ans = "";
        for (auto &c : ret)
            ans += c;
        return ans;
    }
};