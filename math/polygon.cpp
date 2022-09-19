#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "point.cpp"

// convex_hull
// 点集合pointsの凸包を求める.
// 求めた凸包は最も左にあるもののうち最も下にあるものから順に反時計回りに並んでいる.
template <typename T>
vector<Point<T>> convex_hull(vector<Point<T>> points) {
    sort(points.begin(), points.end());
    int n = (int)points.size(), k = 0;
    vector<Point<T>> convex(2 * n);
    for (int i = 0; i < n; i++) {
        while (k > 1 && iSP(convex[k - 2], convex[k - 1], points[i]) == -1)
            k--;
        convex[k++] = points[i];
    }
    for (int i = n - 2, t = k; i >= 0; i--) {
        while (k > t && iSP(convex[k - 2], convex[k - 1], points[i]) == -1)
            k--;
        convex[k++] = points[i];
    }
    convex.resize(k - 1);
    return convex;
}

// polygon_area
// pointsのn点からなる多角形Gの面積を求める.
// Gはpoints[i],points[(i + 1)%n]の2つの頂点を結ぶ線分を
// 辺とする多角形である.
template <typename T>
long double polygon_area(const vector<Point<T>> &points) {
    int n           = (int)points.size();
    long double ret = 0;
    for (int i = 0; i + 2 < n; i++)
        ret += sgn_area(points[0], points[i + 1], points[i + 2]);
    return abs(ret);
}