#pragma once
#include <bits/stdc++.h>
using namespace std;

// Gridの(i,j)なるインデックスを1次元のインデックスに直す

template <typename T> struct IndexGenerator {
    T H, W;
    IndexGenerator(T H, T W) : H(H), W(W) {}
    T N() { return H * W; }
    T operator()(T i, T j) { return i * W + j; }
};