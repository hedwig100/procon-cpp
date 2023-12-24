#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://yukicoder.me/problems/no/489"
#include "../data_structures/sliding_window_aggregation.cpp"

int main() {
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> X(n);
    for (int i = 0; i < n; i++)
        cin >> X[i];

    using SemiGrp = pair<int, int>;
    SlidingWindowAggregation<SemiGrp> swag(
        [](const SemiGrp &a, const SemiGrp &b) {
            if (a.first < b.first)
                return b;
            else
                return a;
        });

    int max_diff = 0;
    int ai = -1, bi = -1;
    for (int i = 0; i <= d; i++)
        swag.push({X[i], i});
    for (int i = 0; i < n; i++) {
        auto [x, j] = swag.fold();
        if (max_diff < x - X[i]) {
            max_diff = x - X[i];
            ai = i, bi = j;
        }
        swag.pop();
        if (i + d + 1 < n) swag.push({X[i + d + 1], i + d + 1});
    }

    if (max_diff == 0)
        cout << 0 << '\n';
    else {
        cout << (long long)k * max_diff << '\n';
        cout << ai << ' ' << bi << '\n';
    }

    return 0;
}