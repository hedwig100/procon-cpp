#pragma once
#include <bits/stdc++.h>
using namespace std;

// UnionFind
// グループを管理するデータ構造
struct UnionFind {
    int n;
    vector<int> parents;

    UnionFind(int n) : n(n) { parents.assign(n, -1); }

    // find
    // xの親を返す.
    // 制約: 0 <= x < n
    int find(int x) {
        if (parents[x] < 0) return x;
        return parents[x] = find(parents[x]);
    }

    // unite
    // xとyを含むグループを併合
    // 制約: 0 <= x,y < n
    void unite(int x, int y) { // xとyの含むグループを併合
        int px = find(x);
        int py = find(y);
        if (parents[px] > parents[py]) swap(px, py);
        if (px != py) {
            parents[px] += parents[py];
            parents[py] = px;
        }
    }

    // same
    // xとyが同じグループにいるか判定
    // 制約: 0 <= x,y < n
    bool same(int x, int y) { return find(x) == find(y); }

    // size
    // xと同じグループのメンバーの個数
    // 制約: 0 <= x < n
    int size(int x) { return -parents[find(x)]; }

    // root
    // 根を全て列挙する
    vector<int> root() {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (parents[i] < 0) res.push_back(i);
        }
        return res;
    }

    // group_count
    // グループの数を返す.
    int group_count() { // ufのグループの数を数える
        return (int)root().size();
    }
};