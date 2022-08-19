#pragma once
#include <bits/stdc++.h>
using namespace std;

// Z-algorithum
// l=(文字列Sの長さ)としてi=0,..,l-1に対して
// Z[i] = (SとS[i:l)の最長共通接頭辞の長さ)
// なる配列Aを返す。
// complexity : O(|S|)
vector<int> Z_algorithm(string s) {
    int l = (int)s.size();
    vector<int> Z(l);
    Z[0]  = l;
    int i = 1, j = 0;
    while (i < l) {
        while (i + j < l && s[j] == s[i + j])
            j++;
        Z[i] = j;

        if (j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while (k < j && k + Z[k] < j) {
            Z[i + k] = Z[k];
            k++;
        }
        i += k;
        j -= k;
    }

    return Z;
}