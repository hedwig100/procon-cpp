#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
using Matrix = vector<vector<T>>;

template <typename T>
Matrix<T> mul(const Matrix<T> &a, const Matrix<T> &b) {
    assert(a[0].size() == b.size());
    Matrix<T> c(a.size(), vector<T>(b[0].size()));
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)a[0].size(); j++) {
            for (int k = 0; k < (int)b[0].size(); k++) {
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }
    return c;
}

template <typename T, typename U>
Matrix<T> pow(Matrix<T> a, U n) {
    assert(a.size() == a[0].size());
    int m = (int)a.size();
    Matrix<T> ans(m, vector<T>(m, 0));
    for (int i = 0; i < m; i++)
        ans[i][i] = 1;
    while (n > 0) {
        if (n & 1) {
            ans = mul(ans, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return ans;
}