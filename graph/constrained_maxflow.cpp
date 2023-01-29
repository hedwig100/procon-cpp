#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "dinic.cpp"

// ConstrainedMaxFlow
// 最小流量制約付き最大流問題をとく.
template <typename T, const T INF>
struct ConstrainedMaxFlow {
    int n, super_s, super_t;
    T max_flow_from_super_s;
    Dinic<T, INF> flow_solver;

    ConstrainedMaxFlow(int n) : n(n), super_s(n), super_t(n + 1), max_flow_from_super_s(0) {
        flow_solver.resize(n + 2);
    }

    // add_edge
    // 頂点aから頂点bへと容量capで最小流量がmin_flowの辺を張る
    // 制約: 0 <= a,b < n,0 <= min_flow <= cap
    void add_edge(int a, int b, T cap, T min_flow = 0) {
        if (min_flow == 0) {
            flow_solver.add_edge(a, b, cap);
            return;
        }
        flow_solver.add_edge(a, b, cap - min_flow);
        flow_solver.add_edge(a, super_t, min_flow);
        flow_solver.add_edge(super_s, b, min_flow);
        max_flow_from_super_s += min_flow;
    }

    // solve
    // 頂点sから頂点tへの最小流量制約付き最大フローを求める.
    // もし流量制約を満たすフローが存在しない場合は false,0 を返す.
    // 　　　　　　　　　　　　　　存在する場合は true,flow を返す.
    // 制約: 0 <= s,t < n
    // 計算量: O(|V|^2|E|)
    pair<bool, T> solve(int s, int t) {
        T a = flow_solver.solve(super_s, super_t);
        T b = flow_solver.solve(super_s, t);
        T c = flow_solver.solve(s, super_t);
        T d = flow_solver.solve(s, t);

        bool does_exist = ((a + b == max_flow_from_super_s) && (b == c));
        return make_pair(does_exist, does_exist ? c + d : T(0));
    }
};