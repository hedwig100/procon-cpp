#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A"
#define ERROR 1e-9
#include "../math/convex_hull.cpp"
#include "../math/line.cpp"

using P = Point<int>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<P> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i];
    auto convex = convex_hull(points);

    int k   = (int)convex.size();
    P start = INFTY<int>;
    int ind = -1;
    for (int i = 0; i < k; i++) {
        if (convex[i].y < start.y || (convex[i].y == start.y && convex[i].x < start.x)) {
            start = convex[i];
            ind   = i;
        }
    }

    cout << k << '\n';
    for (int i = 0; i < k; i++)
        cout << convex[(ind + i) % k] << '\n';

    return 0;
}