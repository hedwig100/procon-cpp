#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C&lang=jp"
#include "../other_algorithm/two_pointers.cpp"

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    long long x = 0;
    TwoPointers<long long, 0> tp(
        n,
        [&](long long data, int r) { return data + A[r - 1] <= x; },
        [&](long long &data, int &l) { data -= A[l]; l++; },
        [&](long long &data, int &r) { data += A[r]; r++; });
    for (int i = 0; i < q; i++) {
        cin >> x;
        tp.solve();
        cout << tp.count << '\n';
    }

    return 0;
}