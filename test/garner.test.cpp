#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://yukicoder.me/problems/no/186"
#include "../math/number_theory.cpp"

int main() {
    vector<long long> X(3), Y(3);
    for (int i = 0; i < 3; i++)
        cin >> X[i] >> Y[i];
    auto [x, m] = garner(X, Y);
    if (x == 0)
        cout << m << '\n';
    else
        cout << x << '\n';
    return 0;
}