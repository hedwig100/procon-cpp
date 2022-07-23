#include <bits/stdc++.h>
using namespace std;

template <typename T>
map<T, int> compress(vector<T> A) {
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    map<T, int> mp;
    for (int i = 0; i < (int)A.size(); i++)
        mp[A[i]] = i;
    return mp;
}