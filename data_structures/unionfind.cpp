#pragma once
#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    int N;
    vector<int> parents;

    UnionFind(int _N) : N(_N) {
        parents.assign(N, -1);
    }

    int find(int x) { // xの親を返す
        if (parents[x] < 0) return x;
        return parents[x] = find(parents[x]);
    }

    void unite(int x, int y) { // xとyの含むグループを併合
        int px = find(x);
        int py = find(y);
        if (parents[px] > parents[py]) swap(px, py);
        if (px != py) {
            parents[px] += parents[py];
            parents[py] = px;
        }
    }

    bool same(int x, int y) { // x,yが同じグループにいるか判定
        return find(x) == find(y);
    }

    int size(int x) { // xと同じグループのメンバーの個数
        return -parents[find(x)];
    }

    vector<int> root() { // ufの根を列挙
        vector<int> res;
        for (int i = 0; i < N; i++) {
            if (parents[i] < 0) res.push_back(i);
        }
        return res;
    }

    int group_count() { // ufのグループの数を数える
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (parents[i] < 0) cnt++;
        }
        return cnt;
    }
};