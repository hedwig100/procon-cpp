#pragma once
#include <bits/stdc++.h>
using namespace std;

// SlidingWindowAggregation
// 半群に対して以下のことが行えるデータ構造
//
// push(x): xを追加する
// pop(): queueの要領で要素を取り除く(FIFO)
// fold():
// 今入っている要素を早く入っていた方からa0,a1,...,anとしたときにa0*a1*...anを計算する.
template <typename SemiGrp> struct SlidingWindowAggregation {
    using Fx = function<SemiGrp(const SemiGrp &, const SemiGrp &)>;

    vector<SemiGrp> left, left_cum, right, right_cum;
    Fx op;

    SlidingWindowAggregation(Fx op) : op(op) {}

    inline int size() { return (int)left.size() + (int)right.size(); }
    inline bool empty() { return size() == 0; }

    // push
    // xを追加する
    // 計算量: O(1)
    void push(SemiGrp x) {
        if ((int)right.size() == 0)
            right.push_back(x), right_cum.push_back(x);
        else
            right.push_back(x), right_cum.push_back(op(right_cum.back(), x));
    }

    // pop
    // データをFIFOで取り出す. 空の場合は何もしない.
    // 計算量: 償却 O(1)
    void pop() {
        if (empty()) return;
        if ((int)left.size() != 0) {
            left.pop_back(), left_cum.pop_back();
            return;
        }

        int sz = (int)right.size();
        if (sz == 1) {
            right.pop_back(), right_cum.pop_back();
            return;
        }
        left.push_back(right.back()), left_cum.push_back(right.back());
        right.pop_back(), right_cum.pop_back();
        for (int i = 1; i < sz - 1; i++) {
            left.push_back(right.back()),
                left_cum.push_back(op(right.back(), left_cum.back()));
            right.pop_back(), right_cum.pop_back();
        }
        right.pop_back(), right_cum.pop_back();
    }

    // fold
    // 今入っている要素を早く入っていた方からa0,a1,...,anとしたときにa0*a1*...anを返す.
    // 制約: 空ではない
    // 計算量: O(1)
    SemiGrp fold() {
        assert(!empty());
        if ((int)left.size() == 0)
            return right_cum.back();
        else if ((int)right.size() == 0)
            return left_cum.back();
        else
            return op(left_cum.back(), right_cum.back());
    }

    friend ostream &operator<<(ostream &os,
                               const SlidingWindowAggregation<SemiGrp> &swag) {
        for (int i = (int)swag.left.size() - 1; i >= 0; i--)
            os << swag.left[i] << ' ';
        for (int i = 0; i < (int)swag.right.size(); i++)
            os << swag.right[i] << ' ';
        return os;
    }
};

// example:
// using SemiGrp = pair<int, int>;
// SlidingWindowAggregation<SemiGrp> swag([](const SemiGrp &a, const SemiGrp &b)
// {
//     if (a.first < b.first)
//         return b;
//     else
//         return a;
// });