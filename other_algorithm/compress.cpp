#include <bits/stdc++.h>
using namespace std;

map<long long, int> compress(vector<long long> A) {
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    map<long long, int> mp;
    for (int i = 0; i < (int)A.size(); i++)
        mp[A[i]] = i;
    return mp;
}