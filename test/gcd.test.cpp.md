---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/euclid.cpp
    title: math/euclid.cpp
  - icon: ':heavy_check_mark:'
    path: math/prime.cpp
    title: math/prime.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0583
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0583
  bundledCode: "#line 1 \"test/gcd.test.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0583\"\
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
    \ b * y);\n}\n#line 3 \"math/prime.cpp\"\nusing namespace std;\n\n// is_prime\n\
    // \u6574\u6570n\u304C\u7D20\u6570\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B\
    .\n// \u5236\u7D04: n >= 1,\n// \u8A08\u7B97\u91CF: O(\u221An)\ntemplate <typename\
    \ T>\nbool is_prime(T n) {\n    for (T i = 2; i * i <= n; i++) {\n        if (n\
    \ % i == 0) return false;\n    }\n    return n != 1;\n}\n\n// divisor\n// \u6574\
    \u6570n\u306E\u56E0\u6570\u3092\u5217\u6319\u3059\u308B.\n// \u5236\u7D04: n >=\
    \ 1\n// \u8A08\u7B97\u91CF: O(\u221Anlogn)\ntemplate <typename T>\nvector<T> divisor(T\
    \ n) {\n    vector<T> ans;\n    for (int i = 1; i * i <= n; i++) {\n        if\
    \ (n % i == 0) {\n            ans.push_back(i);\n            if (i != n / i) ans.push_back(n\
    \ / i);\n        }\n    }\n    sort(ans.begin(), ans.end());\n    return ans;\n\
    }\n\n// prime_factor\n// \u6574\u6570n\u3092\u7D20\u56E0\u6570\u5206\u89E3\u3057\
    \u305F\u7D50\u679C\u3092\u8FD4\u3059.\n// \u5236\u7D04: n >= 1\n// \u8A08\u7B97\
    \u91CF: O(\u221An)\ntemplate <typename T>\nvector<pair<T, int>> prime_factor(T\
    \ n) {\n    vector<pair<T, int>> ans;\n    for (T i = 2; i * i <= n; i++) {\n\
    \        int cnt = 0;\n        while (n % i == 0) {\n            cnt++;\n    \
    \        n /= i;\n        }\n        if (cnt > 0) ans.emplace_back(i, cnt);\n\
    \    }\n    if (n != 1) ans.emplace_back(n, 1);\n    return ans;\n}\n\n// Eratosthenes\n\
    // n\u4EE5\u4E0B\u306E\u6574\u6570\u304C\u7D20\u6570\u304B\u3069\u3046\u304B\u5224\
    \u5B9A\u3059\u308B\n// \u5236\u7D04: n >= 1\nstruct Eratosthenes {\n\n  private:\n\
    \    int n;\n    vector<int> is_primes, primes;\n\n  public:\n    Eratosthenes(int\
    \ n) : n(n) {\n        is_primes.assign(n + 1, 1);\n    }\n\n    // build\n  \
    \  // n\u4EE5\u4E0B\u306E\u7D20\u6570\u3092\u5168\u3066\u8FD4\u3059\n    // \u8A08\
    \u7B97\u91CF: O(nloglogn)\n    vector<int> build() {\n        is_primes[0] = is_primes[1]\
    \ = 0;\n        for (long long i = 2; i <= n; i++) {\n            if (!is_primes[i])\
    \ continue;\n            primes.push_back(i);\n            for (long long j =\
    \ i * i; j <= n; j += i) {\n                is_primes[j] = 0;\n            }\n\
    \        }\n        return primes;\n    }\n\n    // is_prime\n    // \u6574\u6570\
    p\u304C\u7D20\u6570\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B\n    // \u5236\
    \u7D04: 1 <= p <= n\n    bool is_prime(int p) {\n        return is_primes[p];\n\
    \    }\n\n    // factorize\n    // \u6574\u6570m\u3092\u7D20\u56E0\u6570\u5206\
    \u89E3\u3059\u308B\n    // \u5236\u7D04: 1 <= m <= n*n\n    // \u8A08\u7B97\u91CF\
    : O(min{n,\u221Am})\n    template <typename T>\n    vector<pair<T, int>> factorize(T\
    \ m) {\n        vector<pair<T, int>> ans;\n        for (const int &p : primes)\
    \ {\n            if (p > m) break;\n            int count = 0;\n            while\
    \ (m % p == 0) {\n                count++;\n                m /= p;\n        \
    \    }\n            if (count > 0) ans.emplace_back(p, count);\n        }\n  \
    \      if (m != 1) ans.emplace_back(m, 1);\n        return ans;\n    }\n};\n#line\
    \ 7 \"test/gcd.test.cpp\"\n\nint main() {\n    int n;\n    cin >> n;\n    int\
    \ g = 0;\n    for (int i = 0; i < n; i++) {\n        int a;\n        cin >> a;\n\
    \        g = gcd(g, a);\n    }\n    auto factors = divisor(g);\n    for (const\
    \ auto &p : factors)\n        cout << p << '\\n';\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0583\"\
    \n#include \"../math/euclid.cpp\"\n#include \"../math/prime.cpp\"\n\nint main()\
    \ {\n    int n;\n    cin >> n;\n    int g = 0;\n    for (int i = 0; i < n; i++)\
    \ {\n        int a;\n        cin >> a;\n        g = gcd(g, a);\n    }\n    auto\
    \ factors = divisor(g);\n    for (const auto &p : factors)\n        cout << p\
    \ << '\\n';\n    return 0;\n}"
  dependsOn:
  - math/euclid.cpp
  - math/prime.cpp
  isVerificationFile: true
  path: test/gcd.test.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/gcd.test.cpp
layout: document
redirect_from:
- /verify/test/gcd.test.cpp
- /verify/test/gcd.test.cpp.html
title: test/gcd.test.cpp
---
