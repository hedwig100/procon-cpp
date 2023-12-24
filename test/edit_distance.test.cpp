#include <bits/stdc++.h>
using namespace std;

#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/"                                  \
    "description.jsp?id=DPL_1_E&lang=ja"
#include "../dynamic_programming/edit_distance.cpp"

int main() {
    string s, t;
    cin >> s >> t;
    cout << edit_distance(s, t) << '\n';
    return 0;
}