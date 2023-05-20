---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/factorization.test.cpp
    title: test/factorization.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/factorization2.test.cpp
    title: test/factorization2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/gcd.test.cpp
    title: test/gcd.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prime.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// is_prime\n// \u6574\u6570n\u304C\u7D20\u6570\u304B\u3069\u3046\u304B\
    \u5224\u5B9A\u3059\u308B.\n// \u5236\u7D04: n >= 1,\n// \u8A08\u7B97\u91CF: O(\u221A\
    n)\ntemplate <typename T>\nbool is_prime(T n) {\n    for (T i = 2; i * i <= n;\
    \ i++) {\n        if (n % i == 0) return false;\n    }\n    return n != 1;\n}\n\
    \n// divisor\n// \u6574\u6570n\u306E\u56E0\u6570\u3092\u5217\u6319\u3059\u308B\
    .\n// \u5236\u7D04: n >= 1\n// \u8A08\u7B97\u91CF: O(\u221Anlogn)\ntemplate <typename\
    \ T>\nvector<T> divisor(T n) {\n    vector<T> ans;\n    for (int i = 1; i * i\
    \ <= n; i++) {\n        if (n % i == 0) {\n            ans.push_back(i);\n   \
    \         if (i != n / i) ans.push_back(n / i);\n        }\n    }\n    sort(ans.begin(),\
    \ ans.end());\n    return ans;\n}\n\n// prime_factor\n// \u6574\u6570n\u3092\u7D20\
    \u56E0\u6570\u5206\u89E3\u3057\u305F\u7D50\u679C\u3092\u8FD4\u3059.\n// \u5236\
    \u7D04: n >= 1\n// \u8A08\u7B97\u91CF: O(\u221An)\ntemplate <typename T>\nvector<pair<T,\
    \ int>> prime_factor(T n) {\n    vector<pair<T, int>> ans;\n    for (T i = 2;\
    \ i * i <= n; i++) {\n        int cnt = 0;\n        while (n % i == 0) {\n   \
    \         cnt++;\n            n /= i;\n        }\n        if (cnt > 0) ans.emplace_back(i,\
    \ cnt);\n    }\n    if (n != 1) ans.emplace_back(n, 1);\n    return ans;\n}\n\n\
    // Eratosthenes\n// n\u4EE5\u4E0B\u306E\u6574\u6570\u304C\u7D20\u6570\u304B\u3069\
    \u3046\u304B\u5224\u5B9A\u3059\u308B\n// \u5236\u7D04: n >= 1\nstruct Eratosthenes\
    \ {\n\n  private:\n    int n;\n    vector<int> is_primes, primes;\n\n  public:\n\
    \    Eratosthenes(int n) : n(n) {\n        is_primes.assign(n + 1, 1);\n    }\n\
    \n    // build\n    // n\u4EE5\u4E0B\u306E\u7D20\u6570\u3092\u5168\u3066\u8FD4\
    \u3059\n    // \u8A08\u7B97\u91CF: O(nloglogn)\n    vector<int> build() {\n  \
    \      is_primes[0] = is_primes[1] = 0;\n        for (long long i = 2; i <= n;\
    \ i++) {\n            if (!is_primes[i]) continue;\n            primes.push_back(i);\n\
    \            for (long long j = i * i; j <= n; j += i) {\n                is_primes[j]\
    \ = 0;\n            }\n        }\n        return primes;\n    }\n\n    // is_prime\n\
    \    // \u6574\u6570p\u304C\u7D20\u6570\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\
    \u308B\n    // \u5236\u7D04: 1 <= p <= n\n    bool is_prime(int p) {\n       \
    \ return is_primes[p];\n    }\n\n    // factorize\n    // \u6574\u6570m\u3092\u7D20\
    \u56E0\u6570\u5206\u89E3\u3059\u308B\n    // \u5236\u7D04: 1 <= m <= n*n\n   \
    \ // \u8A08\u7B97\u91CF: O(min{n,\u221Am})\n    template <typename T>\n    vector<pair<T,\
    \ int>> factorize(T m) {\n        vector<pair<T, int>> ans;\n        for (const\
    \ int &p : primes) {\n            if (p > m) break;\n            int count = 0;\n\
    \            while (m % p == 0) {\n                count++;\n                m\
    \ /= p;\n            }\n            if (count > 0) ans.emplace_back(p, count);\n\
    \        }\n        if (m != 1) ans.emplace_back(m, 1);\n        return ans;\n\
    \    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// is_prime\n\
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
    \      if (m != 1) ans.emplace_back(m, 1);\n        return ans;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/prime.cpp
  requiredBy: []
  timestamp: '2023-05-20 22:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/gcd.test.cpp
  - test/factorization2.test.cpp
  - test/factorization.test.cpp
documentation_of: math/prime.cpp
layout: document
redirect_from:
- /library/math/prime.cpp
- /library/math/prime.cpp.html
title: math/prime.cpp
---