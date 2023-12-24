#include <bits/stdc++.h>
using namespace std;

#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C"
#define ERROR 1e-9
#include "../math/line.cpp"

using P = Point<long double>;
using L = Line<long double>;
using S = Segment<long double>;
using R = Ray<long double>;

int main() {
    cout << fixed << setprecision(20);

    int q;
    cin >> q;
    while (q--) {
        P p0, p1, p2, p3;
        cin >> p0 >> p1 >> p2 >> p3;
        S s1 = S(p0, p1), s2 = S(p2, p3);
        auto [_, p] = ss_intersection(s1, s2);
        cout << p << '\n';
    }

    return 0;
}