#include <bits/stdc++.h>
using namespace std;

template <class Abel>
struct WeightedUnionFind {
    int N;
    vector<int> parents;
    vector<Abel> diff_weight;

    WeightedUnionFind(int _N, Abel unit = 0) : N(_N) {
        parents.assign(N, -1);
        diff_weight.assign(N, unit);
    }

    int find(int x) {
        if (parents[x] < 0)
            return x;
        else {
            int p = find(parents[x]);
            diff_weight[x] += diff_weight[parents[x]];
            return parents[x] = p;
        }
    }

    Abel weight(int x) {
        find(x);
        return diff_weight[x];
    }

    Abel diff(int x, int y) { // xとyが同じグループであることを確認してから呼ぶ
        return weight(y) - weight(x);
    }

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

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return -parents[find(x)];
    }
};