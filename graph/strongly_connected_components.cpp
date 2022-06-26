#include <bits/stdc++.h>
using namespace std;

struct StronglyConnectedComponents {
  private:
    std::vector<int> visited;
    std::vector<int> memo;

    void _dfs(int v) {
        group[v] = -1;
        for (const int &u : G[v]) {
            if (group[u] > 0) _dfs(u);
        }
        order.push_back(v);
    }

    void rdfs(int v, int cnt) {
        group[v] = cnt;
        scc_group[cnt].push_back(v);
        for (const int &u : rG[v]) {
            if (group[u] < 0) rdfs(u, cnt);
        }
    }

    int _dp(int v) {
        if (visited[v] >= 0) return memo[v];
        int ret = 0;
        for (const int &u : sccG[v]) {
            ret |= _dp(u);
        }
        visited[v]     = 1;
        return memo[v] = ret;
    }

  public:
    int N, N_scc;
    std::vector<std::vector<int>> G, rG;
    std::vector<int> group, order;
    std::vector<std::vector<int>> scc_group, sccG;

    // StronglyConnectedComponents receives N as the number of vertex of graph G.
    StronglyConnectedComponents(int N) : N(N) {
        G.resize(N);
        rG.resize(N);
        group.assign(N, 1);
    }

    // add_edge receives a,b and creates edge a -> b.
    // contraint: 0 <= a,b < N
    void add_edge(int a, int b) {
        G[a].push_back(b);
        rG[b].push_back(a);
    }

    // build bulids strongly connected components.
    // when build_scc is true, build scc_G
    void build(bool build_scc) {
        for (int i = 0; i < N; i++) {
            if (group[i] > 0) _dfs(i);
        }
        std::reverse(order.begin(), order.end());
        N_scc = 0;
        for (const int &v : order) {
            if (group[v] < 0) {
                scc_group.push_back({});
                rdfs(v, N_scc);
                N_scc++;
            }
        }

        if (!build_scc)
            return;

        sccG.resize(N_scc);
        for (int i = 0; i < N_scc; i++) {
            std::set<int> st;
            for (const int &v : scc_group[i]) {
                for (const int &u : G[v]) {
                    st.insert(group[u]);
                }
            }
            for (auto itr = st.begin(); itr != st.end(); itr++) {
                sccG[i].push_back(*itr);
            }
        }
    }

    // DP MUST BE IMPLEMENTED DEPENDING ON THE PROBLEM TO BE SOLVED.
    // build must be called before dp is called.
    int dp() {
        visited.assign(N_scc, -1);
        memo.resize(N_scc, 0);
        for (int i = 0; i < N_scc; i++) {
            if ((int)scc_group[i].size() > 1) {
                memo[i]    = 1;
                visited[i] = 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < N_scc; i++) {
            if (_dp(i)) ans += (int)scc_group[i].size();
        }
        return ans;
    }

    // scc[i] returns a group which vertex i belongs to.
    // this function is valid after build () is called.
    int operator[](int i) {
        return group[i];
    }
};

// https://atcoder.jp/contests/abc245/tasks/abc245_f

int abc245_f() {
    int N, M;
    std::cin >> N >> M;
    StronglyConnectedComponents scc(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        scc.add_edge(u, v);
    }
    scc.build(true);
    std::cout << scc.dp() << '\n';
    return 0;
}

int main() {
    abc245_f();
    return 0;
}