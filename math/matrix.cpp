#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "mint.cpp"

template <typename T> using Matrix = vector<vector<T>>;

template <typename T> Matrix<T> mul(const Matrix<T> &a, const Matrix<T> &b) {
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

template <typename T> vector<T> mul(const Matrix<T> &a, const vector<T> &b) {
    assert(a[0].size() == b.size());
    vector<T> ans(a.size(), 0);
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)a[0].size(); j++) {
            ans[i] += a[i][j] * b[j];
        }
    }
    return ans;
}

template <typename T, typename U> Matrix<T> pow(Matrix<T> a, U n) {
    assert(a.size() == a[0].size());
    int m = (int)a.size();
    Matrix<T> ans(m, vector<T>(m, 0));
    for (int i = 0; i < m; i++)
        ans[i][i] = 1;
    while (n > 0) {
        if (n & 1) { ans = mul(ans, a); }
        a = mul(a, a);
        n >>= 1;
    }
    return ans;
}

template <int MOD> int _find_pivot(const Matrix<ModInt<MOD>> &a, int i) {
    for (int j = i; j < (int)a[i].size(); j++) {
        if (a[j][i].x != 0) return j;
    }
    return -1;
}

template <typename T> int _find_pivot(const Matrix<T> &a, int i) {
    int pivot = -1;
    T val     = T(0);
    for (int j = i; j < (int)a[i].size(); j++) {
        if (abs(a[j][i]) > val) {
            val   = abs(a[j][i]);
            pivot = j;
        }
    }
    return pivot;
}

// lu_decomposition
// PA = LUなる分解をする. ただし, Pは置換行列, Lは対角成分が1の下三角行列,
// Uは上三角行列. 置換PとL,Uを詰めた行列を返す. Aが正則ではない場合,
// Uの対角成分に0が含まれる. 計算量: O(n^3)
template <typename T>
pair<vector<int>, Matrix<T>> lu_decomposition(Matrix<T> a) {
    assert(a.size() == a[0].size());
    int n = (int)a.size();
    vector<int> pinv(n);
    iota(pinv.begin(), pinv.end(), 0);
    for (int i = 0; i < n; i++) {
        int pivot = _find_pivot(a, i);
        if (pivot < 0) continue;
        swap(a[i], a[pivot]), swap(pinv[i], pinv[pivot]);
        for (int j = i + 1; j < n; j++) {
            a[j][i] /= a[i][i];
            for (int k = i + 1; k < n; k++) {
                a[j][k] -= a[i][k] * a[j][i];
            }
        }
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i < n; i++) {
        if (i == pinv[i]) continue;
        int k = -1;
        for (int j = i + 1; j < n; j++) {
            if (pinv[j] == i) k = j;
        }
        swap(p[i], p[k]);
        swap(pinv[i], pinv[k]);
    }
    return make_pair(p, a);
}

constexpr inline bool _is_zero(long double x) { return abs(x) < 1e-8; }
constexpr inline bool _is_zero(double x) { return abs(x) < 1e-8; }
template <int MOD> constexpr inline bool _is_zero(const ModInt<MOD> &x) {
    return x.x == 0;
}
template <typename T> constexpr inline bool _is_zero(T x) { return x == T(0); }

// solve
// PA = LUを用いてAx = bなる連立方程式をとく.
// もし解が存在しなければ{}を返す. 解が少なくとも一つ存在すればその一つを返す.
// 計算量: O(n^2)
template <typename T>
vector<T> solve(vector<int> p, const Matrix<T> &lu, vector<T> b) {
    int n = (int)lu.size();
    for (int i = 0; i < n; i++) {
        if (i == p[i]) continue;
        int k = -1;
        for (int j = i + 1; j < n; j++) {
            if (p[j] == i) k = j;
        }
        swap(p[i], p[k]);
        swap(b[i], b[k]);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            b[i] -= b[j] * lu[i][j];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++)
            b[i] -= b[j] * lu[i][j];
        if (_is_zero(lu[i][i]) && !_is_zero(b[i]))
            return {}; // 解なし
        else if (!_is_zero(lu[i][i]))
            b[i] /= lu[i][i];
    }
    return b;
}

// solve
// Ax = bなる連立方程式をとく.
// もし解が存在しなければ{}を返す. 解が少なくとも一つ存在すればその一つを返す.
// 計算量: O(n^3)
template <typename T> vector<T> solve(Matrix<T> A, vector<T> b) {
    assert(A.size() == A[0].size());
    auto [p, lu] = lu_decomposition(A);
    return solve(p, lu, b);
}

// _det
// lu分解された行列の行列式を求める.
// 計算量: O(n)
template <typename T> T _det(const Matrix<T> &lu) {
    T ans = T(1);
    for (int i = 0; i < (int)lu.size(); i++)
        ans *= lu[i][i];
    return ans;
}

// det
// 行列の行列式を求める.
// 計算量: O(n^3)
template <typename T> T det(Matrix<T> A) {
    auto [_, lu] = lu_decomposition(A);
    return _det(lu);
}

// _rank
// lu分解された行列のランクを求める.
// 計算量: O(n)
template <typename T> int _rank(const Matrix<T> &lu) {
    int ans = (int)lu.size();
    for (int i = 0; i < (int)lu.size(); i++)
        if (_is_zero(lu[i][i])) ans--;
    return ans;
}

// rank
// 行列のランクを求める.
// 計算量: O(n^3)
template <typename T> int rank(Matrix<T> A) {
    auto [_, lu] = lu_decomposition(A);
    return _rank(lu);
}