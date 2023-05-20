---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: math/line.cpp
    title: math/line.cpp
  - icon: ':heavy_check_mark:'
    path: math/polygon.cpp
    title: math/polygon.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convex_hull.test.cpp
    title: test/convex_hull.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/isp.test.cpp
    title: test/isp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polygon_area.test.cpp
    title: test/polygon_area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polygon_diameter.test.cpp
    title: test/polygon_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/proj.test.cpp
    title: test/proj.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/reflection.test.cpp
    title: test/reflection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ss_distance.test.cpp
    title: test/ss_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ss_intersection1.test.cpp
    title: test/ss_intersection1.test.cpp
  - icon: ':x:'
    path: test/ss_intersection2.test.cpp
    title: test/ss_intersection2.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/point.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nconstexpr long double GEOMETRY_EPS = 1e-8;\n\n// sgn\n// a > 0\u306A\
    \u30891, a = 0\u306A\u30890,a < 0\u306A\u3089-1\u3092\u8FD4\u3059.\nconstexpr\
    \ inline int sgn(const long double a) { return (a < -GEOMETRY_EPS ? -1 : (a >\
    \ GEOMETRY_EPS ? 1 : 0)); }\nconstexpr inline int sgn(const int a) { return (a\
    \ < 0 ? -1 : (a > 0 ? 1 : 0)); }\n\n// 2\u6B21\u5143\u5EA7\u6A19\u30AF\u30E9\u30B9\
    \n// T = int,long double\u306A\u3069\ntemplate <typename T>\nstruct Point {\n\
    \    T x, y;\n    constexpr inline Point(T x = 0, T y = 0) : x(x), y(y) {}\n\n\
    \    // unary operator: +,-\n    constexpr inline Point operator+() const { return\
    \ *this; }\n    constexpr inline Point operator-() const { return Point(-x, -y);\
    \ }\n\n    // +=,-=,*=,/=\n    constexpr inline Point &operator+=(const Point\
    \ &q) {\n        x += q.x;\n        y += q.y;\n        return *this;\n    }\n\
    \    constexpr inline Point &operator-=(const Point &q) {\n        x -= q.x;\n\
    \        y -= q.y;\n        return *this;\n    }\n    template <typename U>\n\
    \    constexpr inline Point &operator*=(U a) {\n        x *= a;\n        y *=\
    \ a;\n        return *this;\n    }\n    template <typename U>\n    constexpr inline\
    \ Point &operator/=(U a) {\n        x /= a;\n        y /= a;\n        return *this;\n\
    \    }\n\n    // +,-,*,/\n    constexpr inline Point operator+(const Point &q)\
    \ const { return Point(*this) += q; }\n    constexpr inline Point operator-(const\
    \ Point &q) const { return Point(*this) -= q; }\n    template <typename U>\n \
    \   constexpr inline Point operator*(const U &a) const { return Point(*this) *=\
    \ a; }\n    template <typename U>\n    constexpr inline Point operator/(const\
    \ U &a) const { return Point(*this) /= a; }\n\n    // <,> \u306E\u6BD4\u8F03\u306F\
    \u8F9E\u66F8\u9806\u306E\u6BD4\u8F03, \u3064\u307E\u308Ax,y\u306E\u9806\u306B\u5927\
    \u304D\u3044\u65B9\u3092\u78BA\u8A8D\u3059\u308B.\n    inline bool operator<(const\
    \ Point &q) const { return (sgn(x - q.x) != 0 ? sgn(x - q.x) < 0 : sgn(y - q.y)\
    \ < 0); }\n    inline bool operator>(const Point &q) const { return (sgn(x - q.x)\
    \ != 0 ? sgn(x - q.x) > 0 : sgn(y - q.y) > 0); }\n    inline bool operator==(const\
    \ Point &q) const { return (sgn(x - q.x) == 0 && sgn(y - q.y) == 0); }\n\n   \
    \ friend ostream &operator<<(ostream &os, const Point &p) { return os << p.x <<\
    \ ' ' << p.y; }\n    friend istream &operator>>(istream &is, Point &p) { return\
    \ is >> p.x >> p.y; }\n};\n\n// *,/\ntemplate <typename T, typename U>\ninline\
    \ Point<T> operator*(const U &s, const Point<T> &p) { return {s * p.x, s * p.y};\
    \ }\ntemplate <typename T, typename U>\ninline Point<T> operator/(const U &s,\
    \ const Point<T> &p) { return {p.x / s, p.y / s}; }\n\n// dot\n// p,q\u306E\u5185\
    \u7A4D\u3092\u8A08\u7B97\u3059\u308B.\ntemplate <typename T>\nconstexpr inline\
    \ T dot(const Point<T> &p, const Point<T> &q) { return p.x * q.x + p.y * q.y;\
    \ }\n\n// cross\n// p,q\u306E\u5916\u7A4D\u3092\u8A08\u7B97\u3059\u308B\ntemplate\
    \ <typename T>\nconstexpr inline T cross(const Point<T> &p, const Point<T> &q)\
    \ { return p.x * q.y - q.x * p.y; }\n\n// length2\n// \u30D9\u30AF\u30C8\u30EB\
    p\u306E\u9577\u3055(\u539F\u70B9\u304B\u3089\u306E\u8DDD\u96E2)\u306E2\u4E57\u3092\
    \u6C42\u3081\u308B.\ntemplate <typename T>\nconstexpr inline T length2(const Point<T>\
    \ &p) { return dot(p, p); }\n\n// length\n// \u30D9\u30AF\u30C8\u30EBp\u306E\u9577\
    \u3055(\u539F\u70B9\u304B\u3089\u306E\u8DDD\u96E2)\u3092\u6C42\u3081\u308B.\n\
    template <typename T>\ninline long double length(const Point<T> &p) { return sqrt((long\
    \ double)length2(p)); }\n\n// dist\n// \u70B9p\u3068\u70B9q\u306E\u9593\u306E\u8DDD\
    \u96E2\u3092\u6C42\u3081\u308B.\ntemplate <typename T>\ninline long double dist(const\
    \ Point<T> &p, const Point<T> &q) { return length(p - q); }\n\n// sgn_area\n//\
    \ p,q,r\u304C\u3064\u304F\u308B\u4E09\u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\
    \u9762\u7A4D\ntemplate <typename T>\nconstexpr inline long double sgn_area(const\
    \ Point<T> &p, const Point<T> &q, const Point<T> &r) { return (long double)cross(q\
    \ - p, r - p) / 2.0; }\n\n// area\n// p,q,r\u304C\u3064\u304F\u308B\u4E09\u89D2\
    \u5F62\u306E\u9762\u7A4D\ntemplate <typename T>\nconstexpr inline long double\
    \ area(const Point<T> &p, const Point<T> &q, const Point<T> &r) { return abs(sgn_area(p,\
    \ q, r)); }\n\n// normalize\n// \u70B9p\u3092\u9577\u30551\u306B\u6B63\u898F\u5316\
    \u3057\u305F\u70B9\u3092\u8FD4\u3059.\ntemplate <typename T>\ninline Point<long\
    \ double> normalize(const Point<T> &p) { return (Point<long double>)p / length(p);\
    \ }\n\n// rotation\n// \u70B9p\u3092\u53CD\u6642\u8A08\u56DE\u308A\u306Barg\u3060\
    \u3051\u56DE\u8EE2\u3055\u305B\u305F\u70B9\u3092\u8FD4\u3059. (arg\u306Frad\u3067\
    \u6E2C\u308B)\ntemplate <typename T>\ninline Point<long double> rotation(const\
    \ Point<T> &p, double arg) { return Point(cos(arg) * p.x - sin(arg) * p.y, sin(arg)\
    \ * p.x + cos(arg) * p.y); }\n\n// angle\n// \u70B9p\u306Ex\u8EF8\u306E\u6B63\u306E\
    \u65B9\u5411\u304B\u3089\u53CD\u6642\u8A08\u56DE\u308A\u306B\u6E2C\u3063\u305F\
    \u89D2\u5EA6\u3092[-pi,pi]\u3067\u8FD4\u3059.\ntemplate <typename T>\ninline long\
    \ double angle(const Point<T> &p) { return atan2(p.y, p.x); }\n\n// rot90\n//\
    \ \u70B9p\u3092\u53CD\u6642\u8A08\u56DE\u308A\u306B90\u5EA6\u56DE\u8EE2\ntemplate\
    \ <typename T>\nconstexpr inline Point<T> rot90(const Point<T> &p) { return Point(-p.y,\
    \ p.x); }\n\n// iSP\n// \u7570\u306A\u308B3\u70B9a,b,c\u306E\u4F4D\u7F6E\u95A2\
    \u4FC2\u3092\u8FD4\u3059.\ntemplate <typename T>\nint iSP(const Point<T> &a, const\
    \ Point<T> &b, const Point<T> &c) {\n    if (sgn(cross(c - b, a - b)) > 0) return\
    \ 1;  // ab bc __/: +1\n    if (sgn(cross(c - b, a - b)) < 0) return -1; // ab\
    \ bc --\\: -1\n    if (sgn(dot(a - b, c - b)) < 0) return 2;    // abc   ---:\
    \ +2\n    if (sgn(dot(a - c, b - c)) < 0) return -2;   // acb   ---: -2\n    return\
    \ 0;                                    // bac   ---:  0\n}\n\n// example:\n//\
    \ using P = Point<int>;\n// using P = Point<long double>;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nconstexpr\
    \ long double GEOMETRY_EPS = 1e-8;\n\n// sgn\n// a > 0\u306A\u30891, a = 0\u306A\
    \u30890,a < 0\u306A\u3089-1\u3092\u8FD4\u3059.\nconstexpr inline int sgn(const\
    \ long double a) { return (a < -GEOMETRY_EPS ? -1 : (a > GEOMETRY_EPS ? 1 : 0));\
    \ }\nconstexpr inline int sgn(const int a) { return (a < 0 ? -1 : (a > 0 ? 1 :\
    \ 0)); }\n\n// 2\u6B21\u5143\u5EA7\u6A19\u30AF\u30E9\u30B9\n// T = int,long double\u306A\
    \u3069\ntemplate <typename T>\nstruct Point {\n    T x, y;\n    constexpr inline\
    \ Point(T x = 0, T y = 0) : x(x), y(y) {}\n\n    // unary operator: +,-\n    constexpr\
    \ inline Point operator+() const { return *this; }\n    constexpr inline Point\
    \ operator-() const { return Point(-x, -y); }\n\n    // +=,-=,*=,/=\n    constexpr\
    \ inline Point &operator+=(const Point &q) {\n        x += q.x;\n        y +=\
    \ q.y;\n        return *this;\n    }\n    constexpr inline Point &operator-=(const\
    \ Point &q) {\n        x -= q.x;\n        y -= q.y;\n        return *this;\n \
    \   }\n    template <typename U>\n    constexpr inline Point &operator*=(U a)\
    \ {\n        x *= a;\n        y *= a;\n        return *this;\n    }\n    template\
    \ <typename U>\n    constexpr inline Point &operator/=(U a) {\n        x /= a;\n\
    \        y /= a;\n        return *this;\n    }\n\n    // +,-,*,/\n    constexpr\
    \ inline Point operator+(const Point &q) const { return Point(*this) += q; }\n\
    \    constexpr inline Point operator-(const Point &q) const { return Point(*this)\
    \ -= q; }\n    template <typename U>\n    constexpr inline Point operator*(const\
    \ U &a) const { return Point(*this) *= a; }\n    template <typename U>\n    constexpr\
    \ inline Point operator/(const U &a) const { return Point(*this) /= a; }\n\n \
    \   // <,> \u306E\u6BD4\u8F03\u306F\u8F9E\u66F8\u9806\u306E\u6BD4\u8F03, \u3064\
    \u307E\u308Ax,y\u306E\u9806\u306B\u5927\u304D\u3044\u65B9\u3092\u78BA\u8A8D\u3059\
    \u308B.\n    inline bool operator<(const Point &q) const { return (sgn(x - q.x)\
    \ != 0 ? sgn(x - q.x) < 0 : sgn(y - q.y) < 0); }\n    inline bool operator>(const\
    \ Point &q) const { return (sgn(x - q.x) != 0 ? sgn(x - q.x) > 0 : sgn(y - q.y)\
    \ > 0); }\n    inline bool operator==(const Point &q) const { return (sgn(x -\
    \ q.x) == 0 && sgn(y - q.y) == 0); }\n\n    friend ostream &operator<<(ostream\
    \ &os, const Point &p) { return os << p.x << ' ' << p.y; }\n    friend istream\
    \ &operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }\n};\n\n// *,/\n\
    template <typename T, typename U>\ninline Point<T> operator*(const U &s, const\
    \ Point<T> &p) { return {s * p.x, s * p.y}; }\ntemplate <typename T, typename\
    \ U>\ninline Point<T> operator/(const U &s, const Point<T> &p) { return {p.x /\
    \ s, p.y / s}; }\n\n// dot\n// p,q\u306E\u5185\u7A4D\u3092\u8A08\u7B97\u3059\u308B\
    .\ntemplate <typename T>\nconstexpr inline T dot(const Point<T> &p, const Point<T>\
    \ &q) { return p.x * q.x + p.y * q.y; }\n\n// cross\n// p,q\u306E\u5916\u7A4D\u3092\
    \u8A08\u7B97\u3059\u308B\ntemplate <typename T>\nconstexpr inline T cross(const\
    \ Point<T> &p, const Point<T> &q) { return p.x * q.y - q.x * p.y; }\n\n// length2\n\
    // \u30D9\u30AF\u30C8\u30EBp\u306E\u9577\u3055(\u539F\u70B9\u304B\u3089\u306E\u8DDD\
    \u96E2)\u306E2\u4E57\u3092\u6C42\u3081\u308B.\ntemplate <typename T>\nconstexpr\
    \ inline T length2(const Point<T> &p) { return dot(p, p); }\n\n// length\n// \u30D9\
    \u30AF\u30C8\u30EBp\u306E\u9577\u3055(\u539F\u70B9\u304B\u3089\u306E\u8DDD\u96E2\
    )\u3092\u6C42\u3081\u308B.\ntemplate <typename T>\ninline long double length(const\
    \ Point<T> &p) { return sqrt((long double)length2(p)); }\n\n// dist\n// \u70B9\
    p\u3068\u70B9q\u306E\u9593\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B.\ntemplate\
    \ <typename T>\ninline long double dist(const Point<T> &p, const Point<T> &q)\
    \ { return length(p - q); }\n\n// sgn_area\n// p,q,r\u304C\u3064\u304F\u308B\u4E09\
    \u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\u9762\u7A4D\ntemplate <typename T>\n\
    constexpr inline long double sgn_area(const Point<T> &p, const Point<T> &q, const\
    \ Point<T> &r) { return (long double)cross(q - p, r - p) / 2.0; }\n\n// area\n\
    // p,q,r\u304C\u3064\u304F\u308B\u4E09\u89D2\u5F62\u306E\u9762\u7A4D\ntemplate\
    \ <typename T>\nconstexpr inline long double area(const Point<T> &p, const Point<T>\
    \ &q, const Point<T> &r) { return abs(sgn_area(p, q, r)); }\n\n// normalize\n\
    // \u70B9p\u3092\u9577\u30551\u306B\u6B63\u898F\u5316\u3057\u305F\u70B9\u3092\u8FD4\
    \u3059.\ntemplate <typename T>\ninline Point<long double> normalize(const Point<T>\
    \ &p) { return (Point<long double>)p / length(p); }\n\n// rotation\n// \u70B9\
    p\u3092\u53CD\u6642\u8A08\u56DE\u308A\u306Barg\u3060\u3051\u56DE\u8EE2\u3055\u305B\
    \u305F\u70B9\u3092\u8FD4\u3059. (arg\u306Frad\u3067\u6E2C\u308B)\ntemplate <typename\
    \ T>\ninline Point<long double> rotation(const Point<T> &p, double arg) { return\
    \ Point(cos(arg) * p.x - sin(arg) * p.y, sin(arg) * p.x + cos(arg) * p.y); }\n\
    \n// angle\n// \u70B9p\u306Ex\u8EF8\u306E\u6B63\u306E\u65B9\u5411\u304B\u3089\u53CD\
    \u6642\u8A08\u56DE\u308A\u306B\u6E2C\u3063\u305F\u89D2\u5EA6\u3092[-pi,pi]\u3067\
    \u8FD4\u3059.\ntemplate <typename T>\ninline long double angle(const Point<T>\
    \ &p) { return atan2(p.y, p.x); }\n\n// rot90\n// \u70B9p\u3092\u53CD\u6642\u8A08\
    \u56DE\u308A\u306B90\u5EA6\u56DE\u8EE2\ntemplate <typename T>\nconstexpr inline\
    \ Point<T> rot90(const Point<T> &p) { return Point(-p.y, p.x); }\n\n// iSP\n//\
    \ \u7570\u306A\u308B3\u70B9a,b,c\u306E\u4F4D\u7F6E\u95A2\u4FC2\u3092\u8FD4\u3059\
    .\ntemplate <typename T>\nint iSP(const Point<T> &a, const Point<T> &b, const\
    \ Point<T> &c) {\n    if (sgn(cross(c - b, a - b)) > 0) return 1;  // ab bc __/:\
    \ +1\n    if (sgn(cross(c - b, a - b)) < 0) return -1; // ab bc --\\: -1\n   \
    \ if (sgn(dot(a - b, c - b)) < 0) return 2;    // abc   ---: +2\n    if (sgn(dot(a\
    \ - c, b - c)) < 0) return -2;   // acb   ---: -2\n    return 0;             \
    \                       // bac   ---:  0\n}\n\n// example:\n// using P = Point<int>;\n\
    // using P = Point<long double>;"
  dependsOn: []
  isVerificationFile: false
  path: math/point.cpp
  requiredBy:
  - math/line.cpp
  - math/polygon.cpp
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/convex_hull.test.cpp
  - test/polygon_diameter.test.cpp
  - test/ss_distance.test.cpp
  - test/ss_intersection2.test.cpp
  - test/reflection.test.cpp
  - test/ss_intersection1.test.cpp
  - test/isp.test.cpp
  - test/proj.test.cpp
  - test/polygon_area.test.cpp
documentation_of: math/point.cpp
layout: document
redirect_from:
- /library/math/point.cpp
- /library/math/point.cpp.html
title: math/point.cpp
---
