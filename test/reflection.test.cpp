#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_B"
#define ERROR 1e-9
#include "../math/line.cpp"

using P = Point<long double>;
using L = Line<long double>;

int main() {
    cout << fixed << setprecision(20);

    P p1, p2;
    cin >> p1 >> p2;
    L l = Line(p1, p2);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        P p;
        cin >> p;
        cout << reflection(p, l) << '\n';
    }
    return 0;
}