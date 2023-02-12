#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://yukicoder.me/problems/no/409"
#include "../data_structures/convex_hull_trick.cpp"
#include "../template/const.hpp"

using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    ll a, b, w;
    cin >> n >> a >> b >> w;
    vector<ll> D(n);
    for (int i = 0; i < n; i++)
        cin >> D[i];

    vector<ll> dp(n + 1, 0);
    ConvexHullTrickMonotone<ll, true> cht;

    cht.add_left(0, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = cht.query(i).first + (ll)i * (i - 1) / 2 * b - (i - 1) * a + D[i - 1];
        cht.add_left(-i * b, dp[i] + i * a + (ll)i * (i + 1) * b / 2);
    }

    ll ans = HINF;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, w + dp[i] - (ll)(n - i) * a + (ll)(n - i) * (n - i + 1) / 2 * b);
    }
    cout << ans << '\n';
    return 0;
}