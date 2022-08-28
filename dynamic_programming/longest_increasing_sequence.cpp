#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T, T INF>
struct LongestIncreasingSequence {

    // dp[i] = 長さi+1であるような増加部分列での最後の要素の最小値, ない場合はINF
    // dp_ind[i] = 長さi+1であるような増加部分列での最後の要素の最小値のインデックス, ない場合は-1
    // prev[i] = A[i]を含む中で最長の増加部分列でのA[i]の前の要素がA[j]であるときj, 先頭のときは-1
    int n;
    vector<T> A, dp;
    vector<int> prev, dp_ind;

    // LongestIncreasingSequece
    // Aの最長増加部分列を求める. すなわち
    // 0 <= i1 < i2 < ... < ik < n, A[i1] < A[i2] < ... < A[ik]なるkの最大値を求める。
    LongestIncreasingSequence(int n, vector<T> &A) : n(n), A(A) {
        dp.assign(n + 1, INF);
        dp_ind.assign(n + 1, -1);
        prev.assign(n, -1);
    }

    // solve
    // Aの最長増加部分列を求める.
    // 計算量: O(nlogn)
    int solve() {
        for (int i = 0; i < n; i++) {
            int j     = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
            dp[j]     = A[i];
            dp_ind[j] = i;
            prev[i]   = (j > 0 ? dp_ind[j - 1] : -1);
        }
        return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
    }

    // restore_lis
    // 最長増加部分列を復元する
    // 計算量: O(l),lは最長増加部分列の長さ
    vector<T> restore_lis() {
        vector<T> ans;
        int max_len = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
        for (int now_ind = dp_ind[max_len - 1]; now_ind >= 0; now_ind = prev[now_ind])
            ans.push_back(A[now_ind]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
