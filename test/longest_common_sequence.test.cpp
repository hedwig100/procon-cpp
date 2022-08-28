#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=jp"
#include "../dynamic_programming/longest_common_sequence.cpp"

int main() {
    int q;
    cin >> q;
    string s, t;
    while (q--) {
        cin >> s >> t;
        LongestCommonSequence lcs(s, t);
        cout << lcs.solve() << '\n';
    }
    return 0;
}