#include <bits/stdc++.h>
using namespace std;

#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B"
#define ERROR 1e-9
#include "../math/polygon.cpp"

using P = Point<long double>;

int main() {
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<P> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    long double d = diameter(convex_hull(A));
    cout << d << '\n';
    return 0;
}