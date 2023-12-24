#include <bits/stdc++.h>
using namespace std;

#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A"
#include "../math/polygon.cpp"

using P = Point<int>;

int main() {
    cout << fixed << setprecision(1);

    int n;
    cin >> n;
    vector<P> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i];
    cout << polygon_area(points) << '\n';

    return 0;
}