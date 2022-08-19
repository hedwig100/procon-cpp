#pragma once
#include <bits/stdc++.h>
using namespace std;

// MP
// l=(文字列Sの長さ)としてi=1,...,l+1について
// A[i] = (S[0:i)の接尾辞と接頭辞であって一致するようなものの最大の長さ, ただしS[0:i)全体は自明に一致するので除く)
// なる配列を返す。A[0]は常に-1
// complexity: O(|S|)
vector<int> MP(string s) {
    int l = (int)s.size();
    vector<int> A(l + 1, -1);
    int j = -1;
    for (int i = 0; i < l; i++) {
        while (j >= 0 && s[i] != s[j])
            j = A[j];
        j++;
        A[i + 1] = j;
    }
    return A;
}