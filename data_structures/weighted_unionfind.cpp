#pragma once
#include <bits/stdc++.h>
using namespace std;

// WeightedUnionFind
// 通常のUnionFindに加えて, 同じグループにいるノードの親に対する重みも
// 管理するデータ構造.
template <typename Abel, Abel unit>
struct WeightedUnionFind {
    int n;
    vector<int> parents;
    vector<Abel> diff_weight;

    WeightedUnionFind(int n) : n(n) {
        parents.assign(n, -1);
        diff_weight.assign(n, unit);
    }

    // find
    // xの親を返す. 経路圧縮するため, diff_weightも更新する
    // 制約: 0 <= x < n
    int find(int x) {
        if (parents[x] < 0)
            return x;
        else {
            int p = find(parents[x]);
            diff_weight[x] += diff_weight[parents[x]];
            return parents[x] = p;
        }
    }

    // weight
    // xのparentからの重みを返す
    // 制約: 0 <= x < n
    Abel weight(int x) {
        find(x);
        return diff_weight[x];
    }

    // diff
    // xとyが同じグループにいる時, xに対するyの重みを返す.
    // xとyが同じグループにいない時, 返す値には意味がない.
    // 制約: 0 <= x,y < n, xとyは同じグループ
    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }

    // unite
    // weight(y) = weight(x) + wとなるようにxとyを併合する.
    // もしすでにxとyが同じグループでweight(y) != weight(x) + wであればfalseを返す.
    // そうでない場合はtrueを返す.
    // 制約: 0 <= x,y < n
    bool unite(int x, int y, Abel w) {
        w += weight(x);
        w -= weight(y);

        x = find(x);
        y = find(y);
        if (x == y) {
            if (diff(x, y) == w)
                return true;
            else
                return false;
        }

        if (parents[x] > parents[y]) {
            swap(x, y);
            w *= -1;
        }

        parents[x] += parents[y];
        parents[y]     = x;
        diff_weight[y] = w;
        return true;
    }

    // same
    // xとyが同じかどうか判定する
    // 制約: 0 <= x,y < n
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    // size
    // xと同じグループのサイズを返す.
    // 制約: 0 <= x < n
    int size(int x) {
        return -parents[find(x)];
    }
};