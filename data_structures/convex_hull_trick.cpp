#pragma once
#include <bits/stdc++.h>
using namespace std;

// 幾何ライブラリのLineと名前が被る恐れがあるのでnamespaceを使う.
namespace _cht {

// Line
// 直線を管理する構造体
template <typename T>
struct Line {
    T a, b;
    Line(T a = 0, T b = 0) : a(a), b(b) {}
    T f(T x) {
        return a * x + b;
    }
    bool operator<(const Line<T> &rhs) const {
        if (a == rhs.a) return (b < rhs.b);
        return (a < rhs.a);
    }

    // necessary
    // l1 <= *this <= l2であり, l1,l2が直線集合にあるときに自分が必要かどうか判定する関数.
    bool neccesary(const Line<T> &l1, const Line<T> &l2) const {
        if (l1.a == a) return false;
        if (l2.a == a) return true;
        return (l2.a - a) * (b - l1.b) < (a - l1.a) * (l2.b - b);
    }
};

// ConvexHullTrickMonotone
// 追加する直線の傾きに単調性がある場合のConvexHullTrick
template <typename T, bool MIN = true>
struct ConvexHullTrickMonotone {
    int n;
    T sgn = MIN ? T(1) : T(-1);
    deque<Line<T>> lines;

    ConvexHullTrickMonotone() : n(0) {
        lines.resize(0);
    }

    // add_right
    // y = ax + bなる直線を追加する.
    // 任意の l \in linesに対して l.a <= a である必要がある.
    // 計算量: 償却 O(1)
    void add_right(T a, T b) {
        if (MIN) return _add_right(a, b);
        return _add_left(a, b);
    }

    // add_left
    // y = ax + bなる直線を追加する.
    // 任意の l \in linesに対して a <= l.a である必要がある.
    // 計算量: 償却 O(1)
    void add_left(T a, T b) {
        if (MIN) return _add_left(a, b);
        return _add_right(a, b);
    }

    // query
    // min_{i=1,\dots,n} a_i x + b_i を求める.
    // 計算量: O(logn)
    // 制約: n > 0,すなわち少なくとも一つ直線が入っている.
    pair<T, Line<T>> query(T x) {
        assert(n > 0);
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (lines[m - 1].f(x) >= lines[m].f(x))
                l = m;
            else
                r = m;
        }
        Line<T> ab(sgn * lines[l].a, sgn * lines[l].b);
        return make_pair(sgn * lines[l].f(x), ab);
    }

    friend ostream &operator<<(ostream &os, const ConvexHullTrickMonotone<T, MIN> &cht) noexcept {
        for (int i = 0; i < cht.n; i++) {
            os << "l(" << cht.lines[i].a << ',' << cht.lines[i].b << "),";
        }
        return os;
    }

  private:
    // _add_right
    // y = ax + bなる直線を追加する.
    // MIN = trueの場合: 任意の l \in linesに対して l.a <= a である必要がある.
    // MIN = falseの場合: 任意の l \in linesに対して a <= l.a である必要がある.
    // 計算量: 償却 O(1)
    void _add_right(T a, T b) {
        Line<T> l(sgn * a, sgn * b);

        if (n <= 1) {
            lines.push_back(l);
            n++;
            return;
        }

        // lは不必要
        if (l.a == lines.back().a && l.b >= lines.back().b)
            return;

        while (n > 1 && !lines.back().neccesary(lines[n - 2], l)) {
            lines.pop_back();
            n--;
        }

        lines.push_back(l);
        n++;
        return;
    }

    // _add_left
    // y = ax + bなる直線を追加する.
    // MIN = true の場合: 任意の l \in linesに対して a <= l.a である必要がある.
    // MIN = false の場合: 任意の l \in linesに対して l.a <= a である必要がある.
    // 計算量: 償却 O(1)
    void _add_left(T a, T b) {
        Line<T> l(sgn * a, sgn * b);

        if (n <= 1) {
            lines.push_front(l);
            n++;
            return;
        }

        // lは不必要
        if (l.a == lines.front().a && l.b >= lines.front().b)
            return;

        while (n > 1 && !lines.front().neccesary(l, lines[1])) {
            lines.pop_front();
            n--;
        }

        lines.push_front(l);
        n++;
        return;
    }
};

} // namespace _cht

using namespace _cht;