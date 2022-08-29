#pragma once
#include <bits/stdc++.h>
using namespace std;

// topological_sort
// 有向グラフGの隣接リストを受け取ってDAGであればトポロジカルソートした結果を返し,
// そうでなければ{-1}を返す.
vector<int> topological_sort(const vector<vector<int>> &G) {
    int n = (int)G.size();
    vector<int> ans;
    stack<int> stk;
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++) {
        for (const int &v : G[i])
            indeg[v]++;
    }
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            stk.push(i);
            indeg[i] = -1;
        }
    }
    while (!stk.empty()) {
        int v = stk.top();
        ans.push_back(v);
        stk.pop();
        for (const int &u : G[v]) {
            if (--indeg[u] == 0) {
                stk.push(u);
                indeg[u] = -1;
            }
        }
    }
    if (all_of(indeg.begin(), indeg.end(), [](int x) { return x < 0; }))
        return ans;
    else
        return {-1};
}