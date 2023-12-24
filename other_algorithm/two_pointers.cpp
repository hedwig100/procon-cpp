#pragma once
#include <bits/stdc++.h>
using namespace std;

// TwoPointers
// 条件Pを満たす連続部分列[l,r)の数え上げ, もしくは最大の長さを計算する.
// ただし条件Pは以下の条件を満たすようなものでなければならない.
// 条件
// - 連続部分列[l,r)が条件Pを満たすとき,
// [l,r)内の任意の連続部分列が条件Pを満たす.
//
template <typename Data, const Data initial_state> struct TwoPointers {
    using Fcond = function<bool(Data data, int r)>;
    using Fincl = function<void(Data &data, int &l)>;
    using Fincr = function<void(Data &data, int &r)>;

    int n;
    long long count = 0;
    int max_length  = 0;

  private:
    Data data = initial_state;

    // cond
    // dataは連続部分列[l,r-1)に関する情報を持っており,
    // [l,r)が条件Pを満たす場合はtrue,そうでない時はfalseを返す. 制約: 0 <= l <
    // r <= n
    Fcond cond;

    // increase_l
    // lをl+1にする. 同時にデータの変更を行う.
    // 制約: 0 <= l < n
    Fincl increase_l;

    // increase_r
    // rをr+1にする. 同時にデータの変更を行う.
    // 制約: 0 <= r < n
    Fincr increase_r;

    void init() {
        count      = 0;
        max_length = 0;
        data       = initial_state;
    }

  public:
    TwoPointers(int n, Fcond cond, Fincl increase_l, Fincr increase_r)
        : n(n), cond(cond), increase_l(increase_l), increase_r(increase_r) {}

    // solve
    // 尺取法を用いて条件Pを満たす連続部分列の最大の長さと数を数える.
    // 計算量: O(n)
    void solve() {
        init();
        int r = 0;
        for (int l = 0; l < n; increase_l(data, l)) {
            while (r < n && cond(data, r + 1)) {
                increase_r(data, r);
            }
            count += r - l;
            max_length = max(max_length, r - l);
            if (r == l) increase_r(data, r);
        }
    }
};

// 未Verify
// TwoPointers2
// 条件Qを満たす連続部分列[l,r)の数え上げ, もしくは最小の長さを計算する.
// ただし条件Qは以下の条件を満たすようなものでなければならない.
// 条件
// - 連続部分列[l,r)が条件Qを満たすとき,
// [l,r)を含む任意の連続部分列が条件Qを満たす.
//
template <typename Data, const Data initial_state> struct TwoPointers2 {
    using Fcond = function<bool(Data data)>;
    using Fincl = function<void(Data &data, int &l)>;
    using Fincr = function<void(Data &data, int &r)>;

    int n;
    long long count;
    int min_length;

  private:
    Data data = initial_state;

    // cond
    // dataは連続部分列[l,r)に関する情報を持っており,
    // [l,r)が条件Qを満たす場合はtrue,そうでない時はfalseを返す. 制約: 0 <= l <
    // r <= n
    Fcond cond;

    // increase_l
    // lをl+1にする. 同時にデータの変更を行う.
    // 制約: 0 <= l < n
    Fincl increase_l;

    // increase_r
    // rをr+1にする. 同時にデータの変更を行う.
    // 制約: 0 <= r < n
    Fincr increase_r;

    void init() {
        count      = 0;
        min_length = n + 1;
        data       = initial_state;
    }

  public:
    TwoPointers2(int n, Fcond cond, Fincl increase_l, Fincr increase_r)
        : n(n), cond(cond), increase_l(increase_l), increase_r(increase_r) {}

    // solve
    // 尺取法を用いて条件Qを満たす連続部分列の最小の長さと数を数える.
    // 計算量: O(n)
    void solve() {
        init();
        int r = 0;
        for (int l = 0; l < n; increse_l(data, l)) {
            while (r <= n && !cond(data)) {
                if (r == n) {
                    r++;
                    break;
                }
                increase_r(data, r);
            }
            if (r == n + 1) break;
            count += n - r + 1;
            min_length = min(min_length, r - l);
            if (r == l) increase_r(data, r);
        }
    }
};

// 使用例
// https://atcoder.jp/contests/abc032/submissions/34471465
// https://atcoder.jp/contests/abc038/submissions/34471634
//
// using Data = long long;
// TwoPointers<Data, 0> tp(
//     n,
//     [&](Data data, int r) { return data + A[r - 1] <= x; },
//     [&](Data &data, int &l) { data -= A[l]; l++; },
//     [&](Data &data, int &r) { data += A[r]; r++; });
