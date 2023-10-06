---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/euclid.cpp
    title: math/euclid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"test/ext_gcd.test.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n#line 3 \"math/euclid.cpp\"\nusing namespace std;\n\n// gcd\n// \u975E\u8CA0\
    \u6574\u6570a,b\u306E\u6700\u5927\u516C\u7D04\u6570\u3092\u6C42\u3081\u308B.\n\
    // \u5236\u7D04: a,b >= 0\n// \u8A08\u7B97\u91CF: O(logmax(a,b))\ntemplate <typename\
    \ T>\nT gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }\n\n// lcm\n// \u975E\
    \u8CA0\u6574\u6570a,b\u306E\u6700\u5C0F\u516C\u500D\u6570\u3092\u6C42\u3081\u308B\
    .\n// \u5236\u7D04: a,b >= 0\n// \u8A08\u7B97\u91CF: O(logmax(a,b))\ntemplate\
    \ <typename T>\nT lcm(T a, T b) { return a / gcd(a, b) * b; }\n\n// ext_gcd\n\
    // \u62E1\u5F35Euclid\u306E\u4E92\u9664\u6CD5\u3067\u975E\u8CA0\u6574\u6570a,b\u306B\
    \u5BFE\u3057\u3066ax + by = gcd(a,b)\u3092\u6E80\u305F\u3059\u6574\u6570x,y\u3092\
    \u6C42\u3081\u308B.\n// \u51FA\u529B\u3055\u308C\u308B\u5024\u306F xy != 0 \u306A\
    \u3089\u3070 |x| <= b,|y| <= a \u3092\u6E80\u305F\u3059.\n// \u5236\u7D04: a,b\
    \ >= 0\n// \u8A08\u7B97\u91CF: O(logmax(a,b))\ntemplate <typename T>\npair<T,\
    \ T> ext_gcd(T a, T b) {\n    if (b == 0) {\n        return make_pair(1, 0);\n\
    \    }\n    auto [x, y] = ext_gcd(b, a % b);\n    return make_pair(y, x - a /\
    \ b * y);\n}\n#line 6 \"test/ext_gcd.test.cpp\"\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(20);\n\n\
    \    int a, b;\n    cin >> a >> b;\n    auto [x, y] = ext_gcd(a, b);\n    cout\
    \ << x << ' ' << y << '\\n';\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n#include \"../math/euclid.cpp\"\n\nint main() {\n    cin.tie(nullptr);\n   \
    \ ios::sync_with_stdio(false);\n    cout << fixed << setprecision(20);\n\n   \
    \ int a, b;\n    cin >> a >> b;\n    auto [x, y] = ext_gcd(a, b);\n    cout <<\
    \ x << ' ' << y << '\\n';\n    return 0;\n}"
  dependsOn:
  - math/euclid.cpp
  isVerificationFile: true
  path: test/ext_gcd.test.cpp
  requiredBy: []
  timestamp: '2022-08-30 16:11:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ext_gcd.test.cpp
layout: document
redirect_from:
- /verify/test/ext_gcd.test.cpp
- /verify/test/ext_gcd.test.cpp.html
title: test/ext_gcd.test.cpp
---
