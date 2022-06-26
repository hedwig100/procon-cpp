#include <bits/stdc++.h>
using namespace std;

// Zalgorithum 最長共通接頭辞の長さ O(|S|)
vector<int> Z(string s) {
    int l = s.size();
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