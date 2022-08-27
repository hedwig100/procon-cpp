// TODO: atcoderの問題でverifyできるようにする
// #include <bits/stdc++.h>
// using namespace std;

// #define PROBLEM "https://atcoder.jp/contests/abc054/tasks/abc054_c"
// #include "../other_algorithm/perm_search.cpp"

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> G(n, vector<int>(n, 0));
//     for (int i = 0; i < m; i++) {
//         int a, b;
//         cin >> a >> b;
//         --a;
//         --b;
//         G[a][b] = 1;
//         G[b][a] = 1;
//     }

//     int ans = 0;
//     auto f  = [&](vector<int> &A) {
//         if (A[0] != 0) return;
//         for (int i = 0; i < n - 1; i++) {
//             if (G[A[i]][A[i + 1]] != 1) return;
//         }
//         ans++;
//     };

//     PermSearch ps(n, f);
//     ps.solve();
//     cout << ans << '\n';
//     return 0;
// }