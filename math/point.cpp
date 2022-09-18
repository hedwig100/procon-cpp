#pragma once
#include <bits/stdc++.h>
using namespace std;

constexpr long double GEOMETRY_EPS = 1e-8;

// sgn
// a > 0なら1, a = 0なら0,a < 0なら-1を返す.
constexpr inline int sgn(const double a) { return (a < -GEOMETRY_EPS ? -1 : (a > GEOMETRY_EPS ? 1 : 0)); }
constexpr inline int sgn(const int a) { return (a < 0 ? -1 : (a > 0 ? 1 : 0)); }

// 2次元座標クラス
// T = int,long doubleなど
template <typename T>
struct Point {
    T x, y;
    constexpr inline Point(T x = 0, T y = 0) : x(x), y(y) {}

    // unary operator: +,-
    constexpr inline Point operator+() const { return *this; }
    constexpr inline Point operator-() const { return Point(-x, -y); }

    // +=,-=,*=,/=
    constexpr inline Point &operator+=(const Point &q) {
        x += q.x;
        y += q.y;
        return *this;
    }
    constexpr inline Point &operator-=(const Point &q) {
        x -= q.x;
        y -= q.y;
        return *this;
    }
    template <typename U>
    constexpr inline Point &operator*=(U a) {
        x *= a;
        y *= a;
        return *this;
    }
    template <typename U>
    constexpr inline Point &operator/=(U a) {
        x /= a;
        y /= a;
        return *this;
    }

    // +,-,*,/
    constexpr inline Point operator+(const Point &q) const { return Point(*this) += q; }
    constexpr inline Point operator-(const Point &q) const { return Point(*this) -= q; }
    template <typename U>
    constexpr inline Point operator*(const U &a) const { return Point(*this) *= a; }
    template <typename U>
    constexpr inline Point operator/(const U &a) const { return Point(*this) /= a; }

    // <,> の比較は辞書順の比較, つまりx,yの順に大きい方を確認する.
    inline bool operator<(const Point &q) const { return (sgn(x - q.x) != 0 ? sgn(x - q.x) < 0 : sgn(y - q.y) < 0); }
    inline bool operator>(const Point &q) const { return (sgn(x - q.x) != 0 ? sgn(x - q.x) > 0 : sgn(y - q.y) > 0); }
    inline bool operator==(const Point &q) const { return (sgn(x - q.x) == 0 && sgn(y - q.y) == 0); }

    friend ostream &operator<<(ostream &os, const Point &p) { return os << p.x << ' ' << p.y; }
    friend istream &operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }
};

// *,/
template <typename T, typename U>
inline Point<T> operator*(const U &s, const Point<T> &p) { return {s * p.x, s * p.y}; }
template <typename T, typename U>
inline Point<T> operator/(const U &s, const Point<T> &p) { return {p.x / s, p.y / s}; }

// dot
// p,qの内積を計算する.
template <typename T>
constexpr inline T dot(const Point<T> &p, const Point<T> &q) { return p.x * q.x + p.y * q.y; }

// cross
// p,qの外積を計算する
template <typename T>
constexpr inline T cross(const Point<T> &p, const Point<T> &q) { return p.x * q.y - q.x * p.y; }

// length2
// ベクトルpの長さ(原点からの距離)の2乗を求める.
template <typename T>
constexpr inline T length2(const Point<T> &p) { return dot(p, p); }

// length
// ベクトルpの長さ(原点からの距離)を求める.
template <typename T>
inline double length(const Point<T> &p) { return sqrt(length2(p)); }

// dist
// 点pと点qの間の距離を求める.
template <typename T>
inline double dist(const Point<T> &p, const Point<T> &q) { return length(p - q); }

// sgn_area
// p,q,rがつくる三角形の符号付き面積
template <typename T>
constexpr inline double sgn_area(const Point<T> &p, const Point<T> &q, const Point<T> &r) { return cross(q - p, r - p) / 2.0; }

// area
// p,q,rがつくる三角形の面積
template <typename T>
constexpr inline double area(const Point<T> &p, const Point<T> &q, const Point<T> &r) { return abs(sgn_area(p, q, r)); }

// normalize
// 点pを長さ1に正規化した点を返す.
template <typename T>
inline Point<long double> normalize(const Point<T> &p) { return p / length(p); }

// rotation
// 点pを反時計回りにargだけ回転させた点を返す. (argはradで測る)
template <typename T>
inline Point<long double> rotation(const Point<T> &p, double arg) { return Point(cos(arg) * p.x - sin(arg) * p.y, sin(arg) * p.x + cos(arg) * p.y); }

// angle
// 点pのx軸の正の方向から反時計回りに測った角度を[-pi,pi]で返す.
template <typename T>
inline double angle(const Point<T> &p) { return atan2(p.y, p.x); }

// rot90
// 点pを反時計回りに90度回転
template <typename T>
constexpr inline Point<T> rot90(const Point<T> &p) { return Point(-p.y, p.x); }

// iSP
// 点a,b,cの位置関係を返す.
template <typename T>
int iSP(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
    if (sgn(cross(c - b, a - b)) > 0) return 1;  // ab bc __/: +1
    if (sgn(cross(c - b, a - b)) < 0) return -1; // ab bc --\: -1
    if (sgn(dot(a - b, c - b)) < 0) return 2;    // abc   ---: +2
    if (sgn(dot(a - c, b - c)) < 0) return -2;   // acb   ---: -2
    return 0;                                    // bac   ---:  0
}

// example:
// using P = Point<int>;
// using P = Point<long double>;