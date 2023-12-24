#pragma once
#include <bits/stdc++.h>
using namespace std;

const int dy[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dx[8] = {0, 1, 0, -1, -1, 1, -1, 1};
bool IN(int y, int x, int H, int W) {
    return (0 <= y) && (y < H) && (0 <= x) && (x < W);
}