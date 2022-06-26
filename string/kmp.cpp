#include <bits/stdc++.h>
using namespace std;

// KMP S[:i]の接頭辞と接尾辞が何文字一致するか　O(|S|)
vector<int> KMP(string s) {
    int l = s.size();
    vector<int> mp(l + 1, -1);
    int j = -1;
    for (int i = 0; i < l; i++) {
        while (j >= 0 && s[i] != s[j])
            j = mp[j];
        j++;
        if (s[i + 1] == s[j])
            mp[i + 1] = mp[j];
        else
            mp[i + 1] = j;
    }
}