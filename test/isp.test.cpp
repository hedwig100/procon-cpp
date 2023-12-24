#include <bits/stdc++.h>
using namespace std;

#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C"
#define ERROR 1e-9
#include "../math/point.cpp"

using P = Point<long double>;

int main() {
    cout << fixed << setprecision(20);

    P p0, p1;
    cin >> p0 >> p1;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        P p2;
        cin >> p2;
        if (p0 == p2 || p1 == p2) {
            cout << "ON_SEGMENT\n";
            continue;
        }
        switch (iSP(p1, p0, p2)) {
        case 1:
            cout << "CLOCKWISE\n";
            break;
        case -1:
            cout << "COUNTER_CLOCKWISE\n";
            break;
        case 2:
            cout << "ONLINE_BACK\n";
            break;
        case -2:
            cout << "ON_SEGMENT\n";
            break;
        case 0:
            cout << "ONLINE_FRONT\n";
            break;
        }
    }
    return 0;
}