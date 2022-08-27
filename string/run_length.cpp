#pragma once
#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> run_length(string s) {
    vector<pair<char, int>> ret;
    pair<char, int> now = make_pair(s[0], 1);
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == s[i - 1]) {
            now.second++;
        } else {
            ret.push_back(now);
            now = make_pair(s[i], 1);
        }
    }
    ret.push_back(now);
    return ret;
}