---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/point.cpp
    title: math/point.cpp
  - icon: ':heavy_check_mark:'
    path: math/polygon.cpp
    title: math/polygon.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A
  bundledCode: "#line 1 \"test/polygon_area.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A\"\
    \n#line 3 \"math/polygon.cpp\"\nusing namespace std;\n\n#line 3 \"math/point.cpp\"\
    \nusing namespace std;\n\nconstexpr long double GEOMETRY_EPS = 1e-8;\n\n// sgn\n\
    // a > 0\u306A\u30891, a = 0\u306A\u30890,a < 0\u306A\u3089-1\u3092\u8FD4\u3059\
    .\nconstexpr inline int sgn(const long double a) { return (a < -GEOMETRY_EPS ?\
    \ -1 : (a > GEOMETRY_EPS ? 1 : 0)); }\nconstexpr inline int sgn(const int a) {\
    \ return (a < 0 ? -1 : (a > 0 ? 1 : 0)); }\n\n// 2\u6B21\u5143\u5EA7\u6A19\u30AF\
    \u30E9\u30B9\n// T = int,long double\u306A\u3069\ntemplate <typename T>\nstruct\
    \ Point {\n    T x, y;\n    constexpr inline Point(T x = 0, T y = 0) : x(x), y(y)\
    \ {}\n\n    // unary operator: +,-\n    constexpr inline Point operator+() const\
    \ { return *this; }\n    constexpr inline Point operator-() const { return Point(-x,\
    \ -y); }\n\n    // +=,-=,*=,/=\n    constexpr inline Point &operator+=(const Point\
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
    \ using P = Point<int>;\n// using P = Point<long double>;\n#line 6 \"math/polygon.cpp\"\
    \n\n// convex_hull\n// \u70B9\u96C6\u5408points\u306E\u51F8\u5305\u3092\u6C42\u3081\
    \u308B.\n// \u6C42\u3081\u305F\u51F8\u5305\u306F\u6700\u3082\u5DE6\u306B\u3042\
    \u308B\u3082\u306E\u306E\u3046\u3061\u6700\u3082\u4E0B\u306B\u3042\u308B\u3082\
    \u306E\u304B\u3089\u9806\u306B\u53CD\u6642\u8A08\u56DE\u308A\u306B\u4E26\u3093\
    \u3067\u3044\u308B.\ntemplate <typename T>\nvector<Point<T>> convex_hull(vector<Point<T>>\
    \ points) {\n    sort(points.begin(), points.end());\n    int n = (int)points.size(),\
    \ k = 0;\n    vector<Point<T>> convex(2 * n);\n    for (int i = 0; i < n; i++)\
    \ {\n        while (k > 1 && iSP(convex[k - 2], convex[k - 1], points[i]) == -1)\n\
    \            k--;\n        convex[k++] = points[i];\n    }\n    for (int i = n\
    \ - 2, t = k; i >= 0; i--) {\n        while (k > t && iSP(convex[k - 2], convex[k\
    \ - 1], points[i]) == -1)\n            k--;\n        convex[k++] = points[i];\n\
    \    }\n    convex.resize(k - 1);\n    return convex;\n}\n\n// polygon_area\n\
    // points\u306En\u70B9\u304B\u3089\u306A\u308B\u591A\u89D2\u5F62G\u306E\u9762\u7A4D\
    \u3092\u6C42\u3081\u308B.\n// G\u306Fpoints[i],points[(i + 1)%n]\u306E2\u3064\u306E\
    \u9802\u70B9\u3092\u7D50\u3076\u7DDA\u5206\u3092\n// \u8FBA\u3068\u3059\u308B\u591A\
    \u89D2\u5F62\u3067\u3042\u308B.\ntemplate <typename T>\nlong double polygon_area(const\
    \ vector<Point<T>> &points) {\n    int n           = (int)points.size();\n   \
    \ long double ret = 0;\n    for (int i = 0; i + 2 < n; i++)\n        ret += sgn_area(points[0],\
    \ points[i + 1], points[i + 2]);\n    return abs(ret);\n}\n\n// diameter\n// \u51F8\
    \u591A\u89D2\u5F62convex\u306E\u76F4\u5F84(\u6700\u9060\u70B9\u5BFE\u306E\u8DDD\
    \u96E2)\u3092\u6C42\u3081\u308B.\ntemplate <typename T>\nlong double diameter(const\
    \ vector<Point<T>> &convex) {\n    int n = (int)convex.size();\n    if (n == 2)\n\
    \        return dist(convex[0], convex[1]);\n\n    int i = 0, j = 0;\n    for\
    \ (int k = 0; k < n; k++) {\n        if (convex[i] < convex[k]) i = k;\n     \
    \   if (convex[j] > convex[k]) j = k;\n    }\n\n    long double ret = 0;\n   \
    \ int si = i, sj = j;\n    while (i != sj || j != si) {\n        ret = max(ret,\
    \ dist(convex[i], convex[j]));\n        if (sgn(cross(convex[(i + 1) % n] - convex[i],\
    \ convex[(j + 1) % n] - convex[j])) < 0)\n            i = (i + 1) % n;\n     \
    \   else\n            j = (j + 1) % n;\n    }\n    return ret;\n}\n#line 6 \"\
    test/polygon_area.test.cpp\"\n\nusing P = Point<int>;\n\nint main() {\n    cout\
    \ << fixed << setprecision(1);\n\n    int n;\n    cin >> n;\n    vector<P> points(n);\n\
    \    for (int i = 0; i < n; i++)\n        cin >> points[i];\n    cout << polygon_area(points)\
    \ << '\\n';\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A\"\
    \n#include \"../math/polygon.cpp\"\n\nusing P = Point<int>;\n\nint main() {\n\
    \    cout << fixed << setprecision(1);\n\n    int n;\n    cin >> n;\n    vector<P>\
    \ points(n);\n    for (int i = 0; i < n; i++)\n        cin >> points[i];\n   \
    \ cout << polygon_area(points) << '\\n';\n\n    return 0;\n}"
  dependsOn:
  - math/polygon.cpp
  - math/point.cpp
  isVerificationFile: true
  path: test/polygon_area.test.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/polygon_area.test.cpp
layout: document
redirect_from:
- /verify/test/polygon_area.test.cpp
- /verify/test/polygon_area.test.cpp.html
title: test/polygon_area.test.cpp
---
