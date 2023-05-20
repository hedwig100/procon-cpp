---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/line.cpp
    title: math/line.cpp
  - icon: ':question:'
    path: math/point.cpp
    title: math/point.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-9
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D
  bundledCode: "#line 1 \"test/ss_distance.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D\"\
    \n#define ERROR 1e-9\n#line 3 \"math/line.cpp\"\nusing namespace std;\n\n#line\
    \ 3 \"math/point.cpp\"\nusing namespace std;\n\nconstexpr long double GEOMETRY_EPS\
    \ = 1e-8;\n\n// sgn\n// a > 0\u306A\u30891, a = 0\u306A\u30890,a < 0\u306A\u3089\
    -1\u3092\u8FD4\u3059.\nconstexpr inline int sgn(const long double a) { return\
    \ (a < -GEOMETRY_EPS ? -1 : (a > GEOMETRY_EPS ? 1 : 0)); }\nconstexpr inline int\
    \ sgn(const int a) { return (a < 0 ? -1 : (a > 0 ? 1 : 0)); }\n\n// 2\u6B21\u5143\
    \u5EA7\u6A19\u30AF\u30E9\u30B9\n// T = int,long double\u306A\u3069\ntemplate <typename\
    \ T>\nstruct Point {\n    T x, y;\n    constexpr inline Point(T x = 0, T y = 0)\
    \ : x(x), y(y) {}\n\n    // unary operator: +,-\n    constexpr inline Point operator+()\
    \ const { return *this; }\n    constexpr inline Point operator-() const { return\
    \ Point(-x, -y); }\n\n    // +=,-=,*=,/=\n    constexpr inline Point &operator+=(const\
    \ Point &q) {\n        x += q.x;\n        y += q.y;\n        return *this;\n \
    \   }\n    constexpr inline Point &operator-=(const Point &q) {\n        x -=\
    \ q.x;\n        y -= q.y;\n        return *this;\n    }\n    template <typename\
    \ U>\n    constexpr inline Point &operator*=(U a) {\n        x *= a;\n       \
    \ y *= a;\n        return *this;\n    }\n    template <typename U>\n    constexpr\
    \ inline Point &operator/=(U a) {\n        x /= a;\n        y /= a;\n        return\
    \ *this;\n    }\n\n    // +,-,*,/\n    constexpr inline Point operator+(const\
    \ Point &q) const { return Point(*this) += q; }\n    constexpr inline Point operator-(const\
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
    \ using P = Point<int>;\n// using P = Point<long double>;\n#line 6 \"math/line.cpp\"\
    \n\n/* Line */\n\nconstexpr long double GEOMETRY_INFTY = 1e9;\n\n// \u7121\u9650\
    \u9060\u70B9\ntemplate <typename T>\nconstexpr Point<T> INFTY(GEOMETRY_INFTY,\
    \ GEOMETRY_INFTY);\n\n// \u76F4\u7DDA\ntemplate <typename T>\nstruct Line {\n\
    \    Point<T> begin, end;\n    Line() = default;\n    Line(const Point<T> &begin,\
    \ const Point<T> &end) : begin(begin), end(end) {}\n\n    constexpr inline Point<T>\
    \ vec() const { return end - begin; }\n    constexpr inline Point<T> countervec()\
    \ const { return begin - end; }\n};\n\n// \u534A\u76F4\u7DDA\ntemplate <typename\
    \ T>\nusing Ray = Line<T>;\n\n// \u7DDA\u5206\ntemplate <typename T>\nusing Segment\
    \ = Line<T>;\n\n// ll_intersection\n// \u76F4\u7DDA\u540C\u58EB\u306E\u4EA4\u70B9\
    \u3092\u8FD4\u3059.\ntemplate <typename T>\nPoint<T> ll_intersection(const Line<T>\
    \ &l1, const Line<T> &l2) {\n    if (sgn(cross(l1.vec(), l2.vec())) == 0) return\
    \ INFTY<T>;                                      // parallel or partially matched\n\
    \    return l1.begin + l1.vec() * cross(l2.vec(), l2.begin - l1.begin) / cross(l2.vec(),\
    \ l1.vec()); // Intersection\n}\n\n// ss_intersection\n// \u7DDA\u5206\u540C\u58EB\
    \u306E\u4EA4\u70B9\u3092\u6C42\u3081\u308B. (\u7DDA\u5206\u304C\u4EA4\u308F\u308B\
    \u304B\u3069\u3046\u304B, \u4EA4\u70B9)\u3092\u8FD4\u3059.\ntemplate <typename\
    \ T>\npair<bool, Point<T>> ss_intersection(const Segment<T> &s1, const Segment<T>\
    \ &s2) {\n    bool is_intersect = (iSP(s2.begin, s1.begin, s1.end) * iSP(s2.end,\
    \ s1.begin, s1.end) <= 0 && iSP(s1.begin, s2.begin, s2.end) * iSP(s1.end, s2.begin,\
    \ s2.end) <= 0);\n    return {is_intersect, ll_intersection(s1, s2)};\n}\n\n//\
    \ sr_intersection\n// \u7DDA\u5206\u3068\u534A\u76F4\u7DDA\u306E\u4EA4\u70B9\u3092\
    \u6C42\u3081\u308B.\ntemplate <typename T>\npair<bool, Point<T>> sr_intersection(const\
    \ Segment<T> &s, const Ray<T> &r) {\n    Point ret = ll_intersection(s, r);\n\
    \    if (ret == INFTY<T>) return {false, ret};\n    Point sv1 = s.begin - ret,\
    \ sv2 = s.end - ret;\n    Point rv1 = ret - r.begin, rv2 = r.end - r.begin;\n\
    \    if (sgn(dot(sv1, sv2)) <= 0 && sgn(dot(rv1, rv2)) > 0) return {true, ret};\n\
    \    return {false, ret};\n}\n\n// ison\n// \u70B9p\u304C\u7DDA\u5206s\u4E0A\u306E\
    \u70B9\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B.\ntemplate <typename\
    \ T>\nconstexpr inline bool ison(const Point<T> &p, const Segment<T> &s) { return\
    \ iSP(p, s.begin, s.end) == 0; }\n\n// pl_distance\n// \u70B9p\u3068\u76F4\u7DDA\
    l\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B.\ntemplate <typename T>\nlong double\
    \ pl_distance(const Point<T> &p, const Line<T> &l) { return abs((long double)cross(l.vec(),\
    \ p - l.begin) / length(l.vec())); }\n\n// ps_distance\n// \u70B9p\u3068\u7DDA\
    \u5206s\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B.\ntemplate <typename T>\nlong\
    \ double ps_distance(const Point<T> &p, const Segment<T> &s) {\n    if (sgn(dot(s.vec(),\
    \ p - s.begin)) < 0 || sgn(dot(s.countervec(), p - s.end)) < 0) {\n        return\
    \ min(dist(p, s.begin), dist(p, s.end));\n    }\n    return pl_distance(p, s);\n\
    }\n\n// ss_distance\n// \u7DDA\u5206s1\u3068\u7DDA\u5206s2\u306E\u8DDD\u96E2\u3092\
    \u6C42\u3081\u308B.\ntemplate <typename T>\nlong double ss_distance(const Segment<T>\
    \ &s1, const Segment<T> &s2) {\n    if (ss_intersection(s1, s2).first) return\
    \ 0;\n    return min({ps_distance(s1.begin, s2), ps_distance(s1.end, s2), ps_distance(s2.begin,\
    \ s1), ps_distance(s2.end, s1)});\n}\n\n// proj\n// \u30D9\u30AF\u30C8\u30EBp\u3092\
    \u76F4\u7DDAl\u306B\u5C04\u5F71\u3057\u305F\u70B9\u3092\u8FD4\u3059.\nPoint<long\
    \ double> proj(const Point<long double> &p, const Line<long double> &l) { return\
    \ l.begin + normalize(l.vec()) * (dot(l.vec(), p - l.begin) / length(l.vec()));\
    \ }\n\n// reflection\n// \u30D9\u30AF\u30C8\u30EBp\u3092\u76F4\u7DDAl\u306B\u5BFE\
    \u3057\u3066\u53CD\u8EE2\u3055\u305B\u305F\u70B9\u3092\u8FD4\u3059.\nPoint<long\
    \ double> reflection(const Point<long double> &p, const Line<long double> &l)\
    \ { return proj(p, l) * 2 - p; }\n\n// vertical_bisector\n// \u70B9p,q\u306E\u5782\
    \u76F4\u4E8C\u7B49\u5206\u7DDA\u3092\u6C42\u3081\u308B.\nLine<long double> vertical_bisector(const\
    \ Point<long double> &p, const Point<long double> &q) {\n    Point mid = (p +\
    \ q) / 2, vec = rot90(p - q);\n    return Line(mid, mid + vec);\n}\n\n// example:\n\
    // using P = Point<int>;\n// using L = Line<int>;\n// using S = Segment<int>;\n\
    // using R = Ray<int>;\n//\n// using P = Point<long double>;\n// using L = Line<long\
    \ double>;\n// using S = Segment<long double>;\n// using R = Ray<long double>;\n\
    #line 8 \"test/ss_distance.test.cpp\"\n\nusing P = Point<long double>;\nusing\
    \ L = Line<long double>;\nusing S = Segment<long double>;\nusing R = Ray<long\
    \ double>;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n\n    int q;\n    cin >> q;\n    while\
    \ (q--) {\n        P p0, p1, p2, p3;\n        cin >> p0 >> p1 >> p2 >> p3;\n \
    \       S s1 = S(p0, p1), s2 = S(p2, p3);\n        cout << ss_distance(s1, s2)\
    \ << '\\n';\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D\"\
    \n#define ERROR 1e-9\n#include \"../math/line.cpp\"\n#include \"../math/point.cpp\"\
    \n\nusing P = Point<long double>;\nusing L = Line<long double>;\nusing S = Segment<long\
    \ double>;\nusing R = Ray<long double>;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(20);\n\n\
    \    int q;\n    cin >> q;\n    while (q--) {\n        P p0, p1, p2, p3;\n   \
    \     cin >> p0 >> p1 >> p2 >> p3;\n        S s1 = S(p0, p1), s2 = S(p2, p3);\n\
    \        cout << ss_distance(s1, s2) << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - math/line.cpp
  - math/point.cpp
  isVerificationFile: true
  path: test/ss_distance.test.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ss_distance.test.cpp
layout: document
redirect_from:
- /verify/test/ss_distance.test.cpp
- /verify/test/ss_distance.test.cpp.html
title: test/ss_distance.test.cpp
---
