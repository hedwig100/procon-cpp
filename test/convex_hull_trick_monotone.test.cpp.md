---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structures/convex_hull_trick.cpp
    title: data_structures/convex_hull_trick.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/409
    links:
    - https://yukicoder.me/problems/no/409
  bundledCode: "#line 1 \"test/convex_hull_trick_monotone.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://yukicoder.me/problems/no/409\"\
    \n#line 3 \"data_structures/convex_hull_trick.cpp\"\nusing namespace std;\n\n\
    // \u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\u306ELine\u3068\u540D\u524D\u304C\
    \u88AB\u308B\u6050\u308C\u304C\u3042\u308B\u306E\u3067namespace\u3092\u4F7F\u3046\
    .\nnamespace _cht {\n\n// Line\n// \u76F4\u7DDA\u3092\u7BA1\u7406\u3059\u308B\u69CB\
    \u9020\u4F53\ntemplate <typename T>\nstruct Line {\n    T a, b;\n    Line(T a\
    \ = 0, T b = 0) : a(a), b(b) {}\n    T f(T x) {\n        return a * x + b;\n \
    \   }\n    bool operator<(const Line<T> &rhs) const {\n        if (a == rhs.a)\
    \ return (b < rhs.b);\n        return (a < rhs.a);\n    }\n\n    // necessary\n\
    \    // l1 <= *this <= l2\u3067\u3042\u308A, l1,l2\u304C\u76F4\u7DDA\u96C6\u5408\
    \u306B\u3042\u308B\u3068\u304D\u306B\u81EA\u5206\u304C\u5FC5\u8981\u304B\u3069\
    \u3046\u304B\u5224\u5B9A\u3059\u308B\u95A2\u6570.\n    bool neccesary(const Line<T>\
    \ &l1, const Line<T> &l2) const {\n        if (l1.a == a) return false;\n    \
    \    if (l2.a == a) return true;\n        return (l2.a - a) * (b - l1.b) < (a\
    \ - l1.a) * (l2.b - b);\n    }\n};\n\n// ConvexHullTrickMonotone\n// \u8FFD\u52A0\
    \u3059\u308B\u76F4\u7DDA\u306E\u50BE\u304D\u306B\u5358\u8ABF\u6027\u304C\u3042\
    \u308B\u5834\u5408\u306EConvexHullTrick\ntemplate <typename T, bool MIN = true>\n\
    struct ConvexHullTrickMonotone {\n    int n;\n    T sgn = MIN ? T(1) : T(-1);\n\
    \    deque<Line<T>> lines;\n\n    ConvexHullTrickMonotone() : n(0) {\n       \
    \ lines.resize(0);\n    }\n\n    // add_right\n    // y = ax + b\u306A\u308B\u76F4\
    \u7DDA\u3092\u8FFD\u52A0\u3059\u308B.\n    // \u4EFB\u610F\u306E l \\in lines\u306B\
    \u5BFE\u3057\u3066 l.a <= a \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B.\n\
    \    // \u8A08\u7B97\u91CF: \u511F\u5374 O(1)\n    void add_right(T a, T b) {\n\
    \        if (MIN) return _add_right(a, b);\n        return _add_left(a, b);\n\
    \    }\n\n    // add_left\n    // y = ax + b\u306A\u308B\u76F4\u7DDA\u3092\u8FFD\
    \u52A0\u3059\u308B.\n    // \u4EFB\u610F\u306E l \\in lines\u306B\u5BFE\u3057\u3066\
    \ a <= l.a \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B.\n    // \u8A08\u7B97\
    \u91CF: \u511F\u5374 O(1)\n    void add_left(T a, T b) {\n        if (MIN) return\
    \ _add_left(a, b);\n        return _add_right(a, b);\n    }\n\n    // query\n\
    \    // min_{i=1,\\dots,n} a_i x + b_i \u3092\u6C42\u3081\u308B.\n    // \u8A08\
    \u7B97\u91CF: O(logn)\n    // \u5236\u7D04: n > 0,\u3059\u306A\u308F\u3061\u5C11\
    \u306A\u304F\u3068\u3082\u4E00\u3064\u76F4\u7DDA\u304C\u5165\u3063\u3066\u3044\
    \u308B.\n    pair<T, Line<T>> query(T x) {\n        assert(n > 0);\n        int\
    \ l = 0, r = n;\n        while (r - l > 1) {\n            int m = (r + l) / 2;\n\
    \            if (lines[m - 1].f(x) >= lines[m].f(x))\n                l = m;\n\
    \            else\n                r = m;\n        }\n        Line<T> ab(sgn *\
    \ lines[l].a, sgn * lines[l].b);\n        return make_pair(sgn * lines[l].f(x),\
    \ ab);\n    }\n\n    friend ostream &operator<<(ostream &os, const ConvexHullTrickMonotone<T,\
    \ MIN> &cht) noexcept {\n        for (int i = 0; i < cht.n; i++) {\n         \
    \   os << \"l(\" << cht.lines[i].a << ',' << cht.lines[i].b << \"),\";\n     \
    \   }\n        return os;\n    }\n\n  private:\n    // _add_right\n    // y =\
    \ ax + b\u306A\u308B\u76F4\u7DDA\u3092\u8FFD\u52A0\u3059\u308B.\n    // MIN =\
    \ true\u306E\u5834\u5408: \u4EFB\u610F\u306E l \\in lines\u306B\u5BFE\u3057\u3066\
    \ l.a <= a \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B.\n    // MIN = false\u306E\
    \u5834\u5408: \u4EFB\u610F\u306E l \\in lines\u306B\u5BFE\u3057\u3066 a <= l.a\
    \ \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B.\n    // \u8A08\u7B97\u91CF\
    : \u511F\u5374 O(1)\n    void _add_right(T a, T b) {\n        Line<T> l(sgn *\
    \ a, sgn * b);\n\n        if (n <= 1) {\n            lines.push_back(l);\n   \
    \         n++;\n            return;\n        }\n\n        // l\u306F\u4E0D\u5FC5\
    \u8981\n        if (l.a == lines.back().a && l.b >= lines.back().b)\n        \
    \    return;\n\n        while (n > 1 && !lines.back().neccesary(lines[n - 2],\
    \ l)) {\n            lines.pop_back();\n            n--;\n        }\n\n      \
    \  lines.push_back(l);\n        n++;\n        return;\n    }\n\n    // _add_left\n\
    \    // y = ax + b\u306A\u308B\u76F4\u7DDA\u3092\u8FFD\u52A0\u3059\u308B.\n  \
    \  // MIN = true \u306E\u5834\u5408: \u4EFB\u610F\u306E l \\in lines\u306B\u5BFE\
    \u3057\u3066 a <= l.a \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B.\n    //\
    \ MIN = false \u306E\u5834\u5408: \u4EFB\u610F\u306E l \\in lines\u306B\u5BFE\u3057\
    \u3066 l.a <= a \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B.\n    // \u8A08\
    \u7B97\u91CF: \u511F\u5374 O(1)\n    void _add_left(T a, T b) {\n        Line<T>\
    \ l(sgn * a, sgn * b);\n\n        if (n <= 1) {\n            lines.push_front(l);\n\
    \            n++;\n            return;\n        }\n\n        // l\u306F\u4E0D\u5FC5\
    \u8981\n        if (l.a == lines.front().a && l.b >= lines.front().b)\n      \
    \      return;\n\n        while (n > 1 && !lines.front().neccesary(l, lines[1]))\
    \ {\n            lines.pop_front();\n            n--;\n        }\n\n        lines.push_front(l);\n\
    \        n++;\n        return;\n    }\n};\n\n} // namespace _cht\n\nusing namespace\
    \ _cht;\n#line 2 \"template/const.hpp\"\nconstexpr int INF        = 1000'000'000;\n\
    constexpr long long HINF = 4000'000'000'000'000'000;\nconstexpr long long MOD\
    \  = 998244353;\nconstexpr double EPS     = 1e-6;\nconstexpr double PI      =\
    \ 3.14159265358979;\n#line 7 \"test/convex_hull_trick_monotone.test.cpp\"\n\n\
    using ll = long long;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n\n    int n;\n    ll a, b, w;\n    cin\
    \ >> n >> a >> b >> w;\n    vector<ll> D(n);\n    for (int i = 0; i < n; i++)\n\
    \        cin >> D[i];\n\n    vector<ll> dp(n + 1, 0);\n    ConvexHullTrickMonotone<ll,\
    \ true> cht;\n\n    cht.add_left(0, 0);\n    dp[0] = 0;\n    for (int i = 1; i\
    \ <= n; i++) {\n        dp[i] = cht.query(i).first + (ll)i * (i - 1) / 2 * b -\
    \ (i - 1) * a + D[i - 1];\n        cht.add_left(-i * b, dp[i] + i * a + (ll)i\
    \ * (i + 1) * b / 2);\n    }\n\n    ll ans = HINF;\n    for (int i = 0; i <= n;\
    \ i++) {\n        ans = min(ans, w + dp[i] - (ll)(n - i) * a + (ll)(n - i) * (n\
    \ - i + 1) / 2 * b);\n    }\n    cout << ans << '\\n';\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://yukicoder.me/problems/no/409\"\
    \n#include \"../data_structures/convex_hull_trick.cpp\"\n#include \"../template/const.hpp\"\
    \n\nusing ll = long long;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n\n    int n;\n    ll a, b, w;\n    cin\
    \ >> n >> a >> b >> w;\n    vector<ll> D(n);\n    for (int i = 0; i < n; i++)\n\
    \        cin >> D[i];\n\n    vector<ll> dp(n + 1, 0);\n    ConvexHullTrickMonotone<ll,\
    \ true> cht;\n\n    cht.add_left(0, 0);\n    dp[0] = 0;\n    for (int i = 1; i\
    \ <= n; i++) {\n        dp[i] = cht.query(i).first + (ll)i * (i - 1) / 2 * b -\
    \ (i - 1) * a + D[i - 1];\n        cht.add_left(-i * b, dp[i] + i * a + (ll)i\
    \ * (i + 1) * b / 2);\n    }\n\n    ll ans = HINF;\n    for (int i = 0; i <= n;\
    \ i++) {\n        ans = min(ans, w + dp[i] - (ll)(n - i) * a + (ll)(n - i) * (n\
    \ - i + 1) / 2 * b);\n    }\n    cout << ans << '\\n';\n    return 0;\n}"
  dependsOn:
  - data_structures/convex_hull_trick.cpp
  isVerificationFile: true
  path: test/convex_hull_trick_monotone.test.cpp
  requiredBy: []
  timestamp: '2023-02-12 13:47:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convex_hull_trick_monotone.test.cpp
layout: document
redirect_from:
- /verify/test/convex_hull_trick_monotone.test.cpp
- /verify/test/convex_hull_trick_monotone.test.cpp.html
title: test/convex_hull_trick_monotone.test.cpp
---
