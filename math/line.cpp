#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "point.cpp"

/* Line */

constexpr long double GEOMETRY_INFTY = 1e9;

// 無限遠点
template <typename T>
constexpr Point<T> INFTY(GEOMETRY_INFTY, GEOMETRY_INFTY);

// 直線
template <typename T>
struct Line {
    Point<T> begin, end;
    Line() = default;
    Line(const Point<T> &begin, const Point<T> &end) : begin(begin), end(end) {}

    constexpr inline Point<T> vec() const { return end - begin; }
};

// 半直線
template <typename T>
using Ray = Line<T>;

// 線分
template <typename T>
using Segment = Line<T>;

// ll_intersection
// 直線同士の交点を返す.
template <typename T>
Point<T> ll_intersection(const Line<T> &l1, const Line<T> &l2) {
    if (sgn(cross(l1.vec(), l2.vec())) == 0) return INFTY<T>;                                      // parallel or partially matched
    return l1.begin + l1.vec() * cross(l2.vec(), l2.begin - l1.begin) / cross(l2.vec(), l1.vec()); // Intersection
}

// ss_intersection
// 線分同士の交点を求める. (線分が交わるかどうか, 交点)を返す.
template <typename T>
pair<bool, Point<T>> ss_intersection(const Segment<T> &s1, const Segment<T> &s2) {
    bool is_intersect = (iSP(s2.begin, s1.begin, s1.end) * iSP(s2.end, s1.begin, s1.end) <= 0 && iSP(s1.begin, s2.begin, s2.end) * iSP(s1.end, s2.begin, s2.end) <= 0);
    return {is_intersect, ll_intersection(s1, s2)};
}

// sr_intersection
// 線分と半直線の交点を求める.
template <typename T>
pair<bool, Point<T>> sr_intersection(const Segment<T> &s, const Ray<T> &r) {
    Point ret = ll_intersection(s, r);
    if (ret == INFTY<T>) return {false, ret};
    Point sv1 = s.begin - ret, sv2 = s.end - ret;
    Point rv1 = ret - r.begin, rv2 = r.end - r.begin;
    if (sgn(dot(sv1, sv2)) <= 0 && sgn(dot(rv1, rv2)) > 0) return {true, ret};
    return {false, ret};
}

// ison
// 点pが線分s上の点かどうかを判定する.
template <typename T>
constexpr inline bool ison(const Point<T> &p, const Segment<T> &s) { return iSP(p, s.begin, s.end) == 0; }

// pl_distance
// 点pと直線lの距離を求める.
template <typename T>
long double pl_distance(const Point<T> &p, const Line<T> &l) { return abs((long double)cross(l.vec(), p - l.begin) / length(l.vec())); }

// ps_distance
// 点pと線分sの距離を求める.
template <typename T>
long double ps_distance(const Point<T> &p, const Segment<T> &s) { return min({length(p - s.begin), length(p - s.end), pl_distance(p, s)}); }

// proj
// ベクトルpを直線lに射影した点を返す.
Point<long double> proj(const Point<long double> &p, const Line<long double> &l) { return l.begin + normalize(l.vec()) * (dot(l.vec(), p - l.begin) / length(l.vec())); }

// reflection
// ベクトルpを直線lに対して反転させた点を返す.
Point<long double> reflection(const Point<long double> &p, const Line<long double> &l) { return proj(p, l) * 2 - p; }

// vertical_bisector
// 点p,qの垂直二等分線を求める.
Line<long double> vertical_bisector(const Point<long double> &p, const Point<long double> &q) {
    Point mid = (p + q) / 2, vec = rot90(p - q);
    return Line(mid, mid + vec);
}

// example:
// using L = Line<int>;
// using L = Line<long double>;